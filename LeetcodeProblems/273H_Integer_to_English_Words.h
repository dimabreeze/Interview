#pragma once
namespace Leetcode
{
	namespace LC273H
	{
/*
273. Integer to English Words
https://leetcode.com/problems/integer-to-english-words/

Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

Example 1:

Input: 123
Output: "One Hundred Twenty Three"
Example 2:

Input: 12345
Output: "Twelve Thousand Three Hundred Forty Five"
Example 3:

Input: 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
Example 4:

Input: 1234567891
Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"


Submission: https://leetcode.com/submissions/detail/335733308/
Runtime: 4 ms, faster than 83.19% of C++ online submissions for Integer to English Words.
Memory Usage: 6.6 MB, less than 100.00% of C++ online submissions for Integer to English Words.
*/
		class Solution {
		public:
			std::string numberToWords( int num ) const;
		};

	}
}
