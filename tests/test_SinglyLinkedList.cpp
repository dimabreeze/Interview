#include <catch2/catch.hpp>
#include "DataStructures\SinglyLinkedList.h"

TEST_CASE( "List: advance", "[list][algo]" ) {
	ListNode* p0 = nullptr;
	REQUIRE( advance( p0, 0 ) == nullptr );
	REQUIRE( advance( p0, 1 ) == nullptr );
	REQUIRE( advance( p0, 2 ) == nullptr );

	p0 = new ListNode( 0 );
	REQUIRE( advance( p0, 0 ) == p0 );
	REQUIRE( advance( p0, 1 ) == nullptr );
	REQUIRE( advance( p0, 2 ) == nullptr );

	ListNode* p1 = new ListNode( 1 );
	p0->next = p1;
	REQUIRE( advance( p0, 0 ) == p0 );
	REQUIRE( advance( p0, 1 ) == p1 );
	REQUIRE( advance( p0, 2 ) == nullptr );

	ListNode* p2 = new ListNode( 2 );
	p1->next = p2;
	REQUIRE( advance( p0, 0 ) == p0 );
	REQUIRE( advance( p0, 1 ) == p1 );
	REQUIRE( advance( p0, 2 ) == p2 );

	delete p0, delete p1, delete p2;
}

TEST_CASE( "List: reverse", "[list][algo]" )
{
	ListNode* p0 = nullptr;
	CHECK( reverse( p0 ) == nullptr );

	p0 = new ListNode( 0 );
	CHECK( reverse( p0 ) == p0 );
	REQUIRE( p0 != nullptr );
	CHECK( p0->next == nullptr );

	ListNode* p1 = new ListNode( 1 );
	p0->next = p1; // p0 -> p1 -> nullptr
	CHECK( reverse( p0 ) == p1 ); // p1 -> p0 -> nullptr
	REQUIRE( p0 != nullptr );
	CHECK( p0->next == nullptr );
	REQUIRE( p1 != nullptr );
	CHECK( p1->next == p0 );

	ListNode* p2 = new ListNode( 2 );
	p0->next = p2; // p1 -> p0 -> p2 -> nullptr
	CHECK( reverse( p1 ) == p2 ); // p2->p0->p1 -> nullptr
	REQUIRE( p0 != nullptr );
	CHECK( p0->next == p1 );
	REQUIRE( p1 != nullptr );
	CHECK( p1->next == nullptr );
	REQUIRE( p2 != nullptr );
	CHECK( p2->next == p0 );

	delete p0, delete p1, delete p2;
}

TEST_CASE( "List: reverse recursive", "[list][algo]" )
{
	ListNode* p0 = nullptr;
	CHECK( reverse_recursive( p0 ) == nullptr );

	p0 = new ListNode( 0 );
	CHECK( reverse_recursive( p0 ) == p0 );
	REQUIRE( p0 != nullptr );
	CHECK( p0->next == nullptr );

	ListNode* p1 = new ListNode( 1 );
	p0->next = p1; // p0 -> p1 -> nullptr
	CHECK( reverse_recursive( p0 ) == p1 ); // p1 -> p0 -> nullptr
	REQUIRE( p0 != nullptr );
	CHECK( p0->next == nullptr );
	REQUIRE( p1 != nullptr );
	CHECK( p1->next == p0 );

	ListNode* p2 = new ListNode( 2 );
	p0->next = p2; // p1 -> p0 -> p2 -> nullptr
	CHECK( reverse_recursive( p1 ) == p2 ); // p2->p0->p1 -> nullptr
	REQUIRE( p0 != nullptr );
	CHECK( p0->next == p1 );
	REQUIRE( p1 != nullptr );
	CHECK( p1->next == nullptr );
	REQUIRE( p2 != nullptr );
	CHECK( p2->next == p0 );

	delete p0, delete p1, delete p2;
}



TEST_CASE( "List: reverse_range", "[list][algo]" )
{
	ListNode* p0 = nullptr;
	CHECK( reverse_range( p0 ) == nullptr );

	p0 = new ListNode( 0 );
	CHECK( reverse_range( p0 ) == p0 );
	REQUIRE( p0 != nullptr );
	CHECK( p0->next == nullptr );

	ListNode* p1 = new ListNode( 1 );
	p0->next = p1; // p0 -> p1 -> nullptr
	CHECK( reverse_range( p0, p1 ) == p0 ); // p0 -> p1 -> nullptr
	REQUIRE( p0 != nullptr );
	REQUIRE( p1 != nullptr );
	CHECK( p0->next == p1 );
	CHECK( p1->next == nullptr );

	ListNode* p2 = new ListNode( 2 );
	p1->next = p2; // p0 -> p1 -> p2 -> nullptr
	CHECK( reverse_range( p0 ) == p2 ); // p2->p1->p0 -> nullptr
	REQUIRE( p0 != nullptr );
	REQUIRE( p1 != nullptr );
	REQUIRE( p2 != nullptr );
	CHECK( !p0->next );
	CHECK( p1->next == p0 );
	CHECK( p2->next == p1 );

	CHECK( reverse_range( p2, p0 ) == p1 ); // p1->p2->p0 -> nullptr
	REQUIRE( p0 != nullptr );
	REQUIRE( p1 != nullptr );
	REQUIRE( p2 != nullptr );
	CHECK( p0->next == nullptr);
	CHECK( p1->next == p2 );
	CHECK( p2->next == p0 );

	delete p0, delete p1, delete p2;
}


