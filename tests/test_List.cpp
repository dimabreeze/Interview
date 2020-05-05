#include <catch2/catch.hpp>
#include "DataStructures\SinglyLinkedList.h"

TEST_CASE( "List: advance", "[list]" ) {
	using Node = Node<int>;
	Node* p0 = nullptr;
	REQUIRE( advance( p0, 0 ) == nullptr );
	REQUIRE( advance( p0, 1 ) == nullptr );
	REQUIRE( advance( p0, 2 ) == nullptr );

	p0 = new Node( 0 );
	REQUIRE( advance( p0, 0 ) == p0 );
	REQUIRE( advance( p0, 1 ) == nullptr );
	REQUIRE( advance( p0, 2 ) == nullptr );

	Node* p1 = new Node( 1 );
	p0->next = p1;
	REQUIRE( advance( p0, 0 ) == p0 );
	REQUIRE( advance( p0, 1 ) == p1 );
	REQUIRE( advance( p0, 2 ) == nullptr );

	Node* p2 = new Node( 2 );
	p1->next = p2;
	REQUIRE( advance( p0, 0 ) == p0 );
	REQUIRE( advance( p0, 1 ) == p1 );
	REQUIRE( advance( p0, 2 ) == p2 );
}

TEST_CASE( "List: reverse", "[list]" )
{
	using Node = Node<int>;

	Node* p0 = nullptr;
	CHECK( reverse( p0 ) == nullptr );

	p0 = new Node( 0 );
	CHECK( reverse( p0 ) == p0 );
	REQUIRE( p0 != nullptr );
	CHECK( p0->next == nullptr );

	Node* p1 = new Node( 1 );
	p0->next = p1; // p0 -> p1 -> nullptr
	CHECK( reverse( p0 ) == p1 ); // p1 -> p0 -> nullptr
	REQUIRE( p0 != nullptr );
	CHECK( p0->next == nullptr );
	REQUIRE( p1 != nullptr );
	CHECK( p1->next == p0 );

	Node* p2 = new Node( 2 );
	p0->next = p2; // p1 -> p0 -> p2 -> nullptr
	CHECK( reverse( p1 ) == p2 ); // p2->p0->p1 -> nullptr
	REQUIRE( p0 != nullptr );
	CHECK( p0->next == p1 );
	REQUIRE( p1 != nullptr );
	CHECK( p1->next == nullptr );
	REQUIRE( p2 != nullptr );
	CHECK( p2->next == p0 );
}