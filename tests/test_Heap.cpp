#include <catch2/catch.hpp>
#include "DataStructures\Heap.h"

TEST_CASE( "Heap (max)", "[heap]" )
{
	Heap<int> maxheap;
	REQUIRE( maxheap.size() == 0 );
	//REQUIRE_THROWS( maxheap.top() );

	maxheap.add( 1 );
	REQUIRE( maxheap.size() == 1 );
	CHECK( maxheap.top() == 1 );

	maxheap.add( 2 );
	REQUIRE( maxheap.size() == 2 );
	CHECK( maxheap.top() == 2 );

	maxheap.add( 20 );
	maxheap.add( 12 );
	maxheap.add( 13 );
	maxheap.add( 25 );
	maxheap.add( 14 );
	REQUIRE( maxheap.size() == 7 );
	CHECK( maxheap.top() == 25 );

	maxheap.pop();
	REQUIRE( maxheap.size() == 6 );
	CHECK( maxheap.top() == 20 );

	maxheap.add( 140 );
	REQUIRE( maxheap.size() == 7 );
	CHECK( maxheap.top() == 140 );
}

TEST_CASE( "Heap (min)", "[heap]" )
{
	Heap<int, std::greater<int>> minheap;
	REQUIRE( minheap.size() == 0 );
	//REQUIRE_THROWS( minheap.top() );

	minheap.add( 100 );
	REQUIRE( minheap.size() == 1 );
	CHECK( minheap.top() == 100 );

	minheap.add( 90 );
	REQUIRE( minheap.size() == 2 );
	CHECK( minheap.top() == 90 );

	minheap.add( 20 );
	minheap.add( 12 );
	minheap.add( 13 );
	minheap.add( 25 );
	minheap.add( 14 );
	REQUIRE( minheap.size() == 7 );
	CHECK( minheap.top() == 12 );

	minheap.pop();
	REQUIRE( minheap.size() == 6 );
	CHECK( minheap.top() == 13 );

	minheap.add( 1 );
	REQUIRE( minheap.size() == 7 );
	CHECK( minheap.top() == 1 );
}