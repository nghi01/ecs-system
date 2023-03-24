#include "Components.hpp"
#include "Coordinator.hpp"

extern Coordinator gCoordinator;


class PhysicsSystem : public System
{
public:
	void Init(){
    }

	void Update(float dt){
        for (auto const& entity : mEntities)
	    {
		auto& rigidBody = gCoordinator.GetComponent<RigidBody>(entity);
		auto& transform = gCoordinator.GetComponent<Transform>(entity);
		auto const& gravity = gCoordinator.GetComponent<Gravity>(entity);

		transform.position += rigidBody.velocity * dt;

		rigidBody.velocity += gravity.force * dt;
	    }
    }
};