#include"queue.h"
#include<windows.h>
int sor=5;
AQueue *AQ=NULL;
LQueue *LQ=NULL;


void InitAQueue(AQueue *Q,int sor)   //初始化队列
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

void DestroyAQueue(AQueue *Q)   //销毁队列
{
    free(Q->data);
    free(Q);
}

Status IsFullAQueue(const AQueue *Q)//判断队列是否为满
{
    if((Q->rear+1)%MAXQUEUE==Q->front)
      return TRUE;
      return FLASE;
}

Status IsEmptyAQueue(const AQueue *Q)  //判断队列是否为空
{
     if(Q->front == Q->rear)
        return TRUE;
    return FLASE;

}



Status GetHeadAQueue(AQueue *Q, void *e)  //获取队头元素
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

int LengthAQueue(AQueue *Q)   //测量队列的长度
{
    if(IsEmptyAQueue(Q))
       return 0;
     else
        return((Q->rear-Q->front+MAXQUEUE)%MAXQUEUE);
}

Status EnAQueue(AQueue *Q, void *data)  //入队
{
    if(IsFullAQueue(Q))
    {
        printf("队列已满!\n");
        return FLASE;
    }
    void *addr;
    addr=(char*)(Q->data)+(Q->rear)*(Q->data_size);
    memcpy(addr,data,Q->data_size);
    Q->rear++;
    return TRUE;
}

Status DeAQueue(AQueue *Q,void *data)  //出队
{
    if(IsEmptyAQueue(Q))
    {
        printf("队列已空!\n");
        return FLASE;
    }
    void *ar;
    ar=(char*)(Q->data)+(Q->front)*(Q->data_size);
    memcpy(data,ar,Q->data_size);
    Q->front=(Q->front+1)%MAXQUEUE;

    return TRUE;
}

void ClearAQueue(AQueue *Q)   //清除队列
{
   Q->front=0;
   Q->rear=0;
}

Status TraverseAQueue(const AQueue *Q, void (*foo)(AQueue *Q,void *q))  //遍历队列
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

void APrint(AQueue *Q,void *q)   //输出队列中的元素
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

void InitLQueue(LQueue *Q,int sor)     //初始化队列
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

void DestroyLQueue(LQueue *Q)  //销毁队列
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


Status IsEmptyLQueue(const LQueue *Q)  //判断队列是否为空
{
    if(Q->front == Q->rear)
        return TRUE;
   else
    return FLASE;
}

Status GetHeadLQueue(LQueue *Q, void *e)  //获取队列的队头
{
    if((Q == NULL) || IsEmptyLQueue(Q))
        return FALSE;
    Node *p=Q->front->next;
    memcpy(e,p->data,Q->data_size);
    return TRUE;

}

int LengthLQueue(LQueue *Q)  //测量队列的长度
{
    if(Q!=NULL)
        return Q->length;
    return 0;
}

Status EnLQueue(LQueue *Q,void *data)   //入队
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

Status DeLQueue(LQueue *Q,void *data)  //出队
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

void ClearLQueue(LQueue *Q)    //清除队列
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


Status TraverseLQueue(const LQueue *Q,void (*foo)(LQueue *Q,void *q))  //遍历队列
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

void LPrint(LQueue *Q,void *q)  //输出队列中的元素
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

void AQUEUE()     //选取顺序队列时,生成顺序队列以及对顺序队列进行操作的函数
{
    int t,st;
    int x;
    char c;
    void (*foo)(AQueue *Q,void *q);
    foo=&APrint;
    printf("请选择对队列的操作:\n");
    printf("1.创建队列   2.销毁队列   3.获取队首元素 \n");
    printf("4.查看队列长度    5.进队一个元素   6.出队一个元素     7.清空队列\n");
    printf("8.遍历队列  9.退出\n");
    scanf("%d",&t);   //输入选择
    system("cls");
    switch(t)
    {
        case 1:   //成队列
            printf("请选择队列中数据的类型:\n   1.char型    2.int型\n");
            scanf("%d",&sor);       /*根据选择生成 不同类型的队列*/
            while(sor!=1&&sor!=2)     //判断输入的数字是否有错
            {
                printf("输入错误,请重新输入:");
                scanf("%d",&sor);
            }
             InitAQueue(AQ,sor);
              printf("队列创建成功");
          break;

        case 2:     //销毁队列
             if(sor == 5)    //先判断是否已经生成了队列,若没有着要求先生成队列
            {
                printf("还未创建队列,请先创建队列");
                 break;
            }
            DestroyAQueue(AQ);
            printf("销毁成功,程序结束");  //队列销毁后,程序结束
            getchar();
           return;
          break;

        case 3:     //获取队列的队首
            if(sor == 5)             //先判断是否已经生成了队列,若没有着要求先生成队列
            {
                printf("还未创建队列,请先创建队列");
                 break;
            }
            if(sor == 1)
                {

                    st=GetHeadAQueue(AQ,&c);
                    if(st == TRUE)
                        printf("队首元素为%c",c);
                    else
                        printf("队列为空");
                }
                if(sor == 2)
                {
                    st=GetHeadAQueue(AQ,&x);
                    if(st == TRUE)
                        printf("队首元素为%d",x);
                    else
                        printf("队列为空");

                }

          break;

        case 4:
             if(sor == 5)   //先判断是否已经生成了队列,若没有着要求先生成队列
            {
                printf("还未创建队列,请先创建队列");
                 break;
            }
            x=LengthAQueue(AQ);
           printf("队列长度为%d",x);
          break;
        case 5:
           if(sor == 5)   //先判断是否已经生成了队列,若没有着要求先生成队列
            {
                printf("还未创建队列,请先创建队列");
                 break;
            }
                getchar();
                if(sor == 1)
                {
                    printf("请输入进队的数据(一次只输入一个)：");
                    scanf("%c",&c);
                    getchar();
                    EnAQueue(AQ,&c);
                    printf("成功入队！");
                }
                if(sor == 2)
                {
                    printf("请输入进队的数据(一次只输入一个)：");
                    scanf("%d",&x);
                    getchar();
                    EnAQueue(AQ,&x);
                    printf("成功入队！");
                 }

        break;
        case 6:    //出队
            if(sor == 5)   //先判断是否已经生成了队列,若没有着要求先生成队列
            {
                printf("还未创建队列,请先创建队列");
                 break;
            }
           if(sor == 1)
                {
                   if(DeAQueue(AQ,&c)==TRUE)
                        printf("出队元素为：%c",c);
                    else
                        printf("队列为空,无法出队");
                }
                if(sor == 2)
                {
                    if(DeAQueue(AQ,&x)==TRUE)
                    printf("出队元素为：%d",x);
                    else
                        printf("队列为空,无法出队");
                }

              break;
        case 7:  //清除队列
            if(sor == 5)   //先判断是否已经生成了队列,若没有着要求先生成队列
            {
                printf("还未创建队列,请先创建队列");
                 break;
            }
            ClearAQueue(AQ);
            printf("清除成功!");
         break;

        case 8:
            if(sor == 5)   //先判断是否已经生成了队列,若没有着要求先生成队列
            {
                printf("还未创建队列,请先创建队列");
                 break;
            }
            if(TraverseAQueue(AQ,foo)==FLASE)
            {
                printf("队列为空队列");
            }
         break;
        case 9:
            exit(1);
            break;
        default:
            printf("输入有错,请重新选择");

    }
    Sleep(1000);
    system("cls");   //清除屏幕
    AQUEUE();

}


