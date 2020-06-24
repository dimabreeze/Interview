#include <catch2/catch.hpp>
#include "Algorithms\Utils.h"

#include <queue>

using namespace Utils;

TEST_CASE( "Utils: priority_queue/max", "[priority_queue]" )
{
	std::priority_queue<int/*, std::vector<int>, std::greater<int>*/> maxq;
	maxq.push( 2 );
	maxq.push( 1 );
	maxq.push( 3 );
	CHECK( maxq.top() == 3 );
}
TEST_CASE( "Utils: priority_queue/min", "[priority_queue]" )
{
	std::priority_queue<int, std::vector<int>, std::greater<int>> minq;
	minq.push( 2 );
	minq.push( 1 );
	minq.push( 3 );
	CHECK( minq.top() == 1 );
}