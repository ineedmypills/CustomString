#ifndef _MY_STRING_HPP_
#define _MY_STRING_HPP_
#include <iostream>
#include <string.h>

class MyString
{
public:

	MyString() {};
	MyString(int size);
	MyString(const char* word);

private:
	char* str = nullptr;
	unsigned int size{ 0 };
};

#endif	//!_MY_STRING_HPP_