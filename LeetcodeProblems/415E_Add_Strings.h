#pragma once
#include <string>

namespace Leetcode
{
	namespace LC451E
	{
/*

https://leetcode.com/problems/add-strings/

Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.

Submisssion: https://leetcode.com/submissions/detail/335464759/
*/
		class Solution {
		public:
			std::string addStrings( std::string s1, std::string s2 );
		};
	}
}