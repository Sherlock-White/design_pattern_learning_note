#pragma once
#ifndef __FLY_WEIGHT_PATTERN_H__
#define __FLY_WEIGHT_PATTERN_H__
#include<string>
#include<fstream>
#include<iostream>
#include<map>
#include<vector>

class BigChar {
private:
	char _charname;
	std::string _fontData;
public:
	BigChar(char charname) {
		_charname = charname;
		std::cout << "BigChar ctor...\n";
		_fontData = charname;
		//do not write like this:
		//_fontData = charname + '.'; //¡Á
		_fontData.push_back('.');
		//try {
		//	std::string name = "big" + _charname;
		//	name += ".txt";
		//	std::ifstream inFile(name);
		//	if (!inFile) throw "file open failed.";
		//	std::istream_iterator<std::string> is(inFile);
		//	std::istream_iterator<std::string> eof;
		//	//some copy bug here
		//	//std::copy(is, eof, std::back_inserter(_fontData));
		//	inFile.close();
		//}
		//catch (std::string s) {
		//	_fontData = _charname + "?";
		//	std::cerr << s << std::endl;
		//}
	}
	void print() {
		std::cout << _fontData;
	}
	char getCharName() {
		return _charname;
	}
	virtual ~BigChar() {
		std::cout << "BigChar dtor...\n";
	}
};

class BigCharFactory {
private:
	//Singleton Pattern
	static BigCharFactory* _singleton;
	//choose map rather than vector for faster search
	std::map<char,BigChar*> _pool;
	BigCharFactory() {
		std::cout << "BigCharFactory ctor...\n";
	}
	//set copy constructor as private
	BigCharFactory(const BigCharFactory&);
	//set assignment constructor as private
	BigCharFactory& operator=(const BigCharFactory&);
public:
	static BigCharFactory& getInstance();

	BigChar* getBigChar(char charname);

	~BigCharFactory() {
		std::cout << "BigCharFactory dtor...\n";
		/*delete _singleton;
		for (auto iter = _pool.begin(); iter != _pool.end(); iter++) {
			delete (*iter).second;
		}*/
	}
};

class BigString {
private:
	std::vector<BigChar*> _bigchars;
public:
	BigString(std::string str) {
		std::cout << "BigString ctor...\n";
		//because Singleton Pattern doesn't allow any copy here
		BigCharFactory& factory = BigCharFactory::getInstance();
		_bigchars.reserve(str.length());
		_bigchars.resize(str.length());
		for (unsigned int i = 0; i < str.length(); i++) {
			_bigchars[i] = factory.getBigChar(str[i]);
		}
	}

	virtual ~BigString() {
		std::cout << "BigString dtor...\n";
	}
	void print();
};

#endif // !__FLY_WEIGHT__
