//
// Created by 老李 on 2022/3/15.
//

//#include "LinkList.h"
//
////初始化链表
//LinkList * Init_LinkList(){
//    //分配内存
//    LinkList* list = (LinkList*)malloc(sizeof(LinkList));
//    list->size = 0;
//
//    //头节点 是不保存数据信息
//    list->head = (LinkNode*)malloc(sizeof(LinkNode));
//    list->head->data = NULL;
//    list->head->next = NULL;
//    return list;
//}
////指定位置插入
//void Insert_LinkList(LinkList* list,int pos,void *data){
//    if(list ==NULL){
//        return;
//    }
//    if(data ==NULL){
//        return;
//    }
//    //友好的处理，pos越界
//    if(pos <0 ||pos >list->size){
//        pos = list->size;
//    }
//    //创建新的节点
//    LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
//    newnode->data = data;
//    newnode->next = NULL;
//
//    //找节点 辅助指针变量
//    LinkNode *pCurrent = list->head;
//    for(int i = 0;i < pos; i++){
//        pCurrent = pCurrent->next;
//    }
//    //新节点入链表
//    newnode->next = pCurrent->next;
//    pCurrent->next = newnode;
//
//    list->size++;
//}
////删除指定位置的值
//void RemoveByPos_LinkList(LinkList* list,int pos){
//    if(list ==NULL){
//        return;
//    }
//    if(pos<0 ||pos >= list->size){
//        return;
//    }
//    LinkNode *pCurrent = (LinkNode*)malloc(sizeof(LinkNode));
//    pCurrent->next = list->head;
//    for(int i = 0;i<pos;i++){
//        pCurrent = pCurrent->next;
//    }
//    //缓存删除的节点
//    LinkNode *pDel = pCurrent->next;
//    pCurrent->next = pDel->next;
//    free(pDel);
//    list->size--;
//}
////获取长度
//int Size_LinkList(LinkList* list){
//    return list->size;
//}
////查找
//int Find_LinkList(LinkList* list,void* data){
//    if(list==NULL){
//        return -1;
//    }
//    if(data ==NULL){
//        return -1;
//    }
//    //遍历查找
//    LinkNode *pCurrent = list->head->next;
//    int pos;
//    for(int i = 0;i<list->size;i++){
//        if( pCurrent->data==data){
//            pos = i;
//            break;
//        }
//        pCurrent = pCurrent->next;
//    }
//    return pos;
//}
////打印链表节点
//void Print_LinkList(LinkList* list,PRINTLINKNODE print){
//    if(list ==NULL){
//        return;
//    }
//    LinkNode *pCurrent = list->head->next;
//    while (pCurrent !=NULL){
//        print(pCurrent->data);
//        pCurrent = pCurrent->next;
//    }
//}
////返回第一个节点
//void* Front_LinkList(LinkList* list){
//    return list->head->next->data;
//}
////释放链表内存
//void FreeSpace_Linklist(LinkList* list){
//    if(list ==NULL){
//        return;
//    }
//    //辅助指针变量
//    LinkNode *pCurrent = list->head;
//    while (pCurrent != NULL){
//        //缓存下一个节点
//        LinkNode *pNext = pCurrent->next;
//        free(pCurrent);
//        pCurrent = pNext;
//    }
//    //释放链表内存
//    list->size = 0;
//    free(list);
//}
//
//typedef struct PERSON{
//    char name[64];
//    int age;
//    int score;
//}Person;
//
////打印函数
//void MyPrint(void* data){
//    Person *p = (Person*)data;
//    std::cout << "Name:" << p->name <<std::endl;
//    std::cout << "Age:" << p->age<<std::endl;
//    std::cout << "Score:" << p->score<<std::endl;
//
//}
//
////int main(){
////    //创建链表
////    LinkList *list = Init_LinkList();
////
////    //创建数据
////    Person p1 = {"aaa",18,100};
////    Person p2 = {"bbb",18,100};
////    Person p3 = {"ccc",18,100};
////    Person p4 = {"ddd",18,100};
////    Person p5 = {"eee",18,100};
////
////    //数据插入链表
////    Insert_LinkList(list,0,&p1);
////    Insert_LinkList(list,0,&p2);
////    Insert_LinkList(list,0,&p3);
////    Insert_LinkList(list,0,&p4);
////    Insert_LinkList(list,0,&p5);
////
////    //打印
////    Print_LinkList(list,MyPrint);
////    std::cout << "======================="<<std::endl;
////    std::cout<<Front_LinkList(list);
////    std::cout << "======================="<<std::endl;
////    RemoveByPos_LinkList(list,3);
////
////    Print_LinkList(list,MyPrint);
////    FreeSpace_Linklist(list);
//}