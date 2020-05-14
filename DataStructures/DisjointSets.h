#pragma once
#include <vector>

class DisjointSets
{
private:
	mutable std::vector<size_t> root;
	mutable std::vector<size_t> size;
	size_t count_distinct;
public:
	size_t CreateSet()
	{
		auto i = root.size();
		root.push_back( i );
		size.push_back( 1 );
		++count_distinct;
		return i;
	}

	size_t Union( size_t s1, size_t s2 )
	{
		auto rs1 = FindSet( s1 );
		auto rs2 = FindSet( s2 );
		if (rs1 == rs2) return rs1;

		--count_distinct;
		if (size[rs1] >= size[rs2])
		{
			//attach s2 -> s1
			root[rs2] = rs1;
			size[rs1] += size[rs2];
			return rs1;
		}
		else
		{
			//attach s1 -> s2
			root[rs1] = rs2;
			size[rs2] += size[rs1];
			return rs2;
		}
	}

	size_t FindSet( size_t s ) const
	{
		if (root[s] == s) return s;

		root[s] = FindSet( root[s] );
		return root[s];
	}

	bool IsSameSet( size_t s1, size_t s2 ) const
	{
		return FindSet( s1 ) == FindSet( s2 );
	}

	size_t getCountDistinct() const { 
		return count_distinct; 
	}
};
