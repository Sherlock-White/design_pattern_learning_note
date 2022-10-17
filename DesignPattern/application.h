#pragma once
#ifndef __APPLICATION_H__
#define __APPLICATION_H__
#include"../framework/framework.h"
#include<string>
#include<iostream>

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
	int getState();
};

class MyView : public View {
private:
	MyDoc* _subject;
public:
	MyView(MyDoc* myDoc);
	virtual void update() override;
};

#endif // !__APPLICATION_H__
