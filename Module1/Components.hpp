#ifndef Components_hpp
#define Components_hpp
#pragma once

#include <memory>
#include <glm/glm.hpp>
#include <vector>

namespace eeng 
{
	class RenderableMesh;
}

struct TransformComponent
{
	glm::vec3 position{ 0.f };
	glm::vec3 scale{ 1.f };
	float rotationY{ 0.f };//radians
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

struct NPCControllerComponent
{
	float moveSpeed{ 5.0f };

	std::vector<glm::vec3> waypoints;

	int currentWaypoint = 0;
};

struct CameraComponent
{
	float distance{ 10.0f };
	float height{ 2.0f };
	float sensitivity{ 0.01f };

	glm::ivec2 mouse_xy_prev{ -1, -1 };
};
#endif