#include "pch.h"
#include "HashSet.h"

using namespace std;

MyHashSet::MyHashSet() : capacity( 100 ), data( capacity ) {}

void MyHashSet::add( int key ) {
	if (contains( key )) return;

	if (INCREASE_CAPACITY_IF_NEEDED and loadfactor() >= maxLF)
	{
		increaseCapacity( capacityMultiplier );
	}
	data[hash( key )].push_back( key );
	++mSize;
}

void MyHashSet::remove( int key ) {
	list<int>* plist;
	list<int>::iterator* plistIter;
	if (!find_internal( key, &plist, &plistIter )) return;

	plist->erase( *plistIter );
	--mSize;
}

/** Returns true if this set contains the specified element */
bool MyHashSet::contains( int key ) {
	list<int>* plist;
	list<int>::iterator* plistIter;
	return find_internal( key, &plist, &plistIter );
}
size_t MyHashSet::size() {
	return mSize;
}
bool  MyHashSet::empty() {
	return mSize == 0;
}

size_t MyHashSet::hash( int key ) { return key % capacity; }
double MyHashSet::loadfactor() { return static_cast<double>(mSize) / capacity; }
bool   MyHashSet::find_internal( int key, list<int>** plist, list<int>::iterator** plistIter ) {
	*plist = nullptr;
	*plistIter = nullptr;
	if (empty()) return false;

	auto& l = data[hash( key )];
	if (l.empty()) return false;

	auto iter = std::find_if( l.begin(), l.end(), [key]( const auto& element ) {
		return element == key;
	} );

	if (iter == l.end()) return false;
	*plist = &l;
	*plistIter = &iter;
	return true;
}
void MyHashSet::increaseCapacity( double multiplier )
{
	size_t newCapacity = static_cast<size_t>(capacity * multiplier);
	auto newData = DataType( newCapacity );
	for (auto& l : data)
	{
		if (l.empty()) continue;
		for (auto key : l)
		{
			newData[hash( key )].push_back( key );
		}
		l.clear();
	}

	std::swap( data, newData );
}
