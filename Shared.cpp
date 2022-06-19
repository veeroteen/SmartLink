#include "Shared.h"
shared_ptr_toy::shared_ptr_toy(const shared_ptr_toy& oth) {
	toy = oth.toy;
	controller = oth.controller;
	controller->count++;
}
shared_ptr_toy::shared_ptr_toy(std::string name) {
	controller = new Control();
	toy = new Toy(name);
}
shared_ptr_toy::shared_ptr_toy() {
	controller = new Control();
	toy = new Toy();
}
shared_ptr_toy::~shared_ptr_toy() {
	controller->count--;
	if (controller->count == 0) {
		delete toy;
		delete controller;
	}
}
std::string shared_ptr_toy::getName()const {
	return toy->getName();
}
shared_ptr_toy& shared_ptr_toy::operator = (const shared_ptr_toy& oth) {
	if (this == &oth) {
		return *this;
	}
	if (this->toy != nullptr) {
		controller->count--;
		if (controller->count == 0) {
			delete toy;
			delete controller;
		}
	}
	controller = oth.controller;
	toy = oth.toy;
	controller->count++;
	return *this;
}