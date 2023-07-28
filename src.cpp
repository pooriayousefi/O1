
#include"O1/O1.hpp"

// entry point
auto main()->int
{
	try
	{
		O1::vector<int> hv{};

		hv.data.emplace_back(3); hv.data.emplace_back(0); hv.data.emplace_back(-1); hv.data.emplace_back(5);
		hv.data.emplace_back(0); hv.data.emplace_back(1); hv.data.emplace_back(-3); hv.data.emplace_back(-1);
		hv.data.emplace_back(4); hv.data.emplace_back(4); hv.data.emplace_back(-7); hv.data.emplace_back(9);
		hv.data.emplace_back(0); hv.data.emplace_back(8); hv.data.emplace_back(-9); hv.data.emplace_back(-4);

		hv.update();

		std::cout << "\n\ndata:\n\n"; hv.show_data(std::cout);
		std::cout << "\nsearch view:\n\n"; hv.show_search_view(std::cout);
		std::cout << "\nsort view:\n\n"; hv.show_sort_view(std::cout);		

		return EXIT_SUCCESS;
	}
	catch (const std::exception& xxx)
	{
		std::cerr << xxx.what() << std::endl;
		return EXIT_FAILURE;
	}
}