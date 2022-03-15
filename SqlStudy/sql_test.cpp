//
// Created by 老李 on 2022/3/15.
//

#include "sql_test.h"

//#include <bits/stdc++.h> mac原本是没有万能头的 需要安装mingw64才能使用这个文件
using namespace std;

bool ConnectMysql();//连接数据库
void FreeConnect();//释放资源

MYSQL mysql;
MYSQL_RES *res;//这个结构代表返回行的一个查询结果集
MYSQL_ROW column;//一个行数据的类型安全(type-safe)的表示



//连接数据库
bool ConnectMysql() {
    mysql_init(&mysql);//初始化mysql
    if (!(mysql_real_connect(&mysql,
                             "localhost",//主机
                             "root",//用户名
                             "admin1234",//密码
                             "test",//数据库名 必须是已经存在的 我的mysql大小写不敏感
                             3306,//端口号 默认的0或者3306
                             NULL, 0//最后两个参数的常用写法 几乎都是这两个
    ))) {
        cout << "Error connecting to database:" + (string) mysql_error(&mysql) << endl;
        return false;
    } else {
        cout << "Connected Successful..." << endl;
        return true;
    }
}

//释放资源
void FreeConnect() {
    mysql_free_result(res);
    mysql_close(&mysql);
    cout << "Free Successful" << endl;
}

//测试代码
//int main() {
//    ConnectMysql();
//    FreeConnect();
//}