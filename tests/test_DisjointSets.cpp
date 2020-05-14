#include <catch2/catch.hpp>
#include "DataStructures\DisjointSets.h"

TEST_CASE( "Disjoint Sets", "[ADS][algo]" )
{
	DisjointSets ds;
	CHECK( ds.getCountDistinct() == 0 );

	auto s0 = ds.CreateSet();
	CHECK( ds.FindSet(0) == 0 );
	CHECK( ds.getCountDistinct() == 1 );

	auto s1 = ds.CreateSet();
	CHECK( ds.FindSet( s0 ) == 0 );
	CHECK( ds.FindSet( s1 ) == 1 );
	CHECK( ds.getCountDistinct() == 2 );
	CHECK( ds.IsSameSet( s0, s1 ) == false );

	CHECK( ds.Union( s0, s1 ) == s0 );
	CHECK( ds.IsSameSet( s0, s1 ) == true );
	CHECK( ds.getCountDistinct() == 1 );
	CHECK( ds.Union( s0, s1 ) == s0 );
	CHECK( ds.getCountDistinct() == 1 );

	auto s3 = ds.CreateSet();
	auto s4 = ds.CreateSet();
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
