#include "pch.h"
#include "76M_Minimum_Window_Substring.h"

namespace
{
	std::ostream& operator<<( std::ostream& os, std::unordered_map<char, int> inputdata )
	{
		std::map<char, int> data( inputdata.begin(), inputdata.end() );
		os << "{";
		for (auto i = data.begin(), e = data.end(); i != e; ++i)
		{
			if (i != data.begin()) std::cout << ",";
			std::cout << i->first << i->second;
		}
		os << "}";
		return os;
	}

	int len( int l, int r ) {
		return r - l + 1;
	};
	int len( std::pair<int, int> p) {
		return len(p.first, p.second);
	};

	int count( char c, const std::unordered_map<char, int>& freq ) {
		auto iter = freq.find( c );
		if (iter == freq.end()) return 0;
		return iter->second;
	};

	std::string substring( std::string s, size_t l, size_t r ) {
		std::string ans;
		for (; l >= 0 and l <= r and r < s.size(); ++l)
		{
			ans += s[l];
		}
		return ans;
	};

}

std::string Solution76::minWindow( std::string s, std::string t ) const {
	std::unordered_map<char, int> map;
	for (auto c : t) ++map[c];

	size_t counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
	while (end < s.size()) {
		const auto c_end   = s[end++];
		if (map[c_end]-- > 0)
		{
			--counter; //in T
		}
		while (counter == 0) { //valid
			if (end - begin < d)
			{
				head = begin;
				d = end - head;
			}
			if (map[s[begin++]]++ == 0)
			{
				++counter; //make it invalid
			}
		}
	}
	return d == INT_MAX ? "" : s.substr( head, d );
}