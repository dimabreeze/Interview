#include <catch2/catch.hpp>
#include "DataStructures\Utils.h"

#include <queue>

using namespace Utils;


TEST_CASE( "Utils: priority_queue", "[priority_queue]" )
{
	std::priority_queue<int> maxq;
	maxq.push( 2 );
	maxq.push( 1 );
	maxq.push( 3 );

	CHECK( maxq.top() == 3 );

	std::priority_queue<int, std::vector<int>, std::greater<int>> minq;
}