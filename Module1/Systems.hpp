#pragma once

#include <entt/entt.hpp>

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
