# design_pattern_learning_note

## 项目简介

- 基于侯捷老师2021年秋季学期同济大学《软件设计模式》课程的一些示例代码整理。
- 修正部分讲义中无法通过编译的错误
- 添加注释标注要点
- 将文件拆分为头文件和cpp文件

## 项目结构 

>|--Factory+Singleton+Observer   
     |--openCommand[Command派生类]  
     |--pasteCommand[Command派生类]  
     |--view[基类]  
     |--testCase2.cpp[测试]  
├── README.md  
├── Command  
│   ├── command                 // 基类  
│   ├── macroCommand            // Command派生类  
│   ├── myClass1  
│   ├── myClass2   
│   ├── simpleCommand           // Command派生类  
│   └── testCase1.cpp           // 测试  
└── Factory+Singleton+Observer  
    ├── application             // 基类  
    ├── document                // 基类  
    ├── myApp                   // Application派生类  
    ├── myDoc                   // Document派生类     
    ├── myView                  // View派生类  
    ├── openCommand             // Command派生类  
    ├── pasteCommand            // Command派生类     
    ├── view                    // 基类  
    └── testCase2.cpp           // 测试  
