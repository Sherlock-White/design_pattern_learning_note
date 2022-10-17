#pragma once
#ifndef __VIEW_H__
#define __VIEW_H__

//Observer 
class View {
public:
	virtual ~View(){}
	virtual void update() = 0;
};

#endif // !__VIEW_H__
