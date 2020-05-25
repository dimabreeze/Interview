#pragma once
#include <unordered_map>

class DisjointSets
{
private:
	mutable std::unordered_map<int, int> root;
	mutable std::unordered_map<int, int> size;
	int count_distinct = 0;
public:
	int CreateSet( int idx )
	{
		if (idx < 0) return -1;
		if (HasSet( idx )) return idx;

		root[idx] = idx;
		size[idx] = 1;
		++count_distinct;
		return idx;
	}

	int Union( int s1, int s2 )
	{
		if (s1 < 0) return s2;
		if (s2 < 0) return s1;

		auto rs1 = FindSet( s1 );
		auto rs2 = FindSet( s2 );
		if (rs1 < 0) return rs2;
		if (rs2 < 0) return rs1;

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

	bool HasSet( int s ) const
	{
		return s >= 0 and root.find( s ) != root.end();
	}

	int FindSet( int s ) const
	{
		if (!HasSet( s )) return -1;

		if (root[s] == s) return s;

		root[s] = FindSet( root[s] );
		return root[s];
	}

	bool IsSameSet( int s1, int s2 ) const
	{
		return FindSet( s1 ) == FindSet( s2 );
	}

	int getCountDistinct() const {
		return count_distinct;
	}
};