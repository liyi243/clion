//
// Created by 老李 on 2022/3/15.
//单向链表

//#ifndef CLION_LINKLIST_H
//#define CLION_LINKLIST_H
//
//#include "iostream"
//
////链表节点
//typedef struct LINKNODE{
//    //int data;写int就固定了,所以用一个无类型指针
//    void* data;
//    struct LINKNODE* next;
//}LinkNode;
//
////链表结构体
//typedef struct LINKLIST{
//    LinkNode * head;
//    int size;
//    //需要容量吗？没有容量的概念
//}LinkList;
//typedef void(*PRINTLINKNODE)(void*);
//
//
////初始化链表
//LinkList * Init_LinkList();
////指定位置插入
//void Insert_LinkList(LinkList* list,int pos,void *data);
////删除指定位置的值
//void RemoveByPos_LinkList(LinkList* list,int pos);
////获取长度
//int Size_LinkList(LinkList* list);
////查找
//int Find_LinkList(LinkList* list,void* data);
////打印链表节点
//void Print_LinkList(LinkList* list,PRINTLINKNODE print);
////返回第一个节点
//void* Front_LinkList(LinkList* list);
////释放链表内存
//void FreeSpace_Linklist(LinkList* list);
//
//#endif //CLION_LINKLIST_H
