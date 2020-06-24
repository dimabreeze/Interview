#include <catch2/catch.hpp>
#include <sstream>
#include "Algorithms\Geometry.h"

using namespace std;

TEST_CASE( "Geometry: dot_product", "[geometry][dot_product]" )
{
	CHECK( dot_product<int>( vector<int>{}, vector<int>{} ) == 0 );

	CHECK( dot_product<int>( vector<int>{1}, vector<int>{0} ) == 0 );
	CHECK( dot_product<int>( vector<int>{0}, vector<int>{1} ) == 0 );

	CHECK( dot_product<int>( vector<int>{1,0}, vector<int>{0,1} ) == 0 );
	CHECK( dot_product<int>( vector<int>{0,1}, vector<int>{1,0} ) == 0 );

	CHECK( dot_product<int>( vector<int>{0, 0, 0, 0}, vector<int>{1, 1, 1, 1, 1, 1, 1} ) == 0 );
	CHECK( dot_product<int>( vector<int>{1, 1, 1, 1}, vector<int>{1, 1, 1, 1} ) == 4 );
	CHECK( dot_product<int>( vector<int>{1, 1, 1, 1, 1, 1}, vector<int>{1, 1, 1, 1, 0, 0} ) == 4 );
}

TEST_CASE( "Geometry: cos", "[geometry][cos]" )
{
	CHECK( cos( vector<int>{}, vector<int>{} ) == 0 );

	CHECK( cos( vector<int>{1}, vector<int>{0} ) == 0 );
	CHECK( cos( vector<int>{0}, vector<int>{1} ) == 0 );

	CHECK( cos( vector<int>{1, 0}, vector<int>{0, 1} ) == 0 );
	CHECK( cos( vector<int>{0, 1}, vector<int>{1, 0} ) == 0 );

	CHECK( cos( vector<int>{0, 0, 0, 0}, vector<int>{1, 1, 1, 1, 1, 1, 1} ) == 0 );
	CHECK( cos( vector<int>{1, 1, 1, 1}, vector<int>{1, 1, 1, 1} ) == 1 );
	CHECK( cos( vector<int>{1, 1, 1, 1, 1, 1}, vector<int>{1, 1, 1, 1, 0, 0} ) == 0.81649658092772615 );
}

