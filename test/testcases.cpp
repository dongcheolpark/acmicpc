#include "catch.hpp"

#include <iostream>
#include <vector>

using namespace std;

TEST_CASE("vector1", "[vector_foreach]") {
	vector<int> v;
	for(int i = 0;i<1000000;i++) {
		v.push_back(i);
	}
	for(auto& item : v) {
		item *= 2;
	}
}

TEST_CASE("vector2", "[vector_iterator]") {
	vector<int> v;
	for(int i = 0;i<1000000;i++) {
		v.push_back(i);
	}
	for(auto item = v.begin();item != v.end();item++) {
		(*item) *= 2;
	}
}