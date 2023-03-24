cmake_minimum_required(VERSION 3.26.1)
project(ECS)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(ECS)

target_compile_options(
	ECS
	PRIVATE
	-fno-exceptions
	-Wall)

target_sources(
	ECS
	PRIVATE
	Source/main.cpp
    Source/System.hpp
	Source/SystemManager.hpp
	Source/Coordinator.hpp
    Source/Components.hpp
	Source/ComponentManager.hpp
	Source/EntityManager.hpp
	Source/PhysicsSystem.hpp
	Source/type.hpp
	Source/vec3.hpp)

target_include_directories(
	ECS
	PRIVATE
	Source)
