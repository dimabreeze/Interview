#include <catch2/catch.hpp>
#include <sstream>
#include "DataStructures\BinaryTree.h"


/*
TEST_CASE( "BinaryTree", "[binarytree]" ) {
	auto n0 = TreeNode( 0 );
	auto n1 = TreeNode( 1 );
	auto n2 = TreeNode( 2 );
	auto n3 = TreeNode( 3 );
	auto n4 = TreeNode( 4 );
	auto n5 = TreeNode( 5 );
	auto n6 = TreeNode( 6 );
	n0.left = &n1;
	n0.right = &n2;
	n1.left = &n3;
	n3.right = &n6;
	n2.left = &n4;
	n2.right = &n5;
	std::stringstream ss;
	std::function<bool( TreeNode* )> visit = [&]( TreeNode* TreeNode ) -> bool {
		if (!TreeNode) ss << "nullptr";
		else ss << TreeNode->val;
		return TreeNode;
	};

		   //    0
		   //   / \
		   //  1   2
		   // /   / \
		   //3   4   5
		   // \
		   //  6

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
*/

