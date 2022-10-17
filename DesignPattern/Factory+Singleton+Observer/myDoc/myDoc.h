#pragma once
#ifndef __MY_DOC_H__
#define __MY_DOC_H__
#include"../document/document.h"
#include<string>
#include<iostream>

class MyDoc : public Document {
private:
	int _subjectState;
public:
	MyDoc(std::string& name) :Document(name),_subjectState(1) {}
	virtual void Serialize();
	virtual void changeData();
	int getState();
};

#endif // !__MY_DOC_H__
