#pragma once

#include <iostream>
#include <type_traits>
#include <boost/type_traits/is_detected.hpp>


template<class T>
using allow_t = decltype(std::declval<T&>().not_prohibit());


//namespace
//{
//}

class protected_class
{
	//class protectee : private protecter
	//{};
	using current_type = protected_class;

	template<class T>
	struct det_allow : std::false_type {};

public:
	explicit protected_class(int i, double d);

	// available methods. e.g. non const getters
	int get_int() const;
	double get_double() const;

	// non availabler methods. e.g. setters
	template <typename P = current_type, typename T = std::enable_if_t<std::is_base_of<protector, P>::value>>
	void set_int(int i) { return set_int_impl(i); }

	template <typename P = current_type, typename T = std::enable_if_t<std::is_base_of<protector, P>::value>>
	void set_int(int i) { return set_int_impl(i); }


	//template <typename P = void, typename T = std::enable_if_t<std::is_base_of<protecter, P>::value>>
	//void set_int(int i) { return set_int_impl(i); }

	//-- Just for test without protection
	//template <typename P = void, typename T = std::enable_if_t<std::is_base_of<protecter, protecter>::value>>
	//void set_int(int i) { return set_int_impl(i); }


//	template <typename T = std::enable_if_t<std::is_base_of<protecter, protectee>::value>>
//	template <typename P = current_type, typename T = std::enable_if_t<std::is_base_of<protecter, P>::value>>
//	template <typename P = void, typename T = std::enable_if_t<std::is_base_of<protecter, P>::value>>
	//inline void set_double(double d) {
	//	std::cout << "Type(p) = " << typeid(P).name() << std::endl;
	//	return set_double_impl(d); }



	//template <typename T = std::enable_if_t<det_allow<T>::value>>
	//void set_double_en(double d) {
	//	std::cout << "Type(T) = " << typeid(T).name() << std::endl;
	//	return set_double_impl(d);
	//}

	static constexpr bool is_value = false;

	template<typename P = void, typename T = std::enable_if_t<boost::is_detected_v<allow_t, P>>>
	void set_double_boost(double d)
	{
		std::cout << "--Type(p) = " << typeid(P).name() << std::endl;
		std::cout << "--Type(T) = " << typeid(T).name() << std::endl;
		return set_double_impl(d);
	}


private:
	void set_int_impl(int i);
	void set_double_impl(double d);

private:
	int int_;
	double double_;
};

std::ostream& operator<<(std::ostream& os, const protected_class& value);

class abstarct
{
	virtual void func() = 0;
};
