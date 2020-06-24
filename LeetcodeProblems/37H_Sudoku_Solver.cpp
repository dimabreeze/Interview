#include "pch.h"
#include "37H_Sudoku_Solver.h"


using namespace Leetcode::LC37H;
using namespace std;

namespace
{
	using Value = uint8_t;
	struct SudokuSolver
	{
		SudokuSolver( vector<vector<char>>& Board )
			: board_main_ref( Board )
			, board_row( 9 )
			, board_col( 9 )
			, board_box( 9 )
		{
			if (board_main_ref.size() != SIZE)
				throw std::exception( "Board size doesn't match declared size" );

			for (size_t i = 0; i < SIZE; ++i)
			{
				if (board_main_ref[i].size() != SIZE)
					throw std::exception( "Board size doesn't match declared size" );
			}

			for (size_t row = 0; row < SIZE; ++row)
			{
				for (size_t col = 0; col < SIZE; ++col)
				{
					const auto val = board_main_ref[row][col];
					if (val == '.') continue;

					const auto box = rc_to_sid( row, col );
					auto& board_row_val_ref = board_row[row];
					auto& board_col_val_ref = board_col[col];
					auto& board_bow_val_ref = board_box[box];

					const Value num = val - '0';
					board_row_val_ref = setbit( board_row_val_ref, num );
					board_col_val_ref = setbit( board_col_val_ref, num );
					board_bow_val_ref = setbit( board_bow_val_ref, num );
				}
			}
		}

		void solve()
		{
			backtrack( 0, 0 );
		}

	private:
		static size_t rc_to_sid( size_t r, size_t c )
		{
			return (r / SQSIZE) * SQSIZE + (c / SQSIZE);
			//     |___box row__________|  |_box col__|
		};

		template<typename T>
		static bool getbit( T num, uint8_t bit )
		{
			T res = num & (static_cast<T>(1) << bit);
			bool bres = res;
			return bres;
		}

		template<typename T>
		static T setbit( T num, uint8_t bit )
		{
			return (num |= (static_cast<T>(1) << bit));
		}
		
		template<typename T>
		static T clearbit( T num, uint8_t bit )
		{
			return (num &= ~(static_cast<T>(1) << bit));
		}

		bool backtrack( size_t row, size_t col, size_t level = 0 )
		{
			if (row >= SIZE)
				return true; // All done, well done

			auto next_col =       (col + 1) % SIZE;
			auto next_row = row + (col + 1) / SIZE;

			// Continue if current cell contains fixed value
			if (board_main_ref[row][col] != '.')
				return backtrack( next_row, next_col, level + 1 );

			const auto box = rc_to_sid( row, col );
			for (Value number = 1; number <= SIZE; ++number)
			{
				auto& board_row_val_ref = board_row[row];
				auto& board_col_val_ref = board_col[col];
				auto& board_box_val_ref = board_box[box];

				// check
				const bool ok_to_add_r = !getbit( board_row_val_ref, number );
				const bool ok_to_add_c = !getbit( board_col_val_ref, number );
				const bool ok_to_add_s = !getbit( board_box_val_ref, number );
				const bool ok_to_add = ok_to_add_r and ok_to_add_c and ok_to_add_s;
				if (!ok_to_add)
					continue;

				// add
				auto br_backup = board_row_val_ref;
				auto bc_backup = board_col_val_ref;
				auto bs_backup = board_box_val_ref;
				board_main_ref[row][col] = number + '0';
				board_row_val_ref = setbit( board_row_val_ref, number );
				board_col_val_ref = setbit( board_col_val_ref, number );
				board_box_val_ref = setbit( board_box_val_ref, number );

				// backtrack further
				if (backtrack( next_row, next_col, level + 1 ))
					return true;

				//revert
				board_main_ref[row][col] = '.';
				board_row_val_ref = br_backup;
				board_col_val_ref = bc_backup;
				board_box_val_ref = bs_backup;
			}
			return false;
		};

	private:
		const static size_t SIZE = 9;
		const static size_t SQSIZE = 3;

		vector<vector<char>>& board_main_ref;
		vector<uint16_t> board_row;
		vector<uint16_t> board_col;
		vector<uint16_t> board_box;
	};
};

void Solution::solveSudoku( vector<vector<char>>& board_main_ref ) 
{
	SudokuSolver( board_main_ref ).solve();
};