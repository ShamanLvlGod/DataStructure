#include "stdafx.h"
#include<iostream>
#include<vector>
#include<map>
#include<ctime>

class ThetaOStructure
{
	// A resizable array 
	std::vector <int> arr;
	// A hash where keys are array elements and vlaues are 
	// indexes in arr[] 
	std::map <int, int> Map;

public:
	// A Theta(1) function to add an element to MyDS 
	// data structure 
	void add(int x)
	{
		// if element is already present, then noting to do 
		if (Map.find(x) != Map.end())
			return;

		// else put element at the end of arr[] 
		int index = arr.size();
		arr.push_back(x);

		// and hashmap also 
		Map.insert(std::pair<int, int>(x, index));
	}

	// function to remove a number to DS in O(1) 
	void remove(int x)
	{
		// element not found then return 
		if (Map.find(x) == Map.end())
			return;

		// remove element from map 
		int index = Map.at(x);
		Map.erase(x);

		// swap with last element in arr 
		// then remove element at back 
		int last = arr.size() - 1;
		std::swap(arr[index], arr[last]);
		arr.pop_back();

		// Update hash table for new index of last element 
		Map.at(arr[index]) = index;
	}

	// Returns index of element if element is present, otherwise null 
	int search(int x)
	{
		if (Map.find(x) != Map.end())
			return Map.at(x);
		return -1;
	}

	// Returns a random element from myStructure 
	int getRandom()
	{
		// Find a random index from 0 to size - 1 
		srand(time(NULL));
		int random_index = rand() % arr.size();

		// Return element at randomly picked index 
		return arr.at(random_index);
	}
};

// Driver main 
int main()
{
	ThetaOStructure ds;
	ds.add(10);
	ds.add(20);
	ds.add(30);
	ds.add(40);
	std::cout << ds.search(30) << std::endl;
	ds.remove(20);
	ds.add(50);
	std::cout << ds.search(50) << std::endl;
	std::cout << ds.getRandom() << std::endl;
}