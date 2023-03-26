#pragma once

#include "type.hpp"
#include <set>
#include <iostream>


class System
{
public:
	std::set<Entity> mEntities;
	
	void ListEntities()
	{
		for (auto it = mEntities.begin(); it != mEntities.end(); ++it)
        	std::cout << ' ' << *it;
	}
};