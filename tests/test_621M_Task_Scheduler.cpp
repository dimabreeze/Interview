#include <catch2/catch.hpp>
#include "LeetcodeProblems\621M_Task_Scheduler.h"


using namespace Leetcode::LC621M;

TEST_CASE( "Leetcode #621: Task Scheduler", "[leetcode][medium][greedy]" )
{
	using namespace std;
	Solution s;

	//LC Tests:
	CHECK( s.leastInterval( { 'A','A','A','B','B','B'}, 2 ) == 8); //main
	CHECK( s.leastInterval( { 'A','A','A' }, 2 ) == 7 ); //main

}
