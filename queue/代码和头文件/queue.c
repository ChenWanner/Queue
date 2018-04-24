#include"queue.h"
#include<windows.h>
int sor=5;
AQueue *AQ=NULL;
LQueue *LQ=NULL;


void InitAQueue(AQueue *Q,int sor)   //��ʼ������
{
   void *Array=NULL;
    if(sor == 1)
        Q->data_size=sizeof(char);
    if(sor == 2)
        Q->data_size=sizeof(int);
    Q->front=0;
    Q->rear=0;
    Array=malloc((Q->data_size)*MAXQUEUE);
    Q->data=Array;
}

void DestroyAQueue(AQueue *Q)   //���ٶ���
{
    free(Q->data);
    free(Q);
}

Status IsFullAQueue(const AQueue *Q)//�ж϶����Ƿ�Ϊ��
{
    if((Q->rear+1)%MAXQUEUE==Q->front)
      return TRUE;
      return FLASE;
}

Status IsEmptyAQueue(const AQueue *Q)  //�ж϶����Ƿ�Ϊ��
{
     if(Q->front == Q->rear)
        return TRUE;
    return FLASE;

}



Status GetHeadAQueue(AQueue *Q, void *e)  //��ȡ��ͷԪ��
{
    if(IsEmptyAQueue(Q))
    {
        return FLASE;
    }
    void *addr;
    addr=(char*)(Q->data)+(Q->front)*Q->data_size;
    memcpy(e,addr,Q->data_size);
    return TRUE;
}

int LengthAQueue(AQueue *Q)   //�������еĳ���
{
    if(IsEmptyAQueue(Q))
       return 0;
     else
        return((Q->rear-Q->front+MAXQUEUE)%MAXQUEUE);
}

Status EnAQueue(AQueue *Q, void *data)  //���
{
    if(IsFullAQueue(Q))
    {
        printf("��������!\n");
        return FLASE;
    }
    void *addr;
    addr=(char*)(Q->data)+(Q->rear)*(Q->data_size);
    memcpy(addr,data,Q->data_size);
    Q->rear++;
    return TRUE;
}

Status DeAQueue(AQueue *Q,void *data)  //����
{
    if(IsEmptyAQueue(Q))
    {
        printf("�����ѿ�!\n");
        return FLASE;
    }
    void *ar;
    ar=(char*)(Q->data)+(Q->front)*(Q->data_size);
    memcpy(data,ar,Q->data_size);
    Q->front=(Q->front+1)%MAXQUEUE;

    return TRUE;
}

void ClearAQueue(AQueue *Q)   //�������
{
   Q->front=0;
   Q->rear=0;
}

Status TraverseAQueue(const AQueue *Q, void (*foo)(AQueue *Q,void *q))  //��������
{
   if((Q == NULL) || IsEmptyAQueue(Q))
        return 0;
    int i,j=0,k=0;
    void *addr;
    i=Q->front;
    while(i < Q->rear)
    {
        addr=(char*)(Q->data)+i*(Q->data_size);
        foo(Q,addr);
        i++;
        k++;
    }
    return TRUE;

}

void APrint(AQueue *Q,void *q)   //��������е�Ԫ��
{

   int a;
    char b;
    if(Q->data_size == sizeof(char))
    {
        memcpy(&b,q,Q->data_size);
        printf("%c ",b);
    }
    if(Q->data_size == sizeof(int))
    {
        memcpy(&a,q,Q->data_size);
        printf("%d ",a);
    }

}

void InitLQueue(LQueue *Q,int sor)     //��ʼ������
{
    if(sor == 1)
        Q->data_size=sizeof(char);
    if(sor == 2)
        Q->data_size=sizeof(int);
    Node *p;
    p=(Node*)malloc(sizeof(Node));
    p->next=NULL;
    p->data=malloc(Q->data_size);
    Q->front=p;
    Q->rear=p;
     Q->length=0;
}

void DestroyLQueue(LQueue *Q)  //���ٶ���
{
    Node *p1,*p2;
    p1=Q->front;
    while(p1!=NULL)
    {
        p2=p1->next;
        free(p1);
        p1=p2;
    }
    free(Q);

}


Status IsEmptyLQueue(const LQueue *Q)  //�ж϶����Ƿ�Ϊ��
{
    if(Q->front == Q->rear)
        return TRUE;
   else
    return FLASE;
}

Status GetHeadLQueue(LQueue *Q, void *e)  //��ȡ���еĶ�ͷ
{
    if((Q == NULL) || IsEmptyLQueue(Q))
        return FALSE;
    Node *p=Q->front->next;
    memcpy(e,p->data,Q->data_size);
    return TRUE;

}

int LengthLQueue(LQueue *Q)  //�������еĳ���
{
    if(Q!=NULL)
        return Q->length;
    return 0;
}

Status EnLQueue(LQueue *Q,void *data)   //���
{
    Node *p;
    p=(Node*)malloc(sizeof(Node));
    p->data=malloc(Q->data_size);
    if((Q == NULL) || (p == NULL) || (p->data == NULL))
        return FLASE;
    p->next=NULL;
    (Q->rear)->next=p;
 memcpy(p->data,data,Q->data_size);
    Q->rear=p;
    Q->length++;
    return TRUE;
}

