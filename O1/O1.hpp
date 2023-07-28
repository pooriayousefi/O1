
#pragma once
#include"functors.hpp"

namespace
{
	namespace O1
	{
		// vector data structure
		template<typename T>
		struct vector
		{
			// type definitions
			using reference_t = std::reference_wrapper<T>;
			
			// members
			std::vector<T, std::allocator<T>> data;

			std::unordered_multiset<
				reference_t,
				reference::hash<reference_t>,
				reference::equal_to<reference_t>,
				std::allocator<reference_t>
			> search_view;

			std::multiset<
				reference_t,
				reference::less<reference_t>,
				std::allocator<reference_t>
			> sort_view;

			// default-ctor
			vector()
				:data{},
				search_view{},
				sort_view{}
			{
			}

			// dtor
			virtual ~vector() = default;

			// data display method
			auto show_data(std::ostream& ostr) const->void
			{
				std::ranges::for_each(
					data,
					[&ostr](auto& e)
					{
						ostr << e << '\t' << reinterpret_cast<uintptr_t>(&e) << '\n';
					}
				);
			}
			auto show_data(std::wostream& ostr) const->void
			{
				std::ranges::for_each(
					data,
					[&ostr](auto& e)
					{
						ostr << e << '\t' << reinterpret_cast<uintptr_t>(&e) << '\n';
					}
				);
			}

			// search view display method
			auto show_search_view(std::ostream& ostr) const->void
			{
				std::ranges::for_each(
					search_view,
					[&ostr](auto& e) 
					{
						ostr << e.get()  << '\t' << reinterpret_cast<uintptr_t>(&e.get()) << '\n';
					}
				);
			}
			auto show_search_view(std::wostream& ostr) const->void
			{
				std::ranges::for_each(
					search_view,
					[&ostr](auto& e)
					{
						ostr << e.get() << L'\t' << reinterpret_cast<uintptr_t>(&e.get()) << L'\n';
					}
				);
			}

			// sort view display method
			auto show_sort_view(std::ostream& ostr) const->void
			{
				std::ranges::for_each(
					sort_view,
					[&ostr](auto& e)
					{
						ostr << e.get() << '\t' << reinterpret_cast<uintptr_t>(&e.get()) << '\n';
					}
				);
			}
			auto show_sort_view(std::wostream& ostr) const->void
			{
				std::ranges::for_each(
					sort_view,
					[&ostr](auto& e)
					{
						ostr << e.get() << L'\t' << reinterpret_cast<uintptr_t>(&e.get()) << L'\n';
					}
				);
			}

			// search view update
			constexpr auto update_search_view() -> void
			{
				search_view.clear();
				std::ranges::for_each(
					data,
					[this](auto& e)
					{
						search_view.emplace(std::ref(e));
					}
				);
			}

			// sort view update
			constexpr auto update_sort_view() -> void
			{
				sort_view.clear();
				std::ranges::for_each(
					data,
					[this](auto& e)
					{
						sort_view.emplace(std::ref(e));
					}
				);
			}

			// update both spaces
			constexpr auto update() -> void
			{
				update_search_view();
				update_sort_view();
			}
		};
	}
}
