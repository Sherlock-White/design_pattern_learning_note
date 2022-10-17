#pragma once
#ifndef __MY_VIEW_H__
#define __MY_VIEW_H__
#include"../myDoc/myDoc.h"

class MyView : public View {
private:
	MyDoc* _subject;
public:
	MyView(MyDoc* myDoc);
	virtual void update() override;
};

#endif // !__MY_VIEW_H__
