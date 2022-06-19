#include "Toy.h"
Toy::Toy(std::string name) {
	this->name = name;
}
std::string Toy::getName() const{
	return name;
}