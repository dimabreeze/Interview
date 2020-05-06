#include "pch.h"
#include <deque>
#include "621M_Task_Scheduler.h"


using namespace Leetcode::LC621M;
using namespace std;

int Solution::leastInterval( vector<char> tasks, int n ) {
	unordered_map<char, int> freq; //task frequency
	int maxcount = 0;
	for (auto t : tasks)
	{
		const auto f = ++freq[t];
		maxcount = std::max( maxcount, f );
	}
	const int S = tasks.size();
	const auto frame = n + 1;
	const auto numFrames = maxcount;
	int ans = (numFrames - 1) * frame;
	for (auto p : freq)
	{
		if (p.second == maxcount) ++ans; //one tick for each task with max count
	}

	return std::max( ans, S );
}
