#include "pch.h"
#include "311M_Sparse_Matrix_Multiplication.h"

using namespace Leetcode::LC311M;
using namespace std;

vector<vector<int>> Solution::multiply( vector<vector<int>> A, vector<vector<int>> B ) const
{
	using Sparse = unordered_map<int, unordered_map<int, int>>;
	//                           row->              col->val
	if (A.empty() or B.empty()) return vector<vector<int>>{};

	const auto toSparse = []( const vector<vector<int>>& matrix )
	{
		Sparse res;
		for (size_t r = 0; r < matrix.size(); ++r)
		{
			for (size_t c = 0; c < matrix[0].size(); ++c)
			{
				auto v = matrix[r][c];
				if (v) res[r][c] = v;
			}
		}
		return res;
	};

	const auto ROWS_A = A.size();
	//const auto CA = A[0].size();
	//const auto RB = B.size();
	const auto COLS_B = B[0].size();

	auto res = vector<vector<int>>( ROWS_A, vector<int>( COLS_B, 0 ) );
	auto sa = toSparse( A );
	auto sb = toSparse( B );

	const auto mult = [&]( const Sparse& SA, const Sparse SB )
	{
		/*
			{{1,-5}}, {{12},
					   {-1}}
			sa = {0: {0: 1, 1: 5}}
			sb = {0: {0:12      },
				  1: {0: 5      }}
		*/

		for (auto iterRowA = SA.begin(); iterRowA != SA.end(); ++iterRowA)  //RA
		{
			int rowA = iterRowA->first;
			const auto& columnsA = iterRowA->second;
			for (auto iterColA = columnsA.begin(); iterColA != columnsA.end(); ++iterColA) //CA/RB
			{
				int colA = iterColA->first;
				int valA = iterColA->second;

				auto iterRowSB = SB.find( colA );
				if (iterRowSB == SB.end()) continue;

				int rowB = iterRowSB->first; //same as colA
				const auto& colsB = iterRowSB->second;

				for (auto iterColSB = colsB.begin(); iterColSB != colsB.end(); ++iterColSB)
				{
					int colB = iterColSB->first;
					int valB = iterColSB->second;
					res[rowA][colB] += (valA * valB);
				}
			}
		}
	};

	mult( sa, sb );
	return res;

}