Status DeLQueue(LQueue *Q,void *data)  //����
{
    if((Q == NULL) || IsEmptyLQueue(Q))
        return FLASE;
    Node *p=Q->front->next;
    memcpy(data,p->data,Q->data_size);
    free(Q->front);
    Q->front=p;
    Q->length--;
    return TRUE;
}

void ClearLQueue(LQueue *Q)    //�������
{
    Node *p=Q->front->next;
    while(Q->front!=Q->rear)
    {
        free(Q->front);
        Q->front=p;
        p=p->next;
    }
    Q->length=0;
}


Status TraverseLQueue(const LQueue *Q,void (*foo)(LQueue *Q,void *q))  //��������
{
    if((Q == NULL) || (IsEmptyLQueue(Q)))
        return FLASE;
    int j=0,k=0;
    Node *p;
    p=Q->front;
    while(p!=Q->rear)
    {
        p=p->next;
        foo(Q,p->data);
        k++;
    }
    return TRUE;
}

void LPrint(LQueue *Q,void *q)  //��������е�Ԫ��
{
    int a;
    char b;
    if(Q->data_size == sizeof(int))
    {
        memcpy(&a,q,Q->data_size);
        printf("%d ",a);
    }
    if(Q->data_size == sizeof(char))
    {
        memcpy(&b,q,Q->data_size);
        printf("%c ",b);
    }
}

void AQUEUE()     //ѡȡ˳�����ʱ,����˳������Լ���˳����н��в����ĺ���
{
    int t,st;
    int x;
    char c;
    void (*foo)(AQueue *Q,void *q);
    foo=&APrint;
    printf("��ѡ��Զ��еĲ���:\n");
    printf("1.��������   2.���ٶ���   3.��ȡ����Ԫ�� \n");
    printf("4.�鿴���г���    5.����һ��Ԫ��   6.����һ��Ԫ��     7.��ն���\n");
    printf("8.��������  9.�˳�\n");
    scanf("%d",&t);   //����ѡ��
    system("cls");
    switch(t)
    {
        case 1:   //�ɶ���
            printf("��ѡ����������ݵ�����:\n   1.char��    2.int��\n");
            scanf("%d",&sor);       /*����ѡ������ ��ͬ���͵Ķ���*/
            while(sor!=1&&sor!=2)     //�ж�����������Ƿ��д�
            {
                printf("�������,����������:");
                scanf("%d",&sor);
            }
             InitAQueue(AQ,sor);
              printf("���д����ɹ�");
          break;

        case 2:     //���ٶ���
             if(sor == 5)    //���ж��Ƿ��Ѿ������˶���,��û����Ҫ�������ɶ���
            {
                printf("��δ��������,���ȴ�������");
                 break;
            }
            DestroyAQueue(AQ);
            printf("���ٳɹ�,�������");  //�������ٺ�,�������
            getchar();
           return;
          break;

        case 3:     //��ȡ���еĶ���
            if(sor == 5)             //���ж��Ƿ��Ѿ������˶���,��û����Ҫ�������ɶ���
            {
                printf("��δ��������,���ȴ�������");
                 break;
            }
            if(sor == 1)
                {

                    st=GetHeadAQueue(AQ,&c);
                    if(st == TRUE)
                        printf("����Ԫ��Ϊ%c",c);
                    else
                        printf("����Ϊ��");
                }
                if(sor == 2)
                {
                    st=GetHeadAQueue(AQ,&x);
                    if(st == TRUE)
                        printf("����Ԫ��Ϊ%d",x);
                    else
                        printf("����Ϊ��");

                }

          break;

        case 4:
             if(sor == 5)   //���ж��Ƿ��Ѿ������˶���,��û����Ҫ�������ɶ���
            {
                printf("��δ��������,���ȴ�������");
                 break;
            }
            x=LengthAQueue(AQ);
           printf("���г���Ϊ%d",x);
          break;
        case 5:
           if(sor == 5)   //���ж��Ƿ��Ѿ������˶���,��û����Ҫ�������ɶ���
            {
                printf("��δ��������,���ȴ�������");
                 break;
            }
                getchar();
                if(sor == 1)
                {
                    printf("��������ӵ�����(һ��ֻ����һ��)��");
                    scanf("%c",&c);
                    getchar();
                    EnAQueue(AQ,&c);
                    printf("�ɹ���ӣ�");
                }
                if(sor == 2)
                {
                    printf("��������ӵ�����(һ��ֻ����һ��)��");
                    scanf("%d",&x);
                    getchar();
                    EnAQueue(AQ,&x);
                    printf("�ɹ���ӣ�");
                 }

        break;
        case 6:    //����
            if(sor == 5)   //���ж��Ƿ��Ѿ������˶���,��û����Ҫ�������ɶ���
            {
                printf("��δ��������,���ȴ�������");
                 break;
            }
           if(sor == 1)
                {
                   if(DeAQueue(AQ,&c)==TRUE)
                        printf("����Ԫ��Ϊ��%c",c);
                    else
                        printf("����Ϊ��,�޷�����");
                }
                if(sor == 2)
                {
                    if(DeAQueue(AQ,&x)==TRUE)
                    printf("����Ԫ��Ϊ��%d",x);
                    else
                        printf("����Ϊ��,�޷�����");
                }

              break;
        case 7:  //�������
            if(sor == 5)   //���ж��Ƿ��Ѿ������˶���,��û����Ҫ�������ɶ���
            {
                printf("��δ��������,���ȴ�������");
                 break;
            }
            ClearAQueue(AQ);
            printf("����ɹ�!");
         break;

        case 8:
            if(sor == 5)   //���ж��Ƿ��Ѿ������˶���,��û����Ҫ�������ɶ���
            {
                printf("��δ��������,���ȴ�������");
                 break;
            }
            if(TraverseAQueue(AQ,foo)==FLASE)
            {
                printf("����Ϊ�ն���");
            }
         break;
        case 9:
            exit(1);
            break;
        default:
            printf("�����д�,������ѡ��");

    }
    Sleep(1000);
    system("cls");   //�����Ļ
    AQUEUE();

}


