#pragma once

#include <vector>

struct FenwickTree
{
	/**
	 * Start from index+1 if you updating index in original array. Keep adding this value
	 * for next node till you reach outside range of tree
	 */
	static void updateBinaryIndexedTree( std::vector<int>& binaryIndexedTree, int val, size_t index ) {
		while (index < binaryIndexedTree.size()) {
			binaryIndexedTree[index] += val;
			index = getNext( index );
		}
	}

	/**
	 * Start from index+1 if you want prefix sum 0 to index. Keep adding value
	 * till you reach 0
	 */
	static int getSum( const std::vector<int>& binaryIndexedTree, size_t index ) {
		index = index + 1;
		int sum = 0;
		while (index > 0) {
			sum += binaryIndexedTree[index];
			index = getParent( index );
		}
		return sum;
	}

	/**
	 * Creating tree is like updating Fenwick tree for every value in array
	 */
	static std::vector<int> createTree( std::vector<int> input ) {
		std::vector<int> binaryIndexedTree( input.size() + 1 );
		for (size_t i = 1; i <= input.size(); i++) {
			updateBinaryIndexedTree( binaryIndexedTree, input[i - 1], i );
		}
		return binaryIndexedTree;
	}
private:
	/**
	 * To get parent
	 * 1) 2's complement to get minus of index
	 * 2) AND this with index
	 * 3) Subtract that from index
	 */
	static int getParent( int index ) {
		return index - (index & -index);
	}

	/**
	 * To get next
	 * 1) 2's complement of get minus of index
	 * 2) AND this with index
	 * 3) Add it to index
	 */
	static int getNext( int index ) {
		return index + (index & -index);
	}
};