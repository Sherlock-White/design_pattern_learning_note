#include"myView.h"
#include<iostream>

MyView::MyView(MyDoc* myDoc) {
	_subject = myDoc;
	_subject->attach(this);
}

void MyView::update() {
	std::cout << "MyView::update() data=" << _subject->getState() << std::endl;
}