void  LQUEUE()     //���������ӵ������Լ������
{
    int t,st;
    int x;
    char c;
    void (*foo)(LQueue *Q,void *q);
    foo=&LPrint;
     printf("��ѡ��Զ��еĲ���:\n");
    printf("1.��������   2.���ٶ���   3.��ȡ����Ԫ�� \n");
    printf("4.�鿴���г���    5.����һ��Ԫ��   6.����һ��Ԫ��     7.��ն���\n");
    printf("8.��������  9.�˳�\n");
    scanf("%d",&t);
    system("cls");
    switch(t)
    {
        case 1:
            printf("��ѡ����������ݵ�����:\n   1.char��    2.int��\n");
            scanf("%d",&sor);
            while(sor!=1&&sor!=2)
            {
                printf("�������,����������:");
                scanf("%d",&sor);
            }
             InitLQueue(LQ,sor);
              printf("���д����ɹ�");
          break;

        case 2:
             if(sor == 5)
            {
                printf("��δ��������,���ȴ�������");
                 break;
            }
            DestroyLQueue(LQ);
            printf("���ٳɹ�,�������");
            getchar();
            return;
          break;

        case 3:

            if(sor == 5)
            {
                printf("��δ��������,���ȴ�������");
                 break;
            }
            if(sor == 1)
                {

                    st=GetHeadLQueue(LQ,&c);
                    if(st == TRUE)
                        printf("����Ԫ��Ϊ%c",c);
                    else
                        printf("����Ϊ��");
                }
                if(sor == 2)
                {
                    st=GetHeadLQueue(LQ,&x);
                if(st == TRUE)
                        printf("����Ԫ��Ϊ%d",x);
                    else

                        printf("����Ϊ��");
                }


          break;

        case 4:
            if(sor == 5)
            {
                printf("��δ��������,���ȴ�������");
                 break;
            }
            x=LengthLQueue(LQ);
           printf("���г���Ϊ%d",x);
          break;
         case 5:
              if(sor == 5)
            {
                printf("��δ��������,���ȴ�������");
                 break;
            }
              getchar();

                if(sor == 1)
                {
                    printf("��������ӵ�����(һ��ֻ����һ��)��");
                    scanf("%c",&c);
                    getchar();
                    EnLQueue(LQ,&c);
                    printf("�ɹ���ӣ�");
                }
                if(sor == 2)
                {
                    printf("��������ӵ�����(һ��ֻ����һ��)��");
                    scanf("%d",&x);
                    getchar();
                    EnLQueue(LQ,&x);
                    printf("�ɹ���ӣ�");
                }

        break;
        case 6:
            if(sor == 5)
            {
                printf("��δ��������,���ȴ�������");
                 break;
            }
           if(sor == 1)
                {
                   if(DeLQueue(LQ,&c)==TRUE)
                      printf("����Ԫ��Ϊ��%c",c);
                    else
                       printf("����Ϊ��,�޷�����");
                }
                if(sor == 2)
                {
                   if(DeLQueue(LQ,&x)==TRUE)
                    printf("����Ԫ��Ϊ��%d",x);
                    else
                    printf("����Ϊ��,�޷�����");
                }

              break;
        case 7:
             if(sor == 5)
            {
                printf("��δ��������,���ȴ�������");
                 break;
            }
            ClearLQueue(LQ);
            printf("����ɹ�!");
         break;

        case 8:
             if(sor == 5)
            {
                printf("��δ��������,���ȴ�������");
                 break;
            }
            if(TraverseLQueue(LQ,foo)==FLASE)
            {
                printf("����Ϊ�ն���");
            }
         break;
        case 9:
            exit(1);
            break;
        default:
            printf("�����д�,������ѡ��");

    }
    Sleep(1000);
    system("cls");
    LQUEUE();


}










