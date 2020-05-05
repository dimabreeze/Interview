#include <catch2/catch.hpp>
//#include <string>
#include "LeetcodeProblems\76M_Minimum_Window_Substring.h"


TEST_CASE( "Leetcode #76: Minimum Window Substring", "[leetcode][medium]" )
{
	Solution76 s;
	CHECK( s.minWindow( "ADOBECODEBANC", "ABC" )     == "BANC" );
	CHECK( s.minWindow( "cabwefgewcwaefgcf", "cae" ) == "cwae" );
	CHECK( s.minWindow( "aaaaaaaaaaaabbbbbcdd", "abcdd" ) == "abbbbbcdd" );
}
