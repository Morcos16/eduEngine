#include "Systems.hpp"
#include "Components.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "ForwardRenderer.hpp"

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