#include "pch.h"
#include "989E_Add_to_Array_Form_of_Integer.h"

using namespace Leetcode::LC989E;
using namespace std;

vector<int> Solution::addToArrayForm( vector<int> A, int k ) {
	using VI = vector<int>;

	int carry = 0;
	auto i = A.rbegin();
	for (auto rend = A.rend(); i != rend; ++i)
	{
		*i += carry + k % 10;
		carry = 0;
		k /= 10;
		if (*i > 9)
		{
			*i -= 10;
			++carry;
		}
	}

	if (k == 0)
	{
		if (!carry) return A;
		else
		{
			VI ans( A.size() + 1, 1 );
			copy( A.begin(), A.end(), next( ans.begin(), 1 ) );
			return ans;
		}
	}

	VI vk;
	k += carry;
	carry = 0;
	while (k > 0)
	{
		vk.push_back( k % 10 );
		k /= 10;
	}

	VI ans( vk.rbegin(), vk.rend() );
	for (auto n : A)
	{
		ans.push_back( n );
	}
	return ans;
}
