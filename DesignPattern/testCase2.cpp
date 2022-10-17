#include"application/application.h"
#include<iostream>
#include"framework/framework.h"

int testCase2() {
	Application* app = new MyApp();
	std::cout << "\ntest OpenCommand...\n";
	OpenCommand ocmd(app);
	ocmd.execute();

	std::cout << "\ntest PasteCommand...\n";
	Document* doc = app->getLastDoc();
	PasteCommand pcmd(doc);
	pcmd.execute();

	std::cout << "\ntext Document-Views(Subject-Observers)...\n";
	/*MyView* myView1 = new MyView(app->getLastDoc());
	[¡ü invalid conversion from 'Document*' to 'MyDoc*']*/
	MyView* myView1 = new MyView((MyDoc*)app->getLastDoc());
	MyView* myView2 = new MyView((MyDoc*)app->getLastDoc());
	app->getLastDoc()->changeData();
	app->getLastDoc()->changeData();

	delete myView1;
	delete myView2;
	return 0;
}