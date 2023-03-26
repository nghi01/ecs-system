#include "Coordinator.hpp"
#include "Components.hpp"
#include "type.hpp"
#include "vec3.hpp"
#include "PhysicsSystem.hpp"
#include <vector>
#include <chrono>
#include <random>
#include <iostream>

Coordinator gCoordinator;

static bool quit = false;

int main()
{
	gCoordinator.Init();

	gCoordinator.RegisterComponent<Gravity>();
	gCoordinator.RegisterComponent<RigidBody>();
	gCoordinator.RegisterComponent<Transform>();

	auto physicsSystem = gCoordinator.RegisterSystem<PhysicsSystem>();

	Signature signature;
	signature.set(gCoordinator.GetComponentType<Gravity>());
	signature.set(gCoordinator.GetComponentType<RigidBody>());
	signature.set(gCoordinator.GetComponentType<Transform>());
	gCoordinator.SetSystemSignature<PhysicsSystem>(signature);

	std::vector<Entity> entities(MAX_ENTITIES);

	std::default_random_engine generator;
	std::uniform_real_distribution<float> randPosition(-100.0f, 100.0f);
	std::uniform_real_distribution<float> randRotation(0.0f, 3.0f);
	std::uniform_real_distribution<float> randScale(3.0f, 5.0f);
	std::uniform_real_distribution<float> randGravity(-10.0f, -1.0f);

	float scale = randScale(generator);

	for (auto& entity : entities)
	{
		entity = gCoordinator.CreateEntity();

		gCoordinator.AddComponent(
			entity,
			Gravity{Vec3(0.0f, randGravity(generator), 0.0f)});

		gCoordinator.AddComponent(
			entity,
			RigidBody{
				.velocity = Vec3(0.0f, 0.0f, 0.0f),
				.acceleration = Vec3(0.0f, 0.0f, 0.0f)
			});

		gCoordinator.AddComponent(
			entity,
			Transform{
				.position = Vec3(randPosition(generator), randPosition(generator), randPosition(generator)),
				.rotation = Vec3(randRotation(generator), randRotation(generator), randRotation(generator)),
				.scale = Vec3(scale, scale, scale)
			});
	}

	float dt = 0.0f;

	while (!quit)
	{
		auto startTime = std::chrono::high_resolution_clock::now();

		physicsSystem->Update(dt);

		auto stopTime = std::chrono::high_resolution_clock::now();

		dt = std::chrono::duration<float, std::chrono::seconds::period>(stopTime - startTime).count();
		std::cout << "I'm running.";
	}
}