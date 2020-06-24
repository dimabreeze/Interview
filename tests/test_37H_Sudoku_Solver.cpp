#include <catch2/catch.hpp>
#include "LeetcodeProblems\37H_Sudoku_Solver.h"

using namespace Leetcode::LC37H;
using namespace std;

TEST_CASE( "Leetcode #37: Sudoku Solver", "[leetcode][hard]" )
{
	using namespace std;

	//LC Tests:
	vector<vector<char>> sudoku {
		//      | 0 | 1 | 2 | | 3 | 4 | 5 | | 6 | 7 | 8 | < r
		/* 0 */{ '5','3','.',  '.','7','.',  '.','.','.' },
		/* 1 */{ '6','.','.',  '1','9','5',  '.','.','.' },
		/* 2 */{ '.','9','8',  '.','.','.',  '.','6','.' },

		/* 3 */{ '8','.','.',  '.','6','.',  '.','.','3' },
		/* 4 */{ '4','.','.',  '8','.','3',  '.','.','1' },
		/* 5 */{ '7','.','.',  '.','2','.',  '.','.','6' },

		/* 6 */{ '.','6','.',  '.','.','.',  '2','8','.' },
		/* 7 */{ '.','.','.',  '4','1','9',  '.','.','5' },
		/* 8 */{ '.','.','.',  '.','8','.',  '.','7','9' }
		// ^
		// c
	};
	Solution().solveSudoku( sudoku );
	CHECK( sudoku == vector<vector<char>> {
		//      | 0 | 1 | 2 | | 3 | 4 | 5 | | 6 | 7 | 8 | < r
		/* 0 */{ '5','3','4',  '6','7','8',  '9','1','2' },
		/* 1 */{ '6','7','2',  '1','9','5',  '3','4','8' },
		/* 2 */{ '1','9','8',  '3','4','2',  '5','6','7' },

		/* 3 */{ '8','5','9',  '7','6','1',  '4','2','3' },
		/* 4 */{ '4','2','6',  '8','5','3',  '7','9','1' },
		/* 5 */{ '7','1','3',  '9','2','4',  '8','5','6' },

		/* 6 */{ '9','6','1',  '5','3','7',  '2','8','4' },
		/* 7 */{ '2','8','7',  '4','1','9',  '6','3','5' },
		/* 8 */{ '3','4','5',  '2','8','6',  '1','7','9' }
		// ^
		// c
	} );
}