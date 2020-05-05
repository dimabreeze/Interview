#pragma once
#include <vector>

namespace Leetcode
{
	namespace LC84H
	{
/*
https://leetcode.com/problems/largest-rectangle-in-histogram

Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, 
find the area of largest rectangle in the histogram.

Example:
Input: [2,1,5,6,2,3]
Output: 10

Submission: https://leetcode.com/submissions/detail/334931447/
*/
		class Solution {
		public:
			int largestRectangleArea( std::vector<int> heights ) const;
		};
	}
}