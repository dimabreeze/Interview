#pragma once
#include <vector>

namespace Leetcode
{
	namespace LC311M //311M_Sparse_Matrix_Multiplication
	{
		/*
		https://leetcode.com/problems/sparse-matrix-multiplication/

		Given two sparse matrices A and B, return the result of AB.

		You may assume that A's column number is equal to B's row number.

		Example:

		Input:

		A = [
		  [ 1, 0, 0],
		  [-1, 0, 3]
		]

		B = [
		  [ 7, 0, 0 ],
		  [ 0, 0, 0 ],
		  [ 0, 0, 1 ]
		]

		Output:

			 |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
		AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
						  | 0 0 1 |

Submission: 
https://leetcode.com/submissions/detail/335303034/
(Runtime: 8 ms, faster than 94.24% of C++ online submissions for Sparse Matrix Multiplication.
Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Sparse Matrix Multiplication.)

		*/
		class Solution {
		public:
			std::vector<std::vector<int>> multiply( std::vector<std::vector<int>> A, std::vector<std::vector<int>> B ) const;
		};
	}
}

