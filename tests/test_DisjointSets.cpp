#include <catch2/catch.hpp>
#include "Algorithms\DisjointSets.h"

using namespace std;

TEST_CASE( "Disjoint Sets", "[ADS][algo]" )
{
	DisjointSets ds;
	CHECK( ds.getCountDistinct() == 0 );

	auto s0 = ds.CreateSet(0);
	CHECK( ds.FindSet(0) == 0 );
	CHECK( ds.getCountDistinct() == 1 );

	auto s1 = ds.CreateSet(1);
	CHECK( ds.FindSet( s0 ) == 0 );
	CHECK( ds.FindSet( s1 ) == 1 );
	CHECK( ds.getCountDistinct() == 2 );
	CHECK( ds.IsSameSet( s0, s1 ) == false );

	CHECK( ds.Union( s0, s1 ) == s0 );
	CHECK( ds.IsSameSet( s0, s1 ) == true );
	CHECK( ds.getCountDistinct() == 1 );
	CHECK( ds.Union( s0, s1 ) == s0 );
	CHECK( ds.getCountDistinct() == 1 );

	auto s3 = ds.CreateSet(3);
	auto s4 = ds.CreateSet(4);
	CHECK( ds.getCountDistinct() == 3 );
	CHECK( ds.Union( s3, s4 ) == s3 );
	CHECK( ds.FindSet( s3 ) == s3 );
	CHECK( ds.FindSet( s4 ) == s3 );
	CHECK( ds.getCountDistinct() == 2 );

	CHECK( ds.IsSameSet( s0, s1 ) == true );
	CHECK( ds.IsSameSet( s1, s0 ) == true );
	CHECK( ds.IsSameSet( s3, s4 ) == true );
	CHECK( ds.IsSameSet( s4, s3 ) == true );

	CHECK( ds.IsSameSet( s0, s3 ) == false );
	CHECK( ds.IsSameSet( s1, s3 ) == false );
	CHECK( ds.IsSameSet( s0, s4 ) == false );
	CHECK( ds.IsSameSet( s1, s4 ) == false );

	CHECK( ds.Union( s1, s4 ) == s0 );
	CHECK( ds.getCountDistinct() == 1 );
	CHECK( ds.IsSameSet( s0, s3 ) == true );
	CHECK( ds.IsSameSet( s1, s3 ) == true );
	CHECK( ds.IsSameSet( s0, s4 ) == true );
	CHECK( ds.IsSameSet( s1, s4 ) == true );
}

namespace
{
	class Solution {
	public:
		vector<int> numIslands2( int m, int n, vector<vector<int>> positions ) {
			DisjointSets ds;

			const auto getidx = [m, n]( int r, int c ) { return r * n + c; };

			vector<int> result;
			for (auto& pos : positions)
			{
				const auto idx = getidx( pos[0], pos[1] );
				ds.CreateSet( idx );

				if (pos[0] > 0)
					ds.Union( idx, getidx( pos[0] - 1, pos[1] ) );
				if (pos[1] > 0)
					ds.Union( idx, getidx( pos[0], pos[1] - 1 ) );
				if (pos[0] < m - 1)
					ds.Union( idx, getidx( pos[0] + 1, pos[1] ) );
				if (pos[1] < n - 1)
					ds.Union( idx, getidx( pos[0], pos[1] + 1 ) );

				result.push_back( ds.getCountDistinct() );
			}

			return result;
		}
	};
}

TEST_CASE( "Disjoint Sets / Leetcode #305: Number of Islands II", "[ADS][algo][leetcode][Hard]" )
{
	Solution sol;
	CHECK( 
		sol.numIslands2( 3, 3, { 
			{ 0, 0 }, 
			{ 0, 1 }, 
			{ 1, 2 }, 
			{ 2, 1 }
	} ) == vector<int>{ 1,1,2,3 } );


	CHECK(sol.numIslands2( 3, 3, {
		{ 0, 1}, 
		{ 1, 2}, 
		{ 2, 1}, 
		{ 1, 0}, 
		{ 0, 2},
		{ 0, 0}, 
		{ 1, 1}}) == vector<int>{ 1,2,3,4,3,2,1 } );

	CHECK( sol.numIslands2( 3, 3, { {0,0},{0,1},{1,2},{1,2} } ) == vector<int>{ 1, 1, 2, 2 } );
	
	CHECK( sol.numIslands2( 3, 6, { {2,2},{2,1},{1,3},{0,4} } ) == vector<int>{ 1, 1, 2, 3 } );

}
/*
  012345
 0....x.
 1..x...
 2.xx...

 1,1,1

*/