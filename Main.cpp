#include "MyString.hpp"

int main() {

	MyString one;
	MyString two(100);
	MyString three("Darova world");

	std::cout << three.GetStr() << std::endl;

	three += " Nu Darova";

	std::cout << three.GetStr() << std::endl;
	std::cout << three.Empty() << std::endl;
	
	std::cout << three.GetSize() << std::endl;
	three.Clear();
	std::cout << three.GetSize() << std::endl;
	std::cout << three.Empty() << std::endl;
}