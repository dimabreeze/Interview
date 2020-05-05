#include "pch.h"
#include "223M_Rectangle_Overlap.h"

namespace
{
	struct Rect {
		int left;
		int right;
		int top;
		int bottom;
	};

	Rect intersection( Rect r1, Rect r2 )
	{
		Rect res {
			std::max( r1.left, r2.left ),   //l
			std::min( r1.right, r2.right ), //r
			std::min( r1.top, r2.top ),     //t
			std::max( r1.bottom, r2.bottom )//b
		};
		if (res.top < res.bottom) res.top = res.bottom;
		if (res.right < res.left) res.right = res.left;
		return res;
	}

	int area( Rect r )
	{
		return (r.top - r.bottom) * (r.right - r.left);
	}

	Rect rect( int A, int B, int C, int D ) //int E, int F, int G, int H
	{
		return Rect {
			/*l*/ A,
			/*r*/ C,
			/*t*/ D,
			/*b*/ B
		};
	}
}

using namespace Leetcode::LC223M;

int Solution::computeArea( int A, int B, int C, int D, int E, int F, int G, int H ) const {
	const Rect r1 = rect( A, B, C, D );
	const Rect r2 = rect( E, F, G, H );

	return area( r1 ) - area( intersection( r1, r2 ) ) + area( r2 );
}
