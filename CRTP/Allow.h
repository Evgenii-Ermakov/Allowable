#pragma once
#include <type_traits>

//#include "protected_class.h"

//namespace
//{
//	template<class T = int>
//	struct det_allow : std::true_type {};
//	//struct det_allow : std::false_type {};
//}

class protected_class;

class protector { };

class base_allow : private protector
{
};

class allow : private base_allow
{


private:
	struct all
	{

		void not_prohibit() {};
	};
//	using current_type = all;
	using current_type = allow;
//	template<class T = allow>
//	struct det_allow : std::true_type {};

	//class protectee : private protecter
	//{};
	using det_allow = std::true_type;
	//static constexpr bool is_value = true;

public:
//	using current_type = allow;
	void method(protected_class& protected_object, int i, double d);
};

class allow2 : public allow
{
//	using current_type = allow;
	//class protectee : private protecter
	//{};

public:
	void method2(protected_class& protected_object, int i, double d);
};
