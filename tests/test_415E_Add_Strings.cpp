#include <catch2/catch.hpp>
#include "LeetcodeProblems\415E_Add_Strings.h"

using namespace Leetcode::LC451E;

TEST_CASE( "Leetcode #451: Add Strings", "[leetcode][easy]" )
{
	using namespace std;
	Solution s;

	//LC Tests:
	CHECK( s.addStrings( "99", "9" ) == "108" );
	CHECK( s.addStrings( "1", "9" ) == "10" );


}
