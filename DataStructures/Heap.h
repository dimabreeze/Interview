#pragma once
#include <vector>
#include <algorithm>
#include <queue>

// A = B if cmp(A,B) && cmp(B,A)
// A < B if cmp(A,B) && !cmp(B,A)
// A > B if !cmp(A,B) && cmp(B,A)

template<typename T, typename Cmp = std::less<T>>
struct Heap
{
	void add( T value )
	{
		data.push_back( value );
		auto idx = size() - 1;
		if (idx == 0) return;

		auto iParent = idxParent( idx );
		const Cmp cmp;
		while (idx > 0 && cmp(getValue(iParent), getValue(idx)) && !cmp( getValue( idx ), getValue( iParent ) ))
		{
			std::swap( getValue( iParent ), getValue( idx ) );
			idx = iParent;
			iParent = idxParent( idx );
		}
	}

	const T& top() const {
		return data.front();
	}

	T pop() {
		T topValue = top();
		data.front() = data.back();
		data.pop_back();
		heapify( 0 );
		return topValue;
	}

	static Heap buildFrom( const std::vector<T>& vec )
	{
		Heap h;
		h.data = vec;
		for (size_t i = 0; i < h.size() / 2; ++i)
		{
			heapify( i );
		}
		return h;
	}

	size_t size() const { return data.size(); }

	static size_t idxLeft( size_t idx ) { return 2 * idx + 1; }
	static size_t idxRight( size_t idx ) { return 2 * idx + 2; }
	static size_t idxParent( size_t idx ) { return (idx - 1) / 2; }
	const T& getValue( size_t idx ) const { return data.at( idx ); }
	T& getValue( size_t idx ) { return data.at( idx ); }


private:
	void heapify(size_t idx) {
		Cmp cmp;
		while (true)
		{
			auto idxL = idxLeft( idx );
			auto idxR = idxRight( idx );
			auto toppestChild = idx;
			if (idxL < size() and 
				cmp( getValue( idx ), getValue( idxL )) and 
				!cmp( getValue( idxL ), getValue( idx )) 
			) 
				toppestChild = idxL;
			else if (idxR < size() and cmp( getValue( idx ), getValue( idxR )) and !cmp( getValue( idxR ), getValue( idx )))
				toppestChild = idxR;
			else
				break;
			std::swap( getValue( idx ), getValue( toppestChild ) );
			idx = toppestChild;
		}
	}

private:
	std::vector<T> data; 
};
