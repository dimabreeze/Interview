#pragma once

#include <unordered_map>
#include <optional>

#include <iostream>
/*
struct TrieNodeString
{
	std::unordered_map<std::string::value_type, TrieNodeString*> adj;
	bool end = false;
};

void insert( TrieNodeString& root, const std::string& data )
{
	using Node = TrieNodeString;
	Node* node = &root;
	for (auto c : data)
	{
		auto& adj = node->adj[c];
		if (adj == nullptr)
		{
			adj = new Node;
		}
		node = adj;
	}
	node->end = true;
}

bool find( TrieNodeString& root, const std::string& data )
{
	using Node = TrieNodeString;
	auto node = &root;
	for (auto c : data)
	{
		auto iter = node->adj.find( c );
		if (iter == node->adj.end()) return false;
		node = iter->second;
	}
	return node->end;
}





void insert2( TrieNodeString& root, std::string word )
{
	std::cout << "insert [" << word << "]" << std::endl;
	TrieNodeString* node = &root;
	int i = 0;
	for (auto c : word)
	{
		std::cout << i++ << ": add '" << c << "'" << std::endl;
		auto& adj = node->adj[c];
		if (adj == nullptr)
		{
			adj = new TrieNodeString;
		}
		node = adj;
		std::cout << std::endl;
	}
	std::cout << "setting final - node with " << node->adj.size() << " adj nodes" << std::endl;
	node->end = true;
}

class Solution {
public:
	std::string longestCommonPrefix( std::vector<std::string>& strs ) {
		TrieNodeString root;
		for (auto word : strs)
		{
			if (word.empty()) return "";
			insert( root, word );
		}

		std::string res;
		auto node = &root;
		int i = 0;
		while (node->adj.size() == 1)
		{
			auto begin = node->adj.begin();
			std::cout << i++ << " (final = " << node->end << "): [" << res << "] + '" << begin->first << "' = [";
			res += begin->first;
			std::cout << res << "]" << std::endl;

			if (node->end)
			{
				std::cout << "final" << std::endl;
				return res;
			}
			node = begin->second;
		}
		return res;
	}
};
*/