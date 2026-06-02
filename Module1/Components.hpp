#ifndef Components_hpp
#define Components_hpp
#pragma once

#include <memory>
#include <glm/glm.hpp>

namespace eeng 
{
	class RenderableMesh;
}

struct TransformComponent
{
	glm::vec3 position{ 0.f };
	glm::vec3 scale{ 1.f };
	float rotationY{ 0.f };
};

struct LinearVelocityComponent
{
	glm::vec3 velocity{ 0.f };
};

struct MeshComponent
{
	std::shared_ptr<eeng::RenderableMesh> mesh;
};

struct PlayerControllerComponent
{
	float moveSpeed{ 5.0f };
};
#endif