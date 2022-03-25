//
// Created by 老李 on 2022/3/25.
//

#include "QyLinklist.h"
#include "iostream"
#include "stdlib.h"
//初始化链表
LinkList * Init_LinkList(){
    LinkList * list = (LinkList*)malloc(sizeof (LinkList));
    list->head.next = NULL;
    list->size = 0;
    return list;
}
//插入
void Insert_LinkList(LinkList* list,int pos,LinkNode* data){
    if(list == NULL){return;}
    if(data ==NULL){return;}
    //如果pos不在范围内，数据就插到尾部
    if(pos < 0||pos >list->size){pos = list->size;}
    //查找插入位置
    LinkNode * pCurrent = &(list->head);
    for (int i = 0; i < pos; i++) {
        pCurrent = pCurrent->next;
    }
    //插入新节点
    data->next = pCurrent->next;
    pCurrent->next = data;

    list->size++;
}
//删除
void Remove_LinkList(LinkList* list,int pos){
    if(list ==NULL){return;}
    if(pos<0||pos>list->size){return;}
    LinkNode *pCurrent = &(list->head);
    for(int i = 0;i<pos;i++){
        pCurrent = pCurrent->next;
    }
//    LinkNode *pDel = pCurrent->next;
//    pCurrent->next = pDel->next;
    pCurrent->next =pCurrent->next->next;
    list->size--;

}
//查找
int Find_LinkList(LinkList* list,LinkNode* data){
    //int pos =-1;
    if(list ==NULL){return -1;}
    if(data ==NULL){return -1;}
    LinkNode *pCurrent = &(list->head);
    for(int i=0;i<list->size;i++){
        if(data == pCurrent){
            return i;
            break;
        }
        pCurrent = pCurrent->next;
    }
    //return 0;
}
//返回链表大小
int Size_LinkList(LinkList* list){
    return list->size;
}
//打印
void Print_LinkList(LinkList* list,PRINTNODE print){
    if (list ==NULL){
        return;
    }
    LinkNode* pCurrent = list->head.next;
    while (pCurrent != NULL){
        print(pCurrent);
        pCurrent = pCurrent->next;
    }
}
//释放链表内存
void FreeSpace_LinkList(LinkList* list){
    if(list ==NULL){
        return;
    }
    free(list);
}

//=================主函数============

typedef struct PERSON{
    LinkNode node;
    char name[64];
    int age;
}Person;

void MyPrint(LinkNode* data){
    Person * p = (Person*)data;
    std::cout <<p->name<<std::endl;
    std::cout <<p->age<<std::endl;
    //printf("Name:%s Age:%d\n",p->name,p->age);
}
int main(){
    //创建链表
    LinkList *list = Init_LinkList();
    //创建数据
    Person  p1,p2,p3,p4,p5;
    strcpy(p1.name,"aaa");
    strcpy(p2.name,"bbb");
    strcpy(p3.name,"ccc");
    strcpy(p4.name,"ddd");
    strcpy(p5.name,"eee");
    p1.age = 10;
    p2.age = 11;
    p3.age = 12;
    p4.age = 13;
    p5.age = 14;

    //将节点插入链表
    Insert_LinkList(list,0,(LinkNode*)(&p1));
    Insert_LinkList(list,0,(LinkNode*)(&p2));
    Insert_LinkList(list,0,(LinkNode*)(&p3));
    Insert_LinkList(list,0,(LinkNode*)(&p4));
    Insert_LinkList(list,0,(LinkNode*)(&p5));

    Print_LinkList(list,MyPrint);

    Remove_LinkList(list,2);
    Print_LinkList(list,MyPrint);
    std::cout<<Find_LinkList(list,(LinkNode*)(&p3))<<std::endl;
    std::cout<< "链表大小:" <<list->size<<std::endl;

    FreeSpace_LinkList(list);


    return 0;
}