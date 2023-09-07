#pragma once
#include <string>
#include <random>

class Entity
{
public:
	std::string name;
	int health;

	Entity();

	const char* toString();
};

//template specialization
template<>
inline void GenericArray<Entity>::listContents()
{

}