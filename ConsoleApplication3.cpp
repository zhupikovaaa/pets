#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Config {
	string name;
	size_t id;
	vector<int> ids;
	template <size_t N>
	decltype(auto) get() const {
		if constexpr (N == 0) return string_view(name);
		else if constexpr (N == 1) return id;
		else if constexpr (N == 2) return (ids);
	} 
};

template<>
struct tuple_size<Config> : integral_constant<size_t, 3> {};

template<size_t N>
struct tuple_element<N, Config> {
	using type = decltype(declval<Config>().get<N>());
};

Config getElem()
{
	Config cnf = { "1231" , 12, vector<int>{1,3,2} };
	return cnf;
}

int main()
{
	auto [name, id, ids] = getElem();
}



