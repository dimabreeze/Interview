#include "pch.h"
#include "223M_Rectangle_Area.h"

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
		r1.left = std::max( r1.left, r2.left );                  //l
		r1.right = std::max( std::min( r1.right, r2.right ), r1.left ); //r
		r1.bottom = std::max( r1.bottom, r2.bottom );                  //b
		r1.top = std::max( std::min( r1.top, r2.top ), r1.bottom );   //t
		return r1;
	}

	int area( Rect r )
	{
		return (r.top - r.bottom) * (r.right - r.left);
	}

	Rect toRect( int A, int B, int C, int D ) //int E, int F, int G, int H
	{
		return Rect{
			/*l*/ A,
			/*r*/ C,
			/*t*/ D,
			/*b*/ B
		};
	}
}

using namespace Leetcode::LC223M;

int Solution::computeArea( int A, int B, int C, int D, int E, int F, int G, int H ) const {
	const Rect r1 = toRect( A, B, C, D );
	const Rect r2 = toRect( E, F, G, H );

	return area( r1 ) - area( intersection( r1, r2 ) ) + area( r2 );
}
