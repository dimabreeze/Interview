#include <catch2/catch.hpp>
#include "Algorithms\FenwickTree.h"

using namespace std;

TEST_CASE( "FenwickTree: general test", "[FenwickTree][BIT][BinaryIndexTree]" )
{
	vector<int> input{ 1,2,3,4,5,6,7 };

	auto binaryIndexedTree = FenwickTree::createTree( input );
	CHECK(1 == FenwickTree::getSum( binaryIndexedTree, 0 ));
	CHECK( 3 == FenwickTree::getSum( binaryIndexedTree, 1 ));
	CHECK( 6 == FenwickTree::getSum( binaryIndexedTree, 2 ));
	CHECK( 10 == FenwickTree::getSum( binaryIndexedTree, 3 ));
	CHECK( 15 == FenwickTree::getSum( binaryIndexedTree, 4 ));
	CHECK( 21 == FenwickTree::getSum( binaryIndexedTree, 5 ));
	CHECK( 28 == FenwickTree::getSum( binaryIndexedTree, 6 ));
}


TEST_CASE( "FenwickTree: all ones", "[FenwickTree][BIT][BinaryIndexTree]" )
{
	vector<int> input{ 0,1,1,1,1,1,1 };

	auto binaryIndexedTree = FenwickTree::createTree( input );
	CHECK( 0 == FenwickTree::getSum( binaryIndexedTree, 0 ) );
	CHECK( 1 == FenwickTree::getSum( binaryIndexedTree, 1 ) );
	CHECK( 2 == FenwickTree::getSum( binaryIndexedTree, 2 ) );
	CHECK( 3 == FenwickTree::getSum( binaryIndexedTree, 3 ) );
	CHECK( 4 == FenwickTree::getSum( binaryIndexedTree, 4 ) );
	CHECK( 5 == FenwickTree::getSum( binaryIndexedTree, 5 ) );
	CHECK( 6 == FenwickTree::getSum( binaryIndexedTree, 6 ) );

	SECTION( "Update" )
	{
		FenwickTree::updateBinaryIndexedTree( binaryIndexedTree, -1, 4 );
		CHECK( 0 == FenwickTree::getSum( binaryIndexedTree, 0 ) );
		CHECK( 1 == FenwickTree::getSum( binaryIndexedTree, 1 ) );
		CHECK( 2 == FenwickTree::getSum( binaryIndexedTree, 2 ) );
		CHECK( 2 == FenwickTree::getSum( binaryIndexedTree, 3 ) );
		CHECK( 3 == FenwickTree::getSum( binaryIndexedTree, 4 ) );
		CHECK( 4 == FenwickTree::getSum( binaryIndexedTree, 5 ) );
		CHECK( 5 == FenwickTree::getSum( binaryIndexedTree, 6 ) );
	}

}