TEST_CASE( "List: Merge two sorted", "[list][algo]" )
{
	ListNode* NODE_NULL = nullptr;
	CHECK( merge_two_sorted( NODE_NULL, NODE_NULL ) == NODE_NULL );

	ListNode* p0 = new ListNode( 0 );
	REQUIRE( merge_two_sorted( p0, NODE_NULL ) == p0 );
	CHECK( p0->next == NODE_NULL );
	REQUIRE( merge_two_sorted( NODE_NULL, p0 ) == p0 );
	CHECK( p0->next == NODE_NULL );


	ListNode* p1 = new ListNode( 1 );
	p0->next = p1;

	REQUIRE( merge_two_sorted( p0, NODE_NULL ) == p0 );
	CHECK( p0->next == p1 );
	CHECK( p1->next == NODE_NULL );
	REQUIRE( merge_two_sorted( NODE_NULL, p0 ) == p0 );
	CHECK( p0->next == p1 );
	CHECK( p1->next == NODE_NULL );
	
	delete p0, delete p1;

	ListNode* n0 = new ListNode{ 0 };
	ListNode* n1 = new ListNode{ 1 }; n0->next = n1;
	ListNode* n2 = new ListNode{ 2 }; n1->next = n2;
	ListNode* n3 = new ListNode{ 3 }; n2->next = n3;
	ListNode* n4 = new ListNode{ 4 }; n3->next = n4;
	ListNode* n5 = new ListNode{ 5 }; 
	ListNode* n6 = new ListNode{ 6 }; n5->next = n6;

	REQUIRE( merge_two_sorted( n5, n0 ) == n0 );
	CHECK( n0->next == n1 );
	CHECK( n1->next == n2 );
	CHECK( n2->next == n3 );
	CHECK( n3->next == n4 );
	CHECK( n4->next == n5 );
	CHECK( n5->next == n6 );
	CHECK( n6->next == NODE_NULL );

	delete n0, delete n1, delete n2, delete n3, delete n4, delete n5, delete n6;
}


TEST_CASE( "List: Median", "[list][algo]" )
{
	ListNode* NODE_NULL = nullptr;

	REQUIRE( median( NODE_NULL ) == NODE_NULL );

	ListNode* n0 = new ListNode{ 0 };
	REQUIRE( median( n0 ) == n0 );
	
	ListNode* n1 = new ListNode{ 1 }; n0->next = n1;
	REQUIRE( median( n0 ) == n1 );

	ListNode* n2 = new ListNode{ 2 }; n1->next = n2;
	REQUIRE( median( n0 ) == n1 );

	ListNode* n3 = new ListNode{ 3 }; n2->next = n3;
	REQUIRE( median( n0 ) == n2 );

	ListNode* n4 = new ListNode{ 4 }; n3->next = n4;
	REQUIRE( median( n0 ) == n2 );

	ListNode* n5 = new ListNode{ 5 }; n4->next = n5;
	REQUIRE( median( n0 ) == n3 );

	ListNode* n6 = new ListNode{ 6 }; n5->next = n6;
	REQUIRE( median( n0 ) == n3 );

	delete n0, delete n1, delete n2, delete n3, delete n4, delete n5, delete n6;
}


/*
TEST_CASE( "List: Merge two one-by-one", "[list][algo]" )
{
	using Node = Node<int>;
	Node* NODE_NULL = nullptr;

	REQUIRE( merge_two_one_by_one( NODE_NULL, NODE_NULL ) == NODE_NULL );

	Node* n0 = new Node{ 0 };
	REQUIRE( merge_two_one_by_one( NODE_NULL, n0 ) == n0 );
	REQUIRE( merge_two_one_by_one( n0, NODE_NULL ) == n0 );

	Node* n1 = new Node{ 1 };
	REQUIRE( merge_two_one_by_one( n0, n1 ) == n0 );
	REQUIRE( n0->next == n1 );
	REQUIRE( n1->next == nullptr );

	Node* n2 = new Node{ 2 };
	REQUIRE( merge_two_one_by_one( n0, n2 ) == n0 );
	//n0 > n2 > n1
	REQUIRE( n0->next == n2 );
	REQUIRE( n2->next == n1 );
	REQUIRE( n1->next == nullptr ); 

	Node* n3 = new Node{ 3 };
	Node* n4 = new Node{ 4 }; n3->next = n4;
	//n3>n4  and  n0>n2>n1
	REQUIRE( merge_two_one_by_one( n3, n0 ) == n3 );   
	//n3>n0>n4>n2>n1
	REQUIRE( n3->next == n0 );
	REQUIRE( n0->next == n4 );
	REQUIRE( n4->next == n2 );
	REQUIRE( n2->next == n1 );
	REQUIRE( n2->next == nullptr );

	delete n0, delete n1, delete n2, delete n3, delete n4;
}
*/