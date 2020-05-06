#include <catch2/catch.hpp>
#include <string>
#include "LeetcodeProblems\57H_Insert_Interval.h"

using namespace Leetcode;
using namespace LC57H;

namespace {
	using namespace std;
	vector<vector<int>> sort( vector<vector<int>> v )
	{
		std::sort( v.begin(), v.end(), []( const vector<int>& lhs, const vector<int>& rhs) {
			if (lhs[0] < rhs[0]) return true;
			return lhs[1] < rhs[1];
		} );
		return v;
	}
}

TEST_CASE( "Leetcode #57: Insert Interval", "[leetcode][hard]" )
{
	using namespace std;
	Solution s;
	//LC Tests:
	CHECK( sort(s.insert( {}, { 5,7 } ) ) == sort( {{ 5,7 }} ) );
	CHECK( sort(s.insert( {{1,3},{6,9} },  { 2,5 } )) == sort({ { 1, 5 }, { 6,9 } } )); 
	CHECK( sort(s.insert( {{1,2},{3,5},{6,7},{8,10},{12,16}}, { 4,8 } ) ) == sort( {{1,2},{3,10},{12,16}} ) ); 
	CHECK( sort( s.insert( { {1,5} }, { 2,3 } ) ) == sort( {{ 1,5 }} ) );

}
