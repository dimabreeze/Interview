#include <catch2/catch.hpp>
#include <string>
#include <vector>
#include "LeetcodeProblems\953E_Verifying_an_Alien_Dictionary.h"

using namespace Leetcode::LC953E;

TEST_CASE( "Leetcode #953: Verifying an Alien Dictionary", "[leetcode][easy]" )
{
	using namespace std;
	Solution s;
	//LC Tests:
	CHECK( s.isAlienSorted( { "hello","leetcode" }, "hlabcdefgijkmnopqrstuvwxyz" ) == true );
	CHECK( s.isAlienSorted( { "word","world","row" }, "worldabcefghijkmnpqstuvxyz" ) == false );
	CHECK( s.isAlienSorted( { "apple","app" }, "abcdefghijklmnopqrstuvwxyz" ) == false );
	CHECK( s.isAlienSorted( { "ubg","kwh" }, "qcipyamwvdjtesbghlorufnkzx" ) == true );
}
