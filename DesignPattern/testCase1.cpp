#include"command/command.h"
#include"myClass/myClass.h"

int main() {
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