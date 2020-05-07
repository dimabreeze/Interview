#include "pch.h"
#include "273H_Integer_to_English_Words.h"


using namespace std;
using namespace Leetcode::LC273H;

namespace
{
	string toword( int n )
	{
		const static map<int, string> dict19
		{
			{0, ""},
			{1, "One"},
			{2, "Two"},
			{3, "Three"},
			{4, "Four"},
			{5, "Five"},
			{6, "Six"},
			{7, "Seven"},
			{8, "Eight"},
			{9, "Nine"},
			{10, "Ten"},
			{11, "Eleven"},
			{12, "Twelve"},
			{13, "Thirteen"},
			{14, "Fourteen"},
			{15, "Fifteen"},
			{16, "Sixteen"},
			{17, "Seventeen"},
			{18, "Eighteen"},
			{19, "Nineteen"}
		};
		if (n <= 19) return dict19.find( n )->second;
		//      0..19 (incl) - all covered

		const static map<int, string> dict20_90
		{
			{20, "Twenty"},
			{30, "Thirty"},
			{40, "Forty"},
			{50, "Fifty"},
			{60, "Sixty"},
			{70, "Seventy"},
			{80, "Eighty"},
			{90, "Ninety"}
		};
		if (n < 100)
		{
			int r = n % 10;
			if (r) return dict20_90.find( n / 10 * 10 )->second + " " + toword( r );
			else   return dict20_90.find( n / 10 * 10 )->second;
		}
		//                      Twenty..ninety              one....nine
				// 21

		if (n < 1000)
		{
			int r = n % 100;
			if (r) return toword( n / 100 ) + " Hundred " + toword( r );
			else   return toword( n / 100 ) + " Hundred";
		}

		const static map<int, string> dict1000{
			{1000, "Thousand"},
			{1000000, "Million"},
			{1000000000, "Billion"}
		};

		for (auto iter = dict1000.rbegin(), end = dict1000.rend(); iter != end; ++iter)
		{
			int d = n / iter->first; //how many 1000000000, 1000000, 1000's
			int r = n % iter->first; //reminder

			if (d > 0)
			{
				if (r) return toword( d ) + " " + iter->second + " " + toword( r );
				else   return toword( d ) + " " + iter->second;
			}
		}
		return "";
	}
}

string Solution::numberToWords( int num ) const {
	if (num == 0) return "Zero";
	return toword( num );
}
