#pragma once
#include <vector>

template<typename R, typename T>
R dot_product( const std::vector<T>& v1, const std::vector<T> v2 )
{
	const auto& smaller = v1.size() < v2.size() ? v1 : v2;
	const auto& larger  = v2.size() < v1.size() ? v2 : v1;

	R product = 0;
	for (size_t i = 0; i < smaller.size(); ++i)
	{
		product += smaller[i] * larger[i];
	}
	return product;
}

template<typename T>
double euclidian_len( const std::vector<T>& v )
{
	return sqrt( dot_product<double>( v, v ) );
}

template<typename T>
double cos( const std::vector<T>& v1, const std::vector<T> v2 )
{
	auto product = dot_product<double>( v1, v2 );
	auto euclidian_len1 = euclidian_len( v1 );
	auto euclidian_len2 = euclidian_len( v2 );

	if (euclidian_len1 == 0 or euclidian_len2 == 0) 
		return 0;
	return product / (euclidian_len( v1 ) * euclidian_len( v2 ));
}

