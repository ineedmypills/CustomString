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
	~MyString();
	MyString& operator=(const MyString& word);
	MyString operator+(const MyString& word);

	char* GetStr();

private:
	char* str = nullptr;
	unsigned int size{ 0 };
};

#endif	//!_MY_STRING_HPP_