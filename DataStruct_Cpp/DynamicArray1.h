//
//  DynamicArray.h
//  CodeforStruct
//
//  Created by 老李 on 2022/3/10.
//

#ifndef DynamicArray1_h
#define DynamicArray1_h

//动态增长内存 策略 将存放的数据的内存放哪？堆上
//动态数组，如果5个元素 申请内存，拷贝数据，释放内存6，插入第七个？低效---方案容量：表示这块内存空间一共可以存多少个
//size概念，记录数组中具体元素个数

//动态数组的结构体
typedef struct DYNAMICARRAY{
    int* pAddr;//存放数据的地址
    int size;  //当前有多少个元素
    int capacity; //容量：容器中最大能容纳多少元素
}Dynamic_Array;

//写一系列的相关对DYNAMICARRAY结构体操作的函数
//初始化
Dynamic_Array* Array_Init();
//插入
void push_back_Array(Dynamic_Array* arr,int value);
//删除
void RemoveByPos_Array(Dynamic_Array* arr,int pos);
void RemoveByValue_Array(Dynamic_Array* arr,int value);
//查找
int Find_Array(Dynamic_Array* arr,int value);
//打印
void Print_Array(Dynamic_Array* arr);
//释放内存
void FreeSpace_Array(Dynamic_Array* arr);
//清空数组
void Clear_Array(Dynamic_Array* arr);
//获取动态容量
int Capacity_Array(Dynamic_Array* arr);
int Size_Array(Dynamic_Array* arr);
int At_Array(Dynamic_Array* arr,int pos);


#endif /* DynamicArray_h */
