#include "allow.h"

#include "protected_class.h"

void allow::change(protected_class& protected_object, int i, double d)
{
	protected_object.set_int<current_type>(i);
	protected_object.set_double<current_type>(d);
}

void allow2::change2(protected_class& protected_object, int i, double d)
{
	protected_object.set_int<current_type>(i * 2);
	protected_object.set_double<current_type>(d * 3.5);
}