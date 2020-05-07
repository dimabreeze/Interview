#include <catch2/catch.hpp>
#include "LeetcodeProblems\56M_Merge_Intervals.h"

using namespace Leetcode::LC56M;

TEST_CASE( "Leetcode #56: Merge Interval", "[leetcode][medium]" )
{
	using namespace std;
	using VI = vector<int>;
	using VVI = vector<VI>;

	Solution s;
	//LC Tests:
	CHECK( s.merge( { {1, 3}, {2, 6}, {8, 10}, {15, 18} } ) == VVI{ { 1, 6 }, { 8, 10 }, { 15, 18 }} );
	CHECK( s.merge( { {1, 4}, {4, 5} } ) == VVI { { 1, 5 }} );
}