#include <catch2/catch.hpp>
#include "LeetcodeProblems\223M_Rectangle_Area.h"

using namespace Leetcode;
using namespace LC223M;

TEST_CASE( "Leetcode #223: Rectangle Area", "[leetcode][medium]" )
{
	Solution s;
	CHECK( s.computeArea( 0, 0, 0, 0, 0, 0, 0, 0 ) == 0 );
	CHECK( s.computeArea( -3,0,3,4,0,-1,9,2 ) == 45 );
	CHECK( s.computeArea( 0,0,50000,40000,0,0,50000,40000 ) == 50000*40000 );

}
