#pragma once
#include "Toy.h"

struct Control{
	int count = 1;
};

class shared_ptr_toy
{
	Toy* toy;
	Control* controller;
public:
	shared_ptr_toy(const shared_ptr_toy& oth);
	shared_ptr_toy(std::string name);
	shared_ptr_toy(Toy toy);
	shared_ptr_toy();
	~shared_ptr_toy();
	Toy* get()const;
	shared_ptr_toy& operator = (const shared_ptr_toy& oth);
};

shared_ptr_toy make_shared_toy();
shared_ptr_toy make_shared_toy(std::string name);
shared_ptr_toy make_shared_toy(Toy& toy);
