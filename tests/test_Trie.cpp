#include <catch2/catch.hpp>
#include "Algorithms\Trie.h"

#include <string>
/*
TEST_CASE( "Trie: insert/find string", "[trie]" ) 
{
	using Node = TrieNodeString;

	Node root;
	insert( root, "ab" );
	CHECK_FALSE( find( root, "a" ) );
	CHECK_FALSE( find( root, "b" ) );
	CHECK( find( root, "ab" ) );

	insert( root, "a" );
	CHECK( find( root, "a") );
	CHECK_FALSE( find( root, "b" ) );
	CHECK( find( root, "ab") );
}

TEST_CASE( "Trie: longestCommonPrefix", "[trie]" )
{
	using Node = TrieNodeString;
	std::vector<std::string> words1 = { "aa", "a" };
	std::vector<std::string> words2 = { "a", "aa" };
	CHECK( Solution().longestCommonPrefix( words1 ) == "a" );
	CHECK( Solution().longestCommonPrefix( words2 ) == "a" );

}
*/