void  LQUEUE()     //以下是链队的生成以及其操作
{
    int t,st;
    int x;
    char c;
    void (*foo)(LQueue *Q,void *q);
    foo=&LPrint;
     printf("请选择对队列的操作:\n");
    printf("1.创建队列   2.销毁队列   3.获取队首元素 \n");
    printf("4.查看队列长度    5.进队一个元素   6.出队一个元素     7.清空队列\n");
    printf("8.遍历队列  9.退出\n");
    scanf("%d",&t);
    system("cls");
    switch(t)
    {
        case 1:
            printf("请选择队列中数据的类型:\n   1.char型    2.int型\n");
            scanf("%d",&sor);
            while(sor!=1&&sor!=2)
            {
                printf("输入错误,请重新输入:");
                scanf("%d",&sor);
            }
             InitLQueue(LQ,sor);
              printf("队列创建成功");
          break;

        case 2:
             if(sor == 5)
            {
                printf("还未创建队列,请先创建队列");
                 break;
            }
            DestroyLQueue(LQ);
            printf("销毁成功,程序结束");
            getchar();
            return;
          break;

        case 3:

            if(sor == 5)
            {
                printf("还未创建队列,请先创建队列");
                 break;
            }
            if(sor == 1)
                {

                    st=GetHeadLQueue(LQ,&c);
                    if(st == TRUE)
                        printf("队首元素为%c",c);
                    else
                        printf("队列为空");
                }
                if(sor == 2)
                {
                    st=GetHeadLQueue(LQ,&x);
                if(st == TRUE)
                        printf("队首元素为%d",x);
                    else

                        printf("队列为空");
                }


          break;

        case 4:
            if(sor == 5)
            {
                printf("还未创建队列,请先创建队列");
                 break;
            }
            x=LengthLQueue(LQ);
           printf("队列长度为%d",x);
          break;
         case 5:
              if(sor == 5)
            {
                printf("还未创建队列,请先创建队列");
                 break;
            }
              getchar();

                if(sor == 1)
                {
                    printf("请输入进队的数据(一次只输入一个)：");
                    scanf("%c",&c);
                    getchar();
                    EnLQueue(LQ,&c);
                    printf("成功入队！");
                }
                if(sor == 2)
                {
                    printf("请输入进队的数据(一次只输入一个)：");
                    scanf("%d",&x);
                    getchar();
                    EnLQueue(LQ,&x);
                    printf("成功入队！");
                }

        break;
        case 6:
            if(sor == 5)
            {
                printf("还未创建队列,请先创建队列");
                 break;
            }
           if(sor == 1)
                {
                   if(DeLQueue(LQ,&c)==TRUE)
                      printf("出队元素为：%c",c);
                    else
                       printf("队列为空,无法出队");
                }
                if(sor == 2)
                {
                   if(DeLQueue(LQ,&x)==TRUE)
                    printf("出队元素为：%d",x);
                    else
                    printf("队列为空,无法出队");
                }

              break;
        case 7:
             if(sor == 5)
            {
                printf("还未创建队列,请先创建队列");
                 break;
            }
            ClearLQueue(LQ);
            printf("清除成功!");
         break;

        case 8:
             if(sor == 5)
            {
                printf("还未创建队列,请先创建队列");
                 break;
            }
            if(TraverseLQueue(LQ,foo)==FLASE)
            {
                printf("队列为空队列");
            }
         break;
        case 9:
            exit(1);
            break;
        default:
            printf("输入有错,请重新选择");

    }
    Sleep(1000);
    system("cls");
    LQUEUE();


}










