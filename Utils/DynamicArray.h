#pragma once

template <typename T>
T* AllocateDynamicArray( uint16_t count )
{
	return new T[count];
}

template <typename T>
void FreeDynamicArray( T* dArray )
{
	delete[] dArray;
}

//pass array to a function:
/*
template<typename T>
void func(T** arr, uint width, uint height) {
	for(int i=0; i<width; ++i)
	{
		for(int j=0; j<height; ++j)
			cout << arr[i][j] << ' ';
		cout << endl;
	}
}
*/