#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"queue.h"
extern sor;
extern LQ;
extern AQ;
int main()
{
   int t;
   AQ=(AQueue*)malloc(sizeof(AQueue));     //先对指针变量初始化,否则不安全,程序会崩溃
    LQ=(LQueue*)malloc(sizeof(LQueue));           //先对指针变量初始化,否则不安全,程序会崩溃
   printf("请选择生成的队列的类型:\n");
 restart:  printf("1.顺序队列   2.链式队列 \n");
   scanf("%d",&t);
   while((t!=1)&&(t!=2))
   {
       printf("输入错误,请重新选择:\n");   //判断输入的选项是否有误
       goto restart;
   }
   if(t==1)               //顺序队列
      AQUEUE();
   if(t==2)           //链队
      LQUEUE();
    return 0;
}


