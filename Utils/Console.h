#pragma once
#define WIN32_LEAN_AND_MEAN
#include <iostream>
#include <ostream>
#include <iterator>
#include <vector>
#include <Windows.h>
#include "DynamicArray.h"


void cls()
{
	// Get the Win32 handle representing standard output.
	// This generally only has to be done once, so we make it static.
	static const HANDLE hOut = GetStdHandle( STD_OUTPUT_HANDLE );

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD topLeft = { 0, 0 };

	// std::cout uses a buffer to batch writes to the underlying console.
	// We need to flush that to the console because we're circumventing
	// std::cout entirely; after we clear the console, we don't want
	// stale buffered text to randomly be written out.
	std::cout.flush();

	// Figure out the current width and height of the console window
	if (!GetConsoleScreenBufferInfo( hOut, &csbi )) {
		// TODO: Handle failure!
		abort();
	}

	DWORD length = csbi.dwSize.X * csbi.dwSize.Y;
	DWORD written = 0;
	// Flood-fill the console with spaces to clear it
	FillConsoleOutputCharacter( hOut, TEXT( ' ' ), length, topLeft, &written );

	// Reset the attributes of every character to the default.
	// This clears all background colour formatting, if any.
	FillConsoleOutputAttribute( hOut, csbi.wAttributes, length, topLeft, &written );

	// Move the cursor back to the top left for the next sequence of writes
	SetConsoleCursorPosition( hOut, topLeft );
}

// x is the column, y is the row. The origin (0,0) is top-left.
void setCursorPosition( int x, int y )
{
	static const HANDLE hOut = GetStdHandle( STD_OUTPUT_HANDLE );
	std::cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition( hOut, coord );
}

void print(char* data, uint16_t width, uint16_t height)
{
	const auto MAX_X = width;
	const auto MAX_Y = height;
	//auto prev_data = AllocateDynamicArray<char>( height * width );
	//std::memset( (char*)prev_data, 0, MAX_X * MAX_Y );

	// ...

	for (int y = 0; y != MAX_Y; y++)
	{
		/*
		if (data[x][y] == prev_data[x*MAX_Y+y]) {
			continue;
		}
		*/
		setCursorPosition( 0, y );
		//std::cout << data[x*width+y];
		auto begin = data + y * width;
		std::copy( begin, begin + width, std::ostream_iterator<char>( std::cout, " " ) );
	}
	setCursorPosition( 0, 0 );
	std::cout.flush();
	//std::memcpy( (char*)prev_data, (char const*)data, MAX_X * MAX_Y );
}


/*
// Note: This requires you to invert the dimensions of `battleField` (and
// `prevBattleField`) in order for rows of characters to be contiguous in memory.
void print2()
{
	for (int y = 0; y != MAX_Y; ++y)
	{
		int runStart = -1;
		for (int x = 0; x != MAX_X; ++x)
		{
			if (battleField[y][x] == prev_data[y][x]) {
				if (runStart != -1) {
					setCursorPosition( runStart, y );
					std::cout.write( &battleField[y][runStart], x - runStart );
					runStart = -1;
				}
			}
			else if (runStart == -1) {
				runStart = x;
			}
		}
		if (runStart != -1) {
			setCursorPosition( runStart, y );
			std::cout.write( &battleField[y][runStart], MAX_X - runStart );
		}
	}
	std::cout.flush();
	std::memcpy( (char*)prev_data, (char const*)battleField, MAX_X * MAX_Y );
}
*/