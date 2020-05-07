#include <catch2/catch.hpp>
#include "LeetcodeProblems\273H_Integer_to_English_Words.h"

using namespace Leetcode::LC273H;

TEST_CASE( "Leetcode 273: Integer to English Words", "[leetcode][hard]" )
{
	using namespace std;

	Solution s;
	//LC Tests:
	CHECK( s.numberToWords(123) == "One Hundred Twenty Three" );
	CHECK( s.numberToWords(12345) == "Twelve Thousand Three Hundred Forty Five" );
	CHECK( s.numberToWords(1234567) == "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven" );
	CHECK( s.numberToWords(1234567891) == "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One" );
	CHECK( s.numberToWords(999) == "Nine Hundred Ninety Nine" );
}

