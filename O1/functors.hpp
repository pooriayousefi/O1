
#pragma once
#include"concepts.hpp"

namespace
{
	namespace O1
	{
		namespace smart_pointer
		{
			template<Concept Ptr>
			struct hash
			{
				constexpr auto operator()(const Ptr& ptr) const->size_t
				{
					std::hash<Ptr::element_type> h{};
					return h(*ptr);
				}
			};

			template<Concept Ptr>
			struct equal_to
			{
				constexpr auto operator()(const Ptr& lhs, const Ptr& rhs) const->bool
				{
					std::equal_to<Ptr::element_type> e{};
					return e(*lhs, *rhs);
				}
			};

			template<Concept Ptr>
			struct less
			{
				constexpr auto operator()(const Ptr& lhs, const Ptr& rhs) const->bool
				{
					std::less<Ptr::element_type> e{};
					return e(*lhs, *rhs);
				}
			};
		}
		namespace reference
		{
			template<Concept Ref>
			struct hash
			{
				constexpr auto operator()(const Ref& ref) const->size_t
				{
					std::hash<Ref::type> h{};
					return h(ref.get());
				}
			};

			template<Concept Ref>
			struct equal_to
			{
				constexpr auto operator()(const Ref& lhs, const Ref& rhs) const->bool
				{
					std::equal_to<Ref::type> e{};
					return e(lhs.get(), rhs.get());
				}
			};

			template<Concept Ref>
			struct less
			{
				constexpr auto operator()(const Ref& lhs, const Ref& rhs) const->bool
				{
					std::less<Ref::type> e{};
					return e(lhs.get(), rhs.get());
				}
			};
		}
	}
}
