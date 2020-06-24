#include <catch2/catch.hpp>
#include <sstream>
#include "Algorithms\BinaryTree.h"

using namespace std;
using namespace std::placeholders;

struct Visit
{
	void visit( TreeNode* node )
	{
		if (node)
			ss << node->val;
		else
			ss << "null";
	}
	string getString() const
	{
		return ss.str();
	}

	void reset() {
		ss.str( "" );
	}
private:
	ostringstream ss;
};

TEST_CASE( "BST: insert", "[BST][BinaryTree]" )
{
	Visit v;
	auto visit = std::bind( &Visit::visit, &v, _1 );

	TreeNode* root = insertBST_iterative( nullptr, 5 );;
	insertBST_recursive( root, 9 );
	insertBST_recursive( root, 3 );
	insertBST_iterative( root, 4 );
	insertBST_recursive( root, 0 );
	insertBST_iterative( root, 6 );
	insertBST_recursive( root, 7 );
	insertBST_iterative( root, 2 );
	insertBST_iterative( root, 8 );
	insertBST_recursive( root, 1 );
	REQUIRE( root != nullptr );

	SECTION( "Insert" )
	{
		dfs_inorder( root, visit );
		CHECK( v.getString() == "0123456789" );
	}

	SECTION( "Delete" )
	{
		deleteNode( root, 0 );
		deleteNode( root, 9 );
		dfs_inorder( root, visit );
		CHECK( v.getString() == "12345678" );
	}
}

TEST_CASE( "BinaryTree: traversal", "[BinaryTree][traversal]" ) {

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

		   //    0
		   //   / \
		   //  1   2
		   // /   / \
		   //3   4   5
		   // \
		   //  6

	Visit v;
	auto visit = std::bind( &Visit::visit, &v, _1);
	SECTION( "BFS" )
	{

		bfs( &n0, visit );
		CHECK( v.getString() == "0123456" );
	}
	SECTION( "DFS preorder" )
	{
		dfs_preorder( &n0, visit );
		CHECK( v.getString() == "0136245" );
	}
	SECTION( "DFS inorder" )
	{
		dfs_inorder( &n0, visit );
		CHECK( v.getString() == "3610425" );
	}
	SECTION( "DFS postorder" )
	{
		dfs_postorder( &n0, visit );
		CHECK( v.getString() == "6314520" );
	}
}

TEST_CASE( "BinaryTree: is_binarytree", "[BinaryTree]" ) {
	struct RAII_helper
	{
		RAII_helper( vector<TreeNode*>& arr ) : mref( arr )
		{}

		~RAII_helper()
		{
			for (auto node : mref) delete node;
		}
	private:
		vector<TreeNode*>& mref;
	};

	SECTION( "binary tree" )
	{
		auto n0 = new TreeNode( 0 );
		auto n1 = new TreeNode( 1 );
		auto n2 = new TreeNode( 2 );
		auto n3 = new TreeNode( 3 );
		auto n4 = new TreeNode( 4 );
		auto n5 = new TreeNode( 5 );
		auto n6 = new TreeNode( 6 );
		n0->left = n1;
		n0->right = n2;
		n1->left = n3;
		n3->right = n6;
		n2->left = n4;
		n2->right = n5;

		vector<TreeNode*> arr{ n0, n1, n2, n3, n4, n5, n6 };
		RAII_helper helper( arr );
		CHECK( is_binarytree( arr ) == true );
	}
	SECTION( "cycle to root" )
	{
		auto n0 = new TreeNode( 0 );
		auto n1 = new TreeNode( 1 );
		auto n2 = new TreeNode( 2 );
		auto n3 = new TreeNode( 3 );
		n0->left = n1;
		n1->left = n2;
		n2->left = n0;

		vector<TreeNode*> arr{ n0, n1, n2, n3 };
		RAII_helper helper( arr );
		CHECK( is_binarytree( arr ) == false );
	}
	SECTION( "cycle to root 2" )
	{
		auto n0 = new TreeNode( 0 );
		auto n1 = new TreeNode( 1 );
		auto n2 = new TreeNode( 2 );
		auto n3 = new TreeNode( 3 );
		n0->left = n1;
		n1->right = n0;

		vector<TreeNode*> arr{ n0, n1 };
		RAII_helper helper( arr );
		CHECK( is_binarytree( arr ) == false );
	}

	SECTION( "multiple roots" )
	{
		auto n0 = new TreeNode( 0 );
		auto n1 = new TreeNode( 1 );

		vector<TreeNode*> arr{ n0, n1 };
		RAII_helper helper( arr );
		CHECK( is_binarytree( arr ) == false );
	}
}