#include "Systems.hpp"
#include "Components.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "ForwardRenderer.hpp"
#include "InputManager.hpp"
#include "glmcommon.hpp"

void MovementSystem::update(entt::registry& registry, float dt) 
{
    auto view = registry.view<TransformComponent, LinearVelocityComponent>();

    for (auto entity : view)
    {
        auto& transform = view.get<TransformComponent>(entity);
        auto& velocity = view.get<LinearVelocityComponent>(entity);

        transform.position += velocity.velocity * dt;
    }
}

void RenderSystem::render(entt::registry& registry, eeng::ForwardRenderer* forwardRenderer) 
{
    auto view = registry.view<TransformComponent, MeshComponent>();

    for (auto entity : view)
    {
        auto& transform = view.get<TransformComponent>(entity);
        auto& mesh = view.get<MeshComponent>(entity);

        glm::mat4 worldMatrix{ 1.0f };
        worldMatrix = glm::translate(worldMatrix, transform.position);
        worldMatrix = glm::rotate(worldMatrix, transform.rotationY, glm::vec3(0, 1, 0));
        worldMatrix = glm::scale(worldMatrix, transform.scale);

        forwardRenderer->renderMesh(mesh.mesh, worldMatrix);
    }
}

void PlayerControllerSystem::update(entt::registry& registry, float dt, InputManagerPtr input, float cameraYaw)
{
    using Key = eeng::InputManager::Key;
    bool W = input->IsKeyPressed(Key::W);
    bool A = input->IsKeyPressed(Key::A);
    bool S = input->IsKeyPressed(Key::S);
    bool D = input->IsKeyPressed(Key::D);

    auto view = registry.view <
        TransformComponent,
        LinearVelocityComponent,
        PlayerControllerComponent>();
    
    for (auto entity : view) 
    {
        auto& velocity = view.get<LinearVelocityComponent>(entity);
        auto& controller = view.get<PlayerControllerComponent>(entity);

        glm::vec3 fwd = glm::vec3(glm_aux::R(cameraYaw, glm_aux::vec3_010) * glm::vec4(0, 0, -1, 0));
        glm::vec3 right = glm::cross(fwd, glm_aux::vec3_010);

        glm::vec3 movementDirection{ 0.0f };

        movementDirection += fwd * ((W ? 1.0f : 0.0f) + (S ? -1.0f : 0.0f));
        movementDirection += right * ((A ? -1.0f : 0.0f) + (D ? 1.0f : 0.0f));

        if (glm::length(movementDirection) > 0.0f) {
            movementDirection = glm::normalize(movementDirection);
        }

        velocity.velocity = movementDirection * controller.moveSpeed;
    }
}