#include "pch.h"
#include "415E_Add_Strings.h"

using namespace Leetcode::LC451E;
using namespace std;

string Solution::addStrings( string s1, string s2 ) {
	const auto& minS = s1.size() < s2.size() ? s1 : s2;
	auto& maxS = s1.size() < s2.size() ? s2 : s1;

	int carry = 0;
	auto iMin = minS.rbegin();
	auto iMax = maxS.rbegin();
	for (auto end = minS.rend(); iMin != end; ++iMin, ++iMax)
	{
		*iMax += carry + *iMin - '0';
		carry = 0;
		if (*iMax > '9')
		{
			*iMax -= 10;
			++carry;
		}
	}
	for (auto end = maxS.rend(); iMax != end; ++iMax)
	{
		*iMax += carry;
		carry = 0;
		if (*iMax > '9')
		{
			*iMax -= 10;
			++carry;
		}
	}
	/*
	if (carry) return string( 1, '0' + carry ) + maxS;
	else return maxS;
	*/

	if (!carry) return std::move( maxS );

	string ans( maxS.size() + 1, '0' + carry );
	for (size_t i = 1; i < ans.size(); ++i)
	{
		ans[i] = maxS[i - 1];
	}
	return std::move( ans );
}