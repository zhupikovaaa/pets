#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>

using namespace std;

int main()
{
	map<string, string> mp;
	auto [iterator1, succeed1] = mp.try_emplace("key", "abc");
	auto [iterator2, succeed2] = mp.try_emplace("key", "cde");
	auto [iterator3, succeed3] = mp.insert_or_assign("key", "fgh");
	auto [iterator4, succeed4] = mp.try_emplace("another_key", "cde");

	assert(succeed1);
	assert(!succeed2);
	assert(!succeed3);
	assert(succeed4);

	for (auto&& [key, value] : mp)
	{
		cout << key << ":" << value << endl;
	}
  }



