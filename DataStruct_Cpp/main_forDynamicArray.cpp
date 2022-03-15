//
// Created by 老李 on 2022/3/14.
//

#include "main_forDynamicArray.h"
//
//  main.cpp
//  CodeforStruct
//
//  Created by 老李 on 2022/3/10.
//github测试11
//

#include <stdio.h>
#include "DynamicArray1.h"
#include <iostream>
using namespace std;

void test01(){
    Dynamic_Array* myArray = Array_Init();
    cout <<"数组容量:" <<myArray->capacity << "\n";
    cout <<"数组大小:" <<Size_Array(myArray) <<"\n";

    for(int i = 0;i<30;i++){
        push_back_Array(myArray, i);
    }

    Print_Array(myArray);
    cout <<"数组容量:" <<myArray->capacity << "\n";
    cout <<"数组大小:" <<Size_Array(myArray) <<"\n";

    RemoveByPos_Array(myArray, 0);
    cout << Find_Array(myArray, 9);
    Print_Array(myArray);

    FreeSpace_Array(myArray);

}

//int main(int argc, const char * argv[]) {
//    // insert code here...
//    test01();
//    //std::cout << "Hello, World!\n";
//    return 0;
//}
