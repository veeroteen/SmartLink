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
shared_ptr_toy::shared_ptr_toy(Toy toy) {
	controller = new Control();
	this->toy = new Toy(toy);
}
shared_ptr_toy::~shared_ptr_toy() {
	controller->count--;
	if (controller->count == 0) {
		delete toy;
		delete controller;
	}
}
Toy* shared_ptr_toy::get()const {
	if (toy != nullptr) {
		return toy;
	}
	return nullptr;
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

shared_ptr_toy make_shared_toy() {
	return shared_ptr_toy();
}

shared_ptr_toy make_shared_toy(std::string name) {
	return shared_ptr_toy(name);
}
shared_ptr_toy make_shared_toy(Toy &toy) {
	return shared_ptr_toy(toy);
}


