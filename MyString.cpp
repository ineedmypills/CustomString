#include "MyString.hpp"

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
	this->str = new char[this->size];
}


