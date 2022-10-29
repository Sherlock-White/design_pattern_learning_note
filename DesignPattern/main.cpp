#include"commandPattern.h"
#include"myClass.h"
#include"application.h"
#include"strategyPattern.h"
#include"compositePattern.h"
#include"flyweightPattern.h"

int testCommandPattern() {
	std::cout << "test SimpleCommand<>...\n";
	MyClass1 receiver1;
	Command* cmd1 = new SimpleCommand<MyClass1>(&receiver1, &MyClass1::action);
	//cmd1->execute({ 1,2 });
	cmd1->execute();

	MyClass2 receiver2;
	Command* cmd2 = new SimpleCommand<MyClass2>(&receiver2, &MyClass2::action);
	//cmd2->execute({ 1,2,3,4 });
	cmd2->execute();

	std::cout << "test MacroCommand... \n";
	MacroCommand macroCmd;
	macroCmd.add(cmd1);
	macroCmd.add(cmd2);
	//macroCmd.execute({ 9,8 });
	macroCmd.execute();

	macroCmd.remove(cmd2);
	//macroCmd.execute({ 9,8,7,6 });
	macroCmd.execute();

	delete cmd1;
	delete cmd2;
	return 0;
}

int testDocument() {
	Application* app = new MyApp();
	std::cout << "\ntest OpenCommand...\n";
	OpenCommand ocmd(app);
	ocmd.execute();

	std::cout << "\ntest PasteCommand...\n";
	Document* doc = app->getLastDoc();
	PasteCommand pcmd(doc);
	pcmd.execute();

	std::cout << "\ntest Document-Views(Subject-Observers)...\n";
	/*MyView* myView1 = new MyView(app->getLastDoc());
	[invalid conversion from 'Document*' to 'MyDoc*']*/
	MyView* myView1 = new MyView(app->getLastDoc());
	MyView* myView2 = new MyView(app->getLastDoc());
	app->getLastDoc()->changeData();
	app->getLastDoc()->changeData();

	delete myView1;
	delete myView2;
	return 0;
}

int testStrategyPattern() {
	TestBed test;
	int answer, width;
	std::cout << "Exit(0) Left(1) Right(2) Center(3):";
	std::cin >> answer;
	while (answer) {
		std::cout << "Width:";
		std::cin >> width;
		test.setStrategy(answer, width);
		test.doIt();
		std::cout << "Exit(0) Left(1) Right(2) Center(3):";
		std::cin >> answer;
	}
	return 0;
}

int testCompositePattern() {
	try {
		std::cout << "Making root entries..." << std::endl;
		Directory rootdir("root");
		Directory bindir("bin");
		Directory tmpdir("tmp");
		Directory usrdir("usr");
		rootdir.add(&bindir);
		rootdir.add(&tmpdir);
		rootdir.add(&usrdir);
		File vi("vi", 10000);
		File latex("latex", 20000);
		bindir.add(&vi);
		bindir.add(&latex);
		Entry* entry = &rootdir;
		entry->printList();
		std::cout << "\n" << "Making user entries..." << std::endl;
		Directory yuki("yuki");
		Directory hanako("hanako");
		Directory tomura("tomura");
		usrdir.add(&yuki);
		usrdir.add(&hanako);
		usrdir.add(&tomura);
		File diary("diary.html", 100);
		File composite("Composite.java", 200);
		File memo("memo.tex", 300);
		File game("game.doc", 400);
		File junk("junk.mail", 500);
		yuki.add(&diary);
		yuki.add(&composite);
		hanako.add(&memo);
		tomura.add(&game);
		tomura.add(&junk);
		entry->printList();
	}
	catch(...){
		std::cout << "[exception]" << std::endl;
	}
	return 0;
}

int main() {
	std::cout << "main()--------------\n";
	std::string str;
	for (int i = 0; i < 3; i++) {
		std::cout << "input #" << i << "string(using digits 0~9):";
		std::cin >> str;
		BigString(str).print();
	}
	std::cout << "main() exit---------\n";
	return 0;
}