#include <catch2/catch.hpp>
#include <vector>
#include "LeetcodeProblems\311M_Sparse_Matrix_Multiplication.h"

using namespace Leetcode::LC311M;

TEST_CASE( "Leetcode #311: Sparse Matrix Multiplication", "[leetcode][medium]" )
{
	using namespace std;
	Solution s;
	//LC Tests:
	CHECK( s.multiply( { {1,-5} }, { {12},
	                                 {-1} }
	) == vector<vector<int>>
	{ { 17 }}
	);

	//main test
	CHECK( s.multiply(
		{{  1,0,0 },
		 { -1,0,3 }},

		{{ 7,0,0 },
		 { 0,0,0 },
		 { 0,0,1 }}
	) == vector<vector<int>>
	{{ 7,0,0 }, 
	 {-7,0,3 }}
	);



}
