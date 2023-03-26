#pragma once

#include "type.hpp"
#include <array>
#include <queue>
#include <cassert>

class EntityManager
{
private:
    //This queue is for unused entity IDs
	std::queue<Entity> mAvailableEntities{};
    
	std::array<Signature, MAX_ENTITIES> mSignatures{};
	uint32_t mLivingEntityCount{};
public:
	EntityManager()
	{
        // Initialize the queue with all possible entity IDs
		for (Entity entity = 0; entity < MAX_ENTITIES; entity++)
		{
			mAvailableEntities.push(entity);
		}
	}

	Entity CreateEntity()
	{
		assert(mLivingEntityCount < MAX_ENTITIES && "Too many entities in existence.");
        // Take an ID from the front of the queue
		Entity id = mAvailableEntities.front();
		mAvailableEntities.pop();
		++mLivingEntityCount;

		return id;
	}

	void DestroyEntity(Entity entity)
	{
		assert(entity < MAX_ENTITIES && "Entity out of range.");
        // Delete the entity's signature
		mSignatures[entity].reset();

        //Put the destroyed entity at the back of the queue
		mAvailableEntities.push(entity);
		--mLivingEntityCount;
	}

	void SetSignature(Entity entity, Signature signature)
	{
		assert(entity < MAX_ENTITIES && "Entity out of range.");
		mSignatures[entity] = signature;
	}

	Signature GetSignature(Entity entity)
	{
		assert(entity < MAX_ENTITIES && "Entity out of range.");
		return mSignatures[entity];
	}
};