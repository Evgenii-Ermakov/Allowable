#include "protected_class.h"
#include <type_traits>

protected_class::protected_class(int i, double d) : int_{ i }, double_{ d }
{
}

int protected_class::get_int() const
{
	return int_;
}

double protected_class::get_double() const
{
	return double_;
}


void protected_class::set_int_impl(int i)
{
	int_ = i;
}

void protected_class::set_double_impl(double d)
{
	double_ = d;
}

std::ostream& operator<<(std::ostream& os, const protected_class& value)
{
	os << "int = " << value.get_int() << ", double = " << value.get_double();
	return os;
}
