#include "MyString.hpp"
#include <cstring>

MyString::MyString() {
	this->size = 255;
	this->str = new char[this->size];
}

MyString::MyString(int size)
{
	this->size = size;
	this->str = new char[this->size];
}

MyString::MyString(const char* word)
{
	this->size = strlen(word) + 1;
	this->str = new char[this->size] {' '};
	memcpy(this->str, word, this->size);
}

MyString::~MyString()
{
	delete[]this->str;
}

MyString& MyString::operator=(const MyString& word)
{
	if (this->str != nullptr)
	{
		delete[]this->str;
	}
	this->size = strlen(word.str) + 1;
	this->str = new char[this->size] {' '};
	memcpy(this->str, word.str, this->size);
	return *this;

}

MyString MyString::operator+(const MyString& word)
{
	MyString newString;
	if (newString.str != nullptr)
	{
		delete[]newString.str;
	}
	newString.size = this->size + word.size - 1;
	memcpy(newString.str, this->str, this->size-1);
	memcpy(newString.str + (this->size - 1), word.str, word.size);

}

char* MyString::GetStr()
{
	return this->str;
}


