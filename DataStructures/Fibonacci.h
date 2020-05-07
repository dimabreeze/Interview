#pragma once
#include <vector>

namespace Algorithms
{
	int fib_recursive( int n )
	{
		if (n == 0) return 0;
		if (n == 1) return 1;

		static std::vector<int> cache;
		if (cache.size() < n) cache.resize( n, 0 );

		int& value = cache[n - 1];
		if (value) return value;

		value = fib_recursive( n - 1 ) + fib_recursive( n - 2 );
		return value;
	}

	int fib_iterative( int n )
	{
		if (n == 0) return 0;
		if (n == 1) return 1;

		static std::vector<int> cache;
		if (cache.size() < n) cache.resize( n, 0 );

		int& value = cache[n - 1];
		if (value) return value;

		value = fib_recursive( n - 1 ) + fib_recursive( n - 2 );
		return value;
	}
}