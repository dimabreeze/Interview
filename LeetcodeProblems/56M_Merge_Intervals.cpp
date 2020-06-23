#include "pch.h"
#include "56M_Merge_Intervals.h"

using namespace Leetcode::LC56M;
using namespace std;

namespace
{
	using Interval = vector<int>;
	using Intervals = vector<Interval>;
	bool overlap( const Interval& l, const Interval& r )
	{
		return !(min( l[1], r[1] ) < max( l[0], r[0] ));
		/*
					   0        1
					   ==========

			  0        1
			  ==========
		*/
	}
	Interval intersection( const Interval& l, const Interval& r )
	{
		/*
				  0        1
				  ==========

			  0        1
			  ==========
		*/
		return Interval{ min( l[0], r[0] ), max( l[1], r[1] ) };
	}
	struct cmp
	{
		bool operator()( const Interval& l, const Interval& r ) const
		{
			if (l[0] != r[0]) return l[0] < r[0];
			return l[1] < r[1];
		}
	};
}

std::vector<std::vector<int>> Solution::merge( std::vector<std::vector<int>> intervals ) const {
	if (intervals.size() < 2) return intervals;

	Intervals ans;
	sort( intervals.begin(), intervals.end(), cmp{} ); //O(NlogN)

	ans.push_back( intervals[0] );
	for (size_t idx = 1; idx < intervals.size(); ++idx)
	{
		const auto& i = intervals[idx]; //current interval
		if (overlap( i, ans.back() )) ans.back()[1] = intersection( i, ans.back() )[1];
		else ans.push_back( i );
	} //O(N)

	return ans;
}