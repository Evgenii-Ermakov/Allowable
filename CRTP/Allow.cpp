#include "Allow.h"

#include "protected_class.h"

//class protecter;

namespace
{
	//template<class T = void>
	//struct det_allow : std::true_type {};
//	using det_allow = std::true_type;
}

void allow::method(protected_class& protected_object, int i, double d)
{
//	using current_type = allow;

//	protected_object.set_int<protector>(i);
	protected_object.set_int<current_type>(i);
//	protected_object.set_double<current_type>(d);

//	using current_type = std::remove_pointer_t<decltype(this)>;

//	static_assert(std::is_base_of_v<protecter, current_type>, "Not a base of");

//	protected_object.set_int<current_type>(i * 2);
//	protected_object.set_double<current_type>(d * 3.5);
//	using det_allow = std::true_type;
//	protected_object.set_double_en<det_allow<>::type>(10);
//	protected_object.set_double_en<det_allow<>::type>(10);
//	protected_object.set_double_en<det_allow>(10);
//	protected_object.set_double_en(10);

	protected_object.set_double<current_type>(1122);

//	protected_object.set_double_boost<current_type>(22.11);
//	protected_object.set_double_boost(22.11);
}

void allow2::method2(protected_class& protected_object, int i, double d)
{
//	static_assert(std::is_base_of_v<protecter, current_type>, "Not a base of");

	//protected_object.set_int<current_type>(i * 2);
	//protected_object.set_double<current_type>(d * 3.5);

	//protected_object.set_double(1122);
}