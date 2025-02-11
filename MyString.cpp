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

char* MyString::GetStr()
{
	return this->str;
}


