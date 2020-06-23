#include "pch.h"
#include "57H_Insert_Interval.h"

using namespace Leetcode::LC57H;

Solution::Intervals Solution::insert( const Intervals& intervals, Interval newInterval ) const {
	Intervals res;
	res.reserve( intervals.size() + 1 );

	bool merged = false;
	for (size_t idx = 0; idx < intervals.size(); ++idx)
	{
		auto& interval = intervals[idx];
		if (interval[1] < newInterval[0] or newInterval[1] < interval[0])
		{
			if (newInterval[1] < interval[0] and !merged)
			{
				res.push_back( newInterval );
				merged = true;
			}
			res.push_back( interval );
			continue;
		}
		newInterval[0] = std::min( interval[0], newInterval[0] );
		newInterval[1] = std::max( interval[1], newInterval[1] );
	}
	if (!merged)
	{
		res.push_back( newInterval );
	}
	return res;
}