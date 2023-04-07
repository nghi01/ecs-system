# ecs-system
I heard of ECS, or Entity Component System, a year ago from a colleague at Gameloft. The idea of a different style of programming that is different from OOP and performs better nonetheless all seems novel to me. I've always wanted to build one for my own usage and experience. 

ECS is a design pattern of DOP (Data-Oriented Programming), where instead of having classes act as blueprints and objects created from those blueprints, we have instead a logic of Entity-Component-System. Each entity would just be an id, each component would just be a struct containing information about the components that make up the entity, and we have some system that will iterate over the list of entities while searching up components. That's the basic concept of ECS.

In this ECS, I just use a very basic Physics System, but we can actually implement and use multiple systems at the same time. This ECS is for my personal use, but if other people want to fork and use it, they are free to do so.

Huge thanks and appreciation to [Austin Morlan's post on ECS](https://austinmorlan.com/posts/entity_component_system/) that gives me a inspiration and understanding of ECS. The ECS system I built is largely based on Austin's post. 

## Prerequisites
* Cmake
* A C++ Compiler

## How to run
Run these if you haven't created a build folder yet.

```
mkdir build
cd build
```

Now run:

```
cmake ..
cmake --build .
./Debug/ECS.exe
```
