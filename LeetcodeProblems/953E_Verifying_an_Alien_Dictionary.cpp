#include "pch.h"
#include "953E_Verifying_an_Alien_Dictionary.h"
#include <unordered_map>

using namespace std;
using namespace Leetcode::LC953E;


bool Solution::isAlienSorted( vector<string> words, string order ) const {
	unordered_map<char, int> positions; /*letter->order*/
	for (int pos = 0; pos < order.size(); ++pos)
	{
		positions[order[pos]] = pos;
	}

	const auto less = [&positions]( const string& lhs, const string& rhs )
	{
		const auto sl = lhs.size();
		const auto sr = rhs.size();

		for (int i = 0; i < min( sl, sr ); ++i)
		{
			if (lhs[i] == rhs[i]) continue;
			return positions[lhs[i]] < positions[rhs[i]];
		}

		return sl < sr;
	};

	for (int pos = 1; pos < words.size(); ++pos)
	{
		if (less(words[pos],words[pos - 1])) return false;
	}

	return true;
}