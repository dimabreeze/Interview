#pragma once

namespace Leetcode
{
	namespace LC223M
	{
/*
https://leetcode.com/problems/rectangle-area/

Find the total area covered by two rectilinear rectangles in a 2D plane.
Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Note:
Assume that the total area is never beyond the maximum possible value of int.
-------------
Example 1:
Input: 
-3
0
3
4
0
-1
9
2
Output: 45
-------------
Example 2:
Input: 
0
0
50000
40000
0
0
50000
40000
Output: 50000*40000

-------------
Submission: https://leetcode.com/submissions/detail/334974518/
*/
		struct Solution {
			int computeArea( int A, int B, int C, int D, int E, int F, int G, int H ) const;
		};
	}
}
