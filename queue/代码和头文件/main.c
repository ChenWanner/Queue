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
   AQ=(AQueue*)malloc(sizeof(AQueue));     //�ȶ�ָ�������ʼ��,���򲻰�ȫ,��������
    LQ=(LQueue*)malloc(sizeof(LQueue));           //�ȶ�ָ�������ʼ��,���򲻰�ȫ,��������
   printf("��ѡ�����ɵĶ��е�����:\n");
 restart:  printf("1.˳�����   2.��ʽ���� \n");
   scanf("%d",&t);
   while((t!=1)&&(t!=2))
   {
       printf("�������,������ѡ��:\n");   //�ж������ѡ���Ƿ�����
       goto restart;
   }
   if(t==1)               //˳�����
      AQUEUE();
   if(t==2)           //����
      LQUEUE();
    return 0;
}


