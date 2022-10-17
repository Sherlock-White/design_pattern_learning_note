#pragma once
#ifndef __DOCUMENT_H__
#define __DOCUMENT_H__
#include<iostream>
#include<string>
#include<list>
#include"../view/view.h"

class Document {
private:
	std::string _name;
	//Observer
	std::list<View*> _views;
	bool _changed = false;
public:
	Document(std::string& name);
	//actually operation open and paste should be declared as virtual function
	//and defined in derived class,but here just write like this for convenience
	void open();
	void paste();
	virtual void Serialize();
	virtual ~Document(){}
	void attach(View* view);
	void detach(View* view);
	void notify();
	virtual void changeData() = 0;
	void dataChanged();
};

#endif // !__DOCUMENT_H__
