#include"myClass2.h"

void MyClass2::action() {
	std::cout << "MyClass1:action();\n";
}

/*void MyClass2::action(std::initializer_list<int> inizer) {
	std::cout << "MyClass1:action();\n";
	for (auto elem : inizer) {
		std::cout << elem;
	}
	std::cout << std::endl;
}
[�� if you want to pass some parameters,write just like this.]*/