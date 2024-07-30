#ifndef SOLUTION_ONE_HPP
#define SOLUTION_ONE_HPP

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

class SmallestInfiniteSEt{
private:
	set<int> s;
public:
	SmallestInfiniteSEt(){
		constexpr int N=1000;
		for(int i=0; i<=N; i++){
			s.emplace(i);
		}
	}

	int popSmallest(){
		const int res=*s.begin();
		s.erase(s.begin());
		return res;
	}

	void addBack(int num){
		s.emplace(num);
	}
};

#endif // SOLUTION_ONE_HPP