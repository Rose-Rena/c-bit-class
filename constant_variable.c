/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
//作用域（scope）和生命周期（lifetime）

//作用域
//局部变量的作用域：就是变量所在的局部范围
//全局变量的作用域捏：整个工程
int g_val = 2021; //全局变量

// //同一个project不同文件的话，想得到变量要声明一下变量（意思就是要知道有这么一个东西）
// //extern keyword
// extern int gg_val;

int main()
{
    printf("1:%d\n", g_val);
    printf("hehe\n");
    {
    printf("2:%d\n", g_val);
    int a = 10;
    printf("a=%d\n", a);
    }
    printf("3:%d\n", g_val);
    return 0;
}

//生命周期
//变量的生命周期：变量的创建和销毁之间的时间段
//局部变量的生命周期：进入局部范围（所在范围）生命开始，出局部范围生命结束
//全局变量的生命周期：程序的生命周期



