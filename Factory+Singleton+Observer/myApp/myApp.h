#pragma once
#ifndef __MY_APP_H__
#define __MY_APP_H__
#include"application.h"
#include"myDoc.h"
#include<string>
#include<iostream>

class MyApp :public Application {
public:
	virtual Document* createDocument(std::string& name);
};

#endif // !__MY_APP_H__
