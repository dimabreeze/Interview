#pragma once

namespace Leetcode
{
	namespace LC56M
	{
/*
https://leetcode.com/problems/merge-intervals/

Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

Submission: https://leetcode.com/submissions/detail/335710828/

*/
		class Solution {
		public:
			std::vector<std::vector<int>> merge( std::vector<std::vector<int>> intervals ) const;
		};
	}
}
