#pragma once
#include <vector>

template<typename ItT>
auto reservoir_sampling( ItT begin, ItT end, size_t K )
{
	using namespace std;
	vector<ItT::value_type> res;
	res.reserve( K );

	int n = 1;
	for (auto it = begin; it != end; ++it, ++n)
	{
		if (res.size() < K)
		{
			res.push_back( *it );
			continue;
		}

		const int r = rand() % n;
		if (r < K)
		{
			res[r] = *it;
		}
	}
}