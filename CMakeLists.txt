cmake_minimum_required(VERSION 3.26.1)
project(ECS)


set(CMAKE_CXX_STANDARD 17)
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
	Source/ComponentArray.hpp
	Source/ComponentManager.hpp
	Source/Coordinator.hpp
	Source/EntityManager.hpp
	Source/EventManager.hpp
	Source/System.hpp
	Source/SystemManager.hpp
	Source/type.hpp)

target_include_directories(
	ECS
	PRIVATE
	Source)
