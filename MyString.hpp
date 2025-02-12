#ifndef _MY_STRING_HPP_
#define _MY_STRING_HPP_
#include <iostream>
#include <cstring>



class MyString
{
public:

	MyString();
	MyString(int size);
	MyString(const char* word);
	MyString(MyString&& word);


	~MyString();

	MyString& operator=(const MyString& word);
	MyString& operator=(MyString&&);
	MyString operator+(const MyString& word);
	MyString& operator+=(const char* word);

	int GetSize();
	void Resize(unsigned int a);
	void Clear();
	bool Empty();
	void PushBack(char a);
	void Print();
	const char* GetStr();


private:
	char* str = nullptr;
	unsigned int size{ 0 };
};

#endif	//!_MY_STRING_HPP_