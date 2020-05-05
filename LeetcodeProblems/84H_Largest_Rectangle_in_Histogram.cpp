#include "pch.h"
#include "84H_Largest_Rectangle_in_Histogram.h"

using namespace Leetcode::LC84H;

int Solution::largestRectangleArea( std::vector<int> heights ) const
{
	if (heights.empty()) return 0;
	if (heights.size() == 1) return heights[0];

	std::vector<int> smallerL( heights.size(), -1 ); //pos of smaller element on the L
	for (int i = 1; i < heights.size(); ++i)
	{
		int h = heights[i];
		int l = i - 1;
		while (l >= 0 and heights[l] >= heights[i])
		{
			l = smallerL[l]; //rather than constantly decreasing [l] we jump to next 'less'
		}
		smallerL[i] = l;
	}

	std::vector<int> smallerR( heights.size(), heights.size() ); //pos of smaller element on the R
	for (int i = heights.size() - 2; i >= 0; --i)
	{
		int r = i + 1;
		while (r < heights.size() and heights[r] >= heights[i])
		{
			r = smallerR[r]; //rather than constantly increasing [r] we jump to next 'less'
		}
		smallerR[i] = r;
	}

	int result = 0;
	for (int idx = 0; idx < heights.size(); ++idx)
	{
		const auto H = heights[idx];
		const auto W = smallerR[idx] - smallerL[idx] - 1; //pos of smaller element on the R / L
		result = std::max( { result, H*W } );
	}
	return result;
}