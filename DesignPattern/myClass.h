#pragma once
#include<iostream>

#ifndef __MY_CLASS_H__
#define __MY_CLASS_H__

class MyClass1;
class MyClass2;

class MyClass1 {
public:
	void action();
	/*void action(std::initializer_list<int> inizer);
	[if you want to pass some parameters,write just like this.]*/
};

void MyClass1::action() {
	std::cout << "MyClass1:action();\n";
}

/*void MyClass1::action(std::initializer_list<int> inizer) {
	std::cout << "MyClass1:action();\n";
	for (auto elem : inizer) {
		std::cout << elem;
	}
	std::cout << std::endl;
}
[if you want to pass some parameters,write just like this.]*/


class MyClass2 {
public:
	void action();
	/*void action(std::initializer_list<int> inizer);
	[if you want to pass some parameters,write just like this.]*/
};

void MyClass2::action() {
	std::cout << "MyClass2:action();\n";
}

/*void MyClass2::action(std::initializer_list<int> inizer) {
	std::cout << "MyClass1:action();\n";
	for (auto elem : inizer) {
		std::cout << elem;
	}
	std::cout << std::endl;
}
[if you want to pass some parameters,write just like this.]*/

#endif // !__MY_CLASS_1_H__
