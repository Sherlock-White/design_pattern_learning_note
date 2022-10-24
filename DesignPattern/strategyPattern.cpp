#include"strategyPattern.h"
#include<fstream>
#include<iostream>

void TestBed::setStrategy(int type, int width) {
	//we need to prevent stack leak,but at first _strategy == nullptr
	delete _strategy;
	if (type == Left) _strategy = new LeftStrategy(width);
	else if (type == Right) _strategy = new RightStrategy(width);
	else if (type == Center) _strategy = new CenterStrategy(width);
}

void TestBed::doIt() {
	_strategy->format();
}

void Strategy::format() {
	char line[80], word[30];
	std::ifstream inFile("quote.txt", std::ios::in);
	line[0] = '\0';
	
	inFile >> word;
	strcat_s(line, word);
	while (inFile >> word) {
		if (strlen(line) + strlen(word) + 1 > _width) {
			justify(line);
		}
		else {
			strcat_s(line, " ");
		}
	}
	justify(line);
}

void LeftStrategy::justify(char* line) {
	std::cout << "LeftStrategy::justify()" << std::endl;
	std::cout << line << std::endl;
	line[0] = '\0';
}

void RightStrategy::justify(char* line) {
	std::cout << "RightStrategy::justify()" << std::endl;
	//char buf[80];
	//int offset = _width - strlen(line);
	//memset(buf, ' ', 80);
	//strcpy(&(buf[offset]), line);
	//std::cout << buf << std::endl;
	//line[0] = '\0';
}

void CenterStrategy::justify(char* line) {
	std::cout << "CenterStrategy::justify()" << std::endl;
	/*char buf[80];
	int offset = (_width - strlen(line)) / 2;
	memset(buf, ' ', 80);
	strcpy(&(buf[offset]), line);
	std::cout << buf << std::endl;
	line[0] = '\0';*/
}