#include <catch2/catch.hpp>
#include "LeetcodeProblems\989E_Add_to_Array_Form_of_Integer.h"

using namespace Leetcode::LC989E;
using namespace std;

TEST_CASE( "Leetcode #989: Add to Array Form of Integer", "[leetcode][easy]" )
{
	using namespace std;
	Solution s;

	//LC Tests:
	;
	CHECK( s.addToArrayForm( {1,2,0,0},  34) == vector<int>{1, 2, 3, 4} );
	CHECK( s.addToArrayForm( {2,7,4},   181) == vector<int>{4,5,5}      );
	CHECK( s.addToArrayForm( {2,1,5},   806) == vector<int>{1,0,2,1}    );
	CHECK( s.addToArrayForm( {9,9,9,9,9,9,9,9,9,9}, 1) == vector<int>{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} );
}