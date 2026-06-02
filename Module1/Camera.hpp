#pragma once

#include <glm/glm.hpp>

struct Camera 
{
	glm::vec3 pos{ 0.0f };
	glm::vec3 lookAt{ 0.0f };
	glm::vec3 up{ 0.0f, 1.0f, 0.0f };

	float yaw{ 0.0f };
	float pitch{ 0.0f };
	float distance{ 10.0f };
	float sensitivity{ 0.01f };

	float nearPlane{ 0.1f };
	float farPlane{ 1000.0f };

	glm::ivec2 mouse_xy_prev{ -1, -1 };
};