#include <catch2/catch.hpp>
#include <sstream>
#include "DataStructures\BinaryTree.h"


TEST_CASE( "BinaryTree", "[binarytree]" ) {
	using Node = BinaryTreeNode<int>;
	auto n0 = Node( 0 );
	auto n1 = Node( 1 );
	auto n2 = Node( 2 );
	auto n3 = Node( 3 );
	auto n4 = Node( 4 );
	auto n5 = Node( 5 );
	auto n6 = Node( 6 );
	n0.left = &n1;
	n0.right = &n2;
	n1.left = &n3;
	n3.right = &n6;
	n2.left = &n4;
	n2.right = &n5;
	std::stringstream ss;
	std::function<bool( BinaryTreeNode<int>* )> visit = [&]( BinaryTreeNode<int>* node ) -> bool {
		if (!node) ss << "nullptr";
		else ss << node->data;
		return node;
	};

	/*
		       0
		      / \
		     1   2
		    /   / \
		   3   4   5
		    \
		     6
	*/

	SECTION( "BFS" )
	{
		bfs( &n0, visit );
		REQUIRE( ss.str() == "0123456" );
	}
	SECTION( "DFS preorder" )
	{
		dfs_preorder( &n0, visit );
		REQUIRE( ss.str() == "0136245" );
	}
	SECTION( "DFS inorder" )
	{
		dfs_inorder( &n0, visit );
		REQUIRE( ss.str() == "3610425" );
	}
	SECTION( "DFS postorder" )
	{
		dfs_postorder( &n0, visit );
		REQUIRE( ss.str() == "6314520" );
	}
}


