#include"myDoc.h"

void MyDoc::Serialize() {
	std::cout << "MyDoc::serialize()\n";
}

void MyDoc::changeData() {
	_subjectState *= 5;
	dataChanged();
	notify();
}

int MyDoc::getState() {
	return _subjectState;
}