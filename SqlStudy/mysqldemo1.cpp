//
// Created by 老李 on 2022/3/18.
//

#include "mysqldemo1.h"
#include "mysql.h"
#include "iostream"
//#include "stdio.h"

#include <iomanip>

using namespace std;

MYSQL mysql;//定义mysql句柄
MYSQL_RES *res;//定义结果集
char query[150];//用于写sql语句
MYSQL_ROW column;



bool ConnectDatabase();
void freeConnect(); //释放连接
bool QueryDatabase1();//查询1
bool QueryDatabase2();//查询2

bool ConnectDatabase(){
    mysql_init(&mysql);
    //数据库连接
    if(!(mysql_real_connect(&mysql,"localhost","root","admin1234","atguigudb",3306,NULL,0))){
                          //如果连接失败
                          cout << "连接失败,失败原因：" << mysql_error(&mysql);
                          return -1;
                          } else {
        cout << "连接成功" << endl;
        return 0;
    }
}

void freeConnect(){
    mysql_free_result(res);
    mysql_close(&mysql);
}

bool QueryDatabase1() {
    //sql语句写入query
    strcpy(query, "select *from employees");
    if (mysql_query(&mysql, query)) {
        cout << "查询失败,失败原因:" << mysql_error(&mysql) << endl;
        return false;
    } else {
        cout << "查询成功" << endl;
    }

    //获取结果集，查询失败和查询成功的情况
    //返回sql语句结束后的结果集,mysql_store_result,结果为1表示失败，结果为0表示成功
    if (!(res = mysql_store_result(&mysql))) {
        //失败的情况
        cout << "获取失败,原因" << mysql_error(&mysql) << endl;
        return false;
    }
    cout << "获取成功" << endl;
    cout << "数据行数" << mysql_affected_rows(&mysql) << endl;
    char *str_field[32];
    for (int i = 0; i < mysql_num_fields(res); i++) {
        str_field[i] = mysql_fetch_field(res)->name;
//        cout << "字段名" << str_field[i] << endl;
    }
    for (int i=0;i< mysql_num_fields(res);i++){
       // cout << str_field[i] << "\t";
        printf("%-15s\t",str_field[i]);
    }
    while ((column = mysql_fetch_row(res))){
        cout << endl;
        for (int i = 0; i<mysql_num_fields(res); i++)
           //cout<< column[i] ;
            printf("%-15s\t", column[i]);
        cout<< endl;

    }

//    while ((column = mysql_fetch_row(res)))
//    {
//        for (int i = 0; i<mysql_num_fields(res); i++)
//            printf("%10s\t", column[i]);
//        printf("\n");
//    }

    return true;
}

bool QueryDatabase2(){

    if(mysql_query(&mysql,"select employee_id,last_name,salary\n"
                          "from employees\n"
                          "order by salary desc ")){
        cout << "查询失败，失败原因:" << mysql_error(&mysql);
        return false;
    } else{
        cout << "查询成功";
    }
    if (!(res = mysql_store_result(&mysql))) {
        //失败的情况
        cout << "获取失败,原因" << mysql_error(&mysql) << endl;
        return false;
    }
    cout << "获取成功";
    cout << "数据行数" << mysql_affected_rows(&mysql) << endl;
    char *strfield[32];

    for(int i = 0; i< mysql_num_fields(res);i++){
        strfield[i] = mysql_fetch_field(res)->name;
        printf("%15s\t",strfield[i]);
    }
    while ((column = mysql_fetch_row(res))){
        cout << endl;
        for(int i = 0;i< mysql_num_fields(res);i++){
            printf("%15s\t",column[i]);
        }
        cout << endl;
    }
    return true;
}


int main(){
    ConnectDatabase();
    cout<< "=========================================="<< endl;
    QueryDatabase1();
    cout<< "=========================================="<< endl;
    QueryDatabase2();
    cout<< "=========================================="<< endl;
    freeConnect();
    return 0;



}