#pragma once

#include <entt/entt.hpp>
#include "InputManager.hpp"

namespace eeng 
{
	class ForwardRenderer;
}

class MovementSystem 
{
public:
	void update(entt::registry& registry, float dt);
};

class RenderSystem 
{
public: 
	void render(entt::registry& registry, eeng::ForwardRenderer* forwardrenderer);
};

class PlayerControllerSystem
{
public:
	void update(entt::registry& registry, float dt, InputManagerPtr input, float cameraYaw);
};
