#include "MyString.hpp"

int main() {

	MyString one;
	MyString two(100);
	MyString three("Darova world");

	std::cout << three.GetStr() << std::endl;

	three += " Nu Darova";

	std::cout << three.GetStr() << std::endl;
}