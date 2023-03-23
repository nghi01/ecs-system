#pragma once

#include <bitset>

//ECS types
using Entity = std::uint32_t;
const Entity MAX_ENTITIES = 100000;

using Component = std::uint8_t;
const Component MAX_COMPONENTS = 32;

using Signature = std::bitset<MAX_COMPONENTS>;