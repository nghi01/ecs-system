#pragma once

#include "vec3.hpp"


struct Transform
{
	Vec3 position;
	Vec3 rotation;
	Vec3 scale;
};

struct Gravity
{
	Vec3 force;
};

struct RigidBody
{
	Vec3 velocity;
	Vec3 acceleration;
};