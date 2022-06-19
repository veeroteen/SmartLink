#pragma once
#include <string>
class Toy
{
	std::string name;
public:
	Toy(std::string name = "Ball");
	std::string getName() const;
};

