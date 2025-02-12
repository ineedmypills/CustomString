#include "MyString.hpp"


MyString::MyString() {
#include <cstring>
#include <iostream>
#include <ostream>
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

MyString::MyString(MyString&& word)
{
	this->size = word.size;
	this->str = new char[this->size];
	this->str = word.str;
	word.str = nullptr;
	word.size = 0;
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

MyString& MyString::operator=(MyString&& word)
{
	if (this->str != nullptr)
	{
		delete[]this->str;
	}

	this->size = word.size;
	this->str = word.str;
	word.size = 0;
	word.str = nullptr;

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
	newString.str = new char[newString.size];
	memcpy(newString.str, this->str, this->size - 1);
	memcpy(newString.str + (this->size - 1), word.str, word.size);

	return newString;
}

MyString& MyString::operator+=(const char* word)
{
	char* tempChar = new char[this->size + strlen(word)];
	memcpy(tempChar, this->str, this->size - 1);
	delete[]this->str;
	this->str = tempChar;
	memcpy(this->str + (this->size - 1), word, strlen(word));
	this->size += strlen(word);
	this->str[this->size - 1] = '\0';



	return *this;
}


int MyString::GetSize()
{
	return this->size;
}

void MyString::Resize(unsigned int cell) {
	char* newStr = new char[cell + 1];
	if (this->str) {
		unsigned int copySize = (cell < this->size) ? cell : this->size;
		std::memcpy(newStr, this->str, copySize);
		newStr[copySize] = '\0';
	}
	else {
		newStr[0] = '\0';
	}

	delete[] this->str;
	this->str = newStr;
	this->size = cell;
}

void MyString::Clear() {
	delete[] this->str;
	this->str = nullptr;
	size = 0;
}

bool MyString::Empty() {
	return size == 0 || this->str == nullptr;
}

void MyString::PushBack(char newChar) {
	char* newStr = new char[size + 2];
	if (this->str) {
		std::memcpy(newStr, this->str, size);
	}
	newStr[size] = newChar;
	newStr[size + 1] = '\0';

	delete[] this->str;
	this->str = newStr;
	size++;
}

void MyString::Print() {
	if (this->str) {
		std::cout << str << std::endl;
	}
	else {
		std::cout << "empty" << std::endl;
	}
}

const char* MyString::GetStr() {
	return this->str;
}


