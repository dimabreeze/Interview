#include <catch2/catch.hpp>
#include "DataStructures/BitManipulation.h"

TEST_CASE( "Bit Manipulation: clear least significant bit", "[algo][bits]" )
{
	CHECK( clear_ls_bit( 0b00 ) == clear_ls_bit( 0b01 ) );
	CHECK( clear_ls_bit( 0b10 ) == clear_ls_bit( 0b11 ) );
	CHECK( clear_ls_bit( 0b1111110 ) == 0b1111110 );
	CHECK( clear_ls_bit( 0b1010101 ) == 0b1010100 );
}


TEST_CASE( "Bit Manipulation: get bit", "[algo][bits]" )
{
	CHECK( getbit( 0b0, 0 ) == 0 );
	CHECK( getbit( 0b1, 0 ) == 1 );
	CHECK( getbit( 0b10, 1 ) == 1 );
	CHECK( getbit( 0b001000, 3 ) == 1 );
}

TEST_CASE( "Bit Manipulation: count bits", "[algo][bits]" )
{
	REQUIRE( countsetbits( 0b0 ) == 0 );
	REQUIRE( countsetbits( 0b1 ) == 1 );
	REQUIRE( countsetbits( 0b0110001101 ) == 5 );

	REQUIRE( countsetbits_Brian_Kernighan( 0b0 ) == countsetbits( 0b0 ) );
	REQUIRE( countsetbits_Brian_Kernighan( 0b1 ) == countsetbits( 0b1 ) );
	REQUIRE( countsetbits_Brian_Kernighan( 0b0110001101 ) == countsetbits( 0b0110001101 ) );

	REQUIRE( countsetbits_lookup_table( 0b0 ) == countsetbits_Brian_Kernighan( 0b0 ) );
	REQUIRE( countsetbits_lookup_table( 0b1 ) == countsetbits_Brian_Kernighan( 0b1 ) );
	REQUIRE( countsetbits_lookup_table( 0b0110001101 ) == countsetbits_Brian_Kernighan( 0b0110001101 ) );
}