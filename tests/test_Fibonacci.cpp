#include <catch2/catch.hpp>
#include "DataStructures\Fibonacci.h"

using namespace Algorithms;

TEST_CASE( "Algorithms: Fibonacci recursive", "[algo][recursion]" )
{
	CHECK( fib_recursive( 0 ) == 0);
	CHECK( fib_recursive( 1 ) == 1 );
	CHECK( fib_recursive( 2 ) == 1 );
	CHECK( fib_recursive( 3 ) == 2 );
	CHECK( fib_recursive( 4 ) == 3 );
	CHECK( fib_recursive( 5 ) == 5 );
	CHECK( fib_recursive( 6 ) == 8 );
}
