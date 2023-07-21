#pragma once
#include <type_traits>

class protected_class;

class protector { };

class base_allow : private protector
{
};

class allow : private base_allow
{

public:
	using current_type = allow;

	void change(protected_class& protected_object, int i, double d);
};

class allow2 : public allow
{
public:
	void change2(protected_class& protected_object, int i, double d);
};
