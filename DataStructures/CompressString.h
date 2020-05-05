#pragma once
#include <iostream>
#include <sstream>

/*
Problem: Compress a string such that 'AAABCCDDDD' becomes 'A3BC2D4'. 
Only compress the string if it saves space.

Constraints:
* ASCII
* Case-sensitive
* Can use additional data structures
*/

struct CompressString
{
	static std::string visit( const std::string& str )
	{
		if (str.size() < 3) return str;

		std::stringstream ss;
		auto output = [&ss](char c, int count) {
			ss << c;
			if (count > 2)
			{
				ss << count;
			}
			else if (count > 1)
			{
				ss << c;
			}
		};

		char previous = str[0];
		int count = 1;
		for (int i = 1; i < str.size(); ++i)
		{
			auto c = str[i];
			if (c == previous) ++count;
			else {
				output( previous, count );
				count = 1;
			}
			previous = c;
		}
		output( previous, count );
		return ss.str();
	}
};