//
//  demo1.cpp
//  CodeforStruct
//
//  Created by 老李 on 2022/3/10.
//xcode测试

#include "DynamicArray1.h"
#include <iostream>
using namespace std;

void test()
{
    cout << "测试2";
}
Dynamic_Array* Array_Init(){
    //申请内存
    Dynamic_Array* myArray =(Dynamic_Array*) malloc(sizeof(Dynamic_Array));
    myArray->size = 0;
    myArray->capacity = 20;
    myArray->pAddr = (int*)malloc(sizeof(int)*myArray->capacity);
    return myArray;
}
//插入
void push_back_Array(Dynamic_Array* arr,int value){
    if(arr ==NULL){
        return;
    }
    //判断空间是否足够
    if(arr->size == arr->capacity){
        //申请更大的内存空间,默认新空间是旧空间的两倍
        int* newSpace = (int*)malloc(sizeof(int)*arr->capacity*2);
        //拷贝数据到新空间:memcpy把旧空间数据（参数2）拷贝到新空间（参数1），多大内存（参数3）
        memcpy(newSpace, arr->pAddr,arr->capacity * sizeof(int));
        //释放旧空间的内存
        free(arr->pAddr);
        //更新容量
        arr->capacity = arr->capacity*2;
        arr->pAddr = newSpace;
    }
    //插入新元素
    arr->pAddr[arr->size] = value;
    arr->size++;
    
}
//删除
void RemoveByPos_Array(Dynamic_Array* arr,int pos){
    if(arr == NULL){
        return;
    }
    //判断位置是否有效
    if(pos<0 |pos >= arr->size){
        return;
    }
    //删除元素
    for(int i =pos; i<arr->size-1;i++){
        arr->pAddr[i] = arr->pAddr[i+1];
    }
    arr->size--;
}
//删除value第一次出现的位置
void RemoveByValue_Array(Dynamic_Array* arr,int value){
    if(arr == NULL){
        return;
    }
//    int pos =-1;
//    for(int i =0; i< arr->size;i++){
//        if(arr->pAddr[i] == value){
//            pos = i;
//            break;
//        }
        //RemoveByPos_Array(arr, pos);
    int pos = Find_Array(arr,value);
    //}
    RemoveByPos_Array(arr, pos);
}
//查找
int Find_Array(Dynamic_Array* arr,int value){
    if(arr == NULL){
        return -1;
    }
    int pos =-1;
    for(int i =0; i< arr->size;i++){
        if(arr->pAddr[i] == value){
            pos = i;
            break;
        }
    }
    return pos;
}
//打印
void Print_Array(Dynamic_Array* arr){
    if(arr == NULL){
        return;
    }
    for(int i = 0; i< arr->size;i++){
        cout << arr->pAddr[i];
    }
    //cout<< "/n";
}
//释放内存
void FreeSpace_Array(Dynamic_Array* arr){
    if(arr->pAddr != NULL){
        free(arr->pAddr);
    }
}

void Clear_Array(Dynamic_Array* arr){
    if(arr->pAddr == NULL){
        return;
    }
    //pAddr->空间
    arr->size = 0;
}
//获取动态容量
int Capacity_Array(Dynamic_Array* arr){
    if(arr == NULL){
        return -1;
    }
    return arr->capacity;
}
int Size_Array(Dynamic_Array* arr){
    if(arr == NULL){
        return -1;
    }
    return arr->size;
}
int At_Array(Dynamic_Array* arr,int pos){
    if(arr == NULL){
        return -1;
    }
    return arr->pAddr[pos];
    
}


