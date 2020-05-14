#pragma once

template<typename T>
T clear_ls_bit( T t )
{
	const static T T0{ 0 };
	return t & (~T0 << 1);
//              \_/
//              all
//              ones
}


template<typename T>
char getbit( T t, unsigned int bitn )
{
	return t & (1 << bitn) >> bitn;
}

template<typename T>
unsigned int countsetbits( T t ) //counts 1's
{
	unsigned int ans = 0;
	while (t)
	{
		ans += t & 1;
		t >>= 1;
	}
	return ans;
}

template<typename T>
unsigned int countsetbits_Brian_Kernighan( T t )
{
/*
Subtracting 1 from a decimal number flips all the bits after the rightmost set bit(which is 1) 
including the rightmost set bit.
for example :
10 in binary is 00001010
9 in binary is 00001001
8 in binary is 00001000
7 in binary is 00000111
So if we subtract a number by 1 and do bitwise & with itself (n & (n-1)), we unset the rightmost set bit. 
If we do n & (n-1) in a loop and count the no of times loop executes we get the set bit count.
The beauty of this solution is the number of times it loops is equal to the number of set bits in a given integer.
*/
	unsigned int ans = 0;
	while (t and ++ans) {
		t &= (t - 1);
	}
	return ans;
}

template<typename T>
unsigned int countsetbits_lookup_table(T t)
{
	static unsigned char lookuptable[256] = { 0 };
	static bool initialised = false;
	if (!initialised)
	{
		for (int i = 0; i < 256; i++)
			lookuptable[i] = (i & 1) + lookuptable[i / 2];
		initialised = true;
	}

	return (
		lookuptable[ t        & 0xff] +
		lookuptable[(t >> 8)  & 0xff] +
		lookuptable[(t >> 16) & 0xff] +
		lookuptable[(t >> 24) & 0xff]
	);
}