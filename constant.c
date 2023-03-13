/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
// C语言中的常量分为以下几种：
//     -字面常量
//     -const 修饰的常变量
//     -#define 定义的标识符常量
//     -枚举常量
    
#include <stdio.h>

int main()
{
//1. 字面常量，存在但好像没什么意义
    // 3.14；//浮点型常量
    // 10;//整型常量
    // 'a';//字符常量
    // "abcdef";//字符串常量
    // return 0;
    
//2. const 修饰的常变量
    // int num = 10;//变量
    // num = 20;
    // printf("num = %d\n", num);//20
    // const int num = 10;//num被const修饰，不能被修改，常变量 - 具有常属性（不能被改变的属性）
    // //它现在不能变了，但它还是个变量
    // int arr[10] = {0}; //10 elements
    // const int n = 10;
    // int arr2[n] = {0};//报错，n必须是常量，它是变量就不行
    //说明不是常量，本质属性是变量，只是被const修饰了一下，根上还是个变量，需要常量的地方它不行
    
//3.  #define 定义的标识符常量
//   #define MAX 10000;
//   int n = MAX;
//   MAX不能改
//   //n=10000
//4. 枚举常量
    //可以一一列举的常量
    enum Sex s = MALE;
    // MALE = 3;//不能改
     return 0;
}

    //性别
    enum Sex
    {
        //这三个值是这种枚举类型的变量的未来可能取值，反正只能赋值这三个值里一个
        //这三个值就是枚举常量
        //枚举常量的值默认为从零开始
        MALE，//0 MALE = 3可以，但是是赋初值，这不是改变而是最开始的值，常量一开始也有值
        FEMALE，//1
        SECRET//2
    }
    