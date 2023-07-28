
#pragma once
#include"stdh.hpp"

namespace
{
	namespace O1
	{
		namespace smart_pointer
		{
			template<typename T>
			concept Concept = requires(T x) { typename T::element_type; *x; };
		}
		namespace dump_pointer
		{
			template<typename T>
			concept Concept = requires(T x) { *x; };
		}
		namespace reference
		{
			template<typename Ref>
			concept Concept = requires(Ref ref) { typename Ref::type; ref.get(); };
		}
	}
}
