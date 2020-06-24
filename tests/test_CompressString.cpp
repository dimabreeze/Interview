#include <catch2/catch.hpp>
#include "Algorithms\CompressString.h"

TEST_CASE( "CompressString: fun_ptr", "[coding]" )
{
	CHECK( CompressString::visit( "" ) == "" );
	CHECK( CompressString::visit( "A" ) == "A" );
	CHECK( CompressString::visit( "AA" ) == "AA" );
	CHECK( CompressString::visit( "AAA" ) == "A3" );
	CHECK( CompressString::visit( "AAAAAAAAAA" ) == "A10" );

	CHECK( CompressString::visit( "AABBCC" ) == "AABBCC" );
	CHECK( CompressString::visit( "AAABCCDDDD" ) == "A3BCCD4" );
	
}