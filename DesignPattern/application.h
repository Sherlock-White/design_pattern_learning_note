#pragma once
#ifndef __APPLICATION_H__
#define __APPLICATION_H__
#include"framework.h"
#include<string>
#include<iostream>

class MyApp;
class MyDoc;
class MyView;

class MyApp :public Application {
public:
	virtual Document* createDocument(std::string& name);
};

class MyDoc : public Document {
private:
	int _subjectState;
public:
	MyDoc(std::string& name) :Document(name), _subjectState(1) {}
	virtual void Serialize();
	virtual void changeData();
	virtual int getState();
	virtual void setState(int i);
	virtual View* getLastView();
};

class MyView : public View {
public:
	MyView(Document* myDoc):View(myDoc){
		_subject->attach(this);
	}
	virtual void update() override;
};

#endif // !__APPLICATION_H__
