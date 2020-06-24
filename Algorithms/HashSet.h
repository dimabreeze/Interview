#pragma once
#include <list>
#include <vector>
#include <algorithm>

class MyHashSet {
private:
	const bool INCREASE_CAPACITY_IF_NEEDED = false;
	const double maxLF = 0.8;
	const double capacityMultiplier = 1.5;

public:
	/** Initialize your data structure here. */
	MyHashSet();

	void add( int key );
	void remove( int key );

	/** Returns true if this set contains the specified element */
	bool contains( int key );
	size_t size();
	bool   empty();

private:
	size_t capacity;
	size_t mSize = 0;

	using DataType = std::vector<std::list<int>>;
	DataType data;

private:
	size_t hash( int key );
	double loadfactor();
	bool   find_internal(int key, DataType::value_type** plist, DataType::value_type::iterator** plistIter );
	void   increaseCapacity(double mult);
};