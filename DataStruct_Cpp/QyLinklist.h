//
// Created by 老李 on 2022/3/25.
//

#ifndef CLION_QYLINKLIST_H
#define CLION_QYLINKLIST_H


//链表小节点
typedef struct LINKNODE{
    struct LINKNODE* next;
}LinkNode;

//链表节点
typedef struct LINKLIST{
    LINKNODE head;
    int size;
}LinkList;
typedef  void(*PRINTNODE)(LinkNode *);

//初始化链表
LinkList * Init_LinkList();
//插入
void Insert_LinkList(LinkList* list,int pos,LinkNode* data);
//删除
void Remove_LinkList(LinkList* list,int pos);
//查找
int Find_LinkList(LinkList* list,LinkNode* data);
//返回链表大小
int Size_LinkList(LinkList* list);
//打印
void Print_LinkList(LinkList* list,PRINTNODE print);
//释放链表内存
void FreeSpace_LinkList(LinkList* list);

#endif //CLION_QYLINKLIST_H
