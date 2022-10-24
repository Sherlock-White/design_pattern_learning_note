#pragma once
#ifndef __STRATEGY_PATTERN_H__
#define __STRATEGY_PATTERN_H__
#include<list>

class Strategy;

class TestBed {
private:
	Strategy* _strategy;
	
public:
	enum StrategyType{Dummy,Left,Right,Center};
	TestBed() {
		_strategy = nullptr;
	}
	void setStrategy(int type, int width);
	void doIt();
};

class Strategy {
private:
	virtual void justify(char* line) = 0;
protected:
	int _width;
public:
	Strategy(int width):_width(width){}
	void format();
};

class LeftStrategy : public Strategy {
public:
	LeftStrategy(int width):Strategy(width){}
private:
	virtual void justify(char* line);
};

class RightStrategy : public Strategy {
public:
	RightStrategy(int width) :Strategy(width) {}
private:
	virtual void justify(char* line);
};

class CenterStrategy : public Strategy {
public:
	CenterStrategy(int width) :Strategy(width) {}
private:
	virtual void justify(char* line);
};

#endif // !__STRATEGY_H__
