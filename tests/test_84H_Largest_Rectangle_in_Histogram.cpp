#include <catch2/catch.hpp>
//#include <string>
#include "LeetcodeProblems\84H_Largest_Rectangle_in_Histogram.h"

using namespace Leetcode;
using namespace LC84H;

TEST_CASE( "Leetcode #84: Largest_Rectangle_in_Histogram", "[leetcode][medium][dp]" )
{
	Solution s;
	CHECK( s.largestRectangleArea( {} )    == 0 );
	CHECK( s.largestRectangleArea( { 0 } ) == 0 );
	CHECK( s.largestRectangleArea( { 3 } ) == 3 );
	CHECK( s.largestRectangleArea( { 3,3,3,3 } ) == 12 );
	CHECK( s.largestRectangleArea( { 4,3,3,3 } ) == 12 );
	CHECK( s.largestRectangleArea( { 4,3,3,4 } ) == 12 );

	CHECK( s.largestRectangleArea( { 2,1,5,6,2,3 } ) == 10 ); //LC TEST
	CHECK( s.largestRectangleArea( { 2,1 } ) == 2 );
	CHECK( s.largestRectangleArea( { 1,2 } ) == 2 );
}
