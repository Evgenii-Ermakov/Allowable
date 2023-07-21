#pragma once

#include <iostream>
#include <type_traits>

#define PROTECT template <typename P = current_type, typename T = std::enable_if_t<std::is_base_of<protector, P>::value>>

class protected_class
{
public:
	explicit protected_class(int i, double d);

	// available methods. e.g. non const getters
	int get_int() const;
	double get_double() const;

	// non availabler methods. e.g. setters
	//template <typename P = current_type, typename T = std::enable_if_t<std::is_base_of<protector, P>::value>>
	PROTECT void set_int(int i) { return set_int_impl(i); }

	//template <typename P = current_type, typename T = std::enable_if_t<std::is_base_of<protector, P>::value>>
	PROTECT void set_double(double d) { return set_double_impl(d); }

private:
	void set_int_impl(int i);
	void set_double_impl(double d);

private:
	int int_;
	double double_;
};

std::ostream& operator<<(std::ostream& os, const protected_class& value);
