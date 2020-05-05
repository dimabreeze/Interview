#pragma once

namespace Utils
{
	template <typename T>
	T swap_endian( T u )
	{
		static_assert (CHAR_BIT == 8, "CHAR_BIT != 8");
		union
		{
			T u;
			unsigned char u8[sizeof( T )];
		} source, dest;

		source.u = u;
		for (size_t k = 0; k < sizeof( T ); k++)
			dest.u8[k] = source.u8[sizeof( T ) - k - 1];
		return dest.u;
	}
	// int i = swap_endian<int>( 65 );

	/*
	int num = 1;
	if(*(char *)&num == 1)
	{
		printf("\nLittle-Endian\n");
	}
	else
	{
		printf("Big-Endian\n");
	}
	*/


	int negate( int a ) {
		if (a < 0)
			a = ~(-a) + 1;
		return a;
	}

}