#include"flyweightPattern.h"
BigCharFactory& BigCharFactory::getInstance() {
	if (_singleton == nullptr) {
		_singleton = new BigCharFactory;
	}
	return (*_singleton);
}

BigChar* BigCharFactory::getBigChar(char charname) {
	BigChar* bc = nullptr;
	auto iter = _pool.find(charname);
	if (iter == _pool.end()) {
		bc = new BigChar(charname);
		_pool[charname] = bc;
	}
	else {
		std::cout << charname << " found! using Flyweight.\n";
		bc = (*iter).second;
	}
	return bc;
}

//initialize static data member here
//do not initialize it in head file, compiler will define it more than once
BigCharFactory* BigCharFactory::_singleton = nullptr;

void BigString::print() {
	for (unsigned int i = 0; i < _bigchars.size(); i++) {
		_bigchars[i]->print();
	}
	std::cout << std::endl;
}