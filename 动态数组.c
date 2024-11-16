#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//动态数组的结构体
struct dynamicarray
{
    //真实在堆区开辟数组的指针
    void**paddr;
    //数组的容量
    int m_capacity;
    //数组的大小
    int m_size;
};
//初始化数组     参数 初始数组容量  返回值 结构体指针

struct dynamiarray*init_dynamincarray(int capacity)
{
    if(capacity<=0)
    {
        return NULL;
    }
    //给数组分配内存
    struct dynamicarray *arr=malloc(sizeof(struct dynamicarray));
    if(arr==NULL)
    {
        return NULL;
    }
    //给属性初始化
    arr->paddr=malloc(sizeof(void*)*capacity);//paddr是void*数组的指针
    //容量初始化return
    arr->m_capacity=capacity;
    //大小初始化
    arr->m_size=0;                                         
    return arr;
}

//插入数组  参数：数组的加结构体，需要插入的数
void insert_dynamicarray(struct dynamicarray*arr,void*date,int pos)
{
    if(arr==NULL)
    {
        return ;
    }
    if(date==NULL)
    {
        return ;
    }
    if(pos<0||pos>arr->m_size)
    {
        //尾插
        pos=arr->m_size;
    }
    //判断数组知否满了
    if(arr->m_size==arr->m_capacity)
    {
        //1计算内存新空间大小
        int newCapacity=arr->m_capacity*2;

        //2开辟新空间
        void ** newspace=malloc(sizeof(void*)*newCapacity);

        //3将原空间下的数据拷贝到新空间下
        memcpy(newspace,arr->paddr,sizeof(void*)*arr->m_capacity);

        //4释放原空间
        free(arr->paddr);

        //5更新指针指向和容量
        arr->paddr=newspace;
        arr->m_capacity=newCapacity;
    }
    //将新元素插入到数组的指定位置
    for(int i=arr->m_size-1;i>=pos;i--)
    {
        arr->paddr[i+1]=arr->paddr[i];
    }
    arr->paddr[pos]=date;
    //更新数组大小
    arr->m_size++;
}

//遍历函数
void foreach_dynamicArray(struct dynamicarray*arr,void(*myPrint)(void*))
{
    if(arr==NULL)
    return;
    for(int i=0;i<arr->m_size;i++)
    {
        myPrint(arr->paddr[i]);
    }
    return ;
}

//删除数组
//按照位置山从删除数据
void removeByPos_dynamicArray(struct dynamicarray*arr,int pos)
{
    if(arr==NULL)
    if(pos<0||pos>=arr->m_size)
    {
        //无效位置return
        return ;

    }
    for(int i=pos;i<arr->m_size;i++)
    {
        arr->paddr[i]=arr->paddr[i+1];
    }
    //更新数组的的大小
    arr->m_size--;
    return;
}

//按值方式删除数组
void removeByValue_dynamicArray(struct dynamicarray*arr,void*date,int (*mycompare)(void*,void*))
{
    if(arr==NULL)return ;
    if(date==NULL)return ;
    for(int i=0;i<arr->m_size;i++)
    {
        //if(arr->paddr==date)
        //利用回调对比函数 自定义如何对比数据
        if(mycompare(arr->paddr[i],date))
        {
            removeByPos_dynamicArray(arr,i);
            break;
        }

    }
    return ;
}

//销毁数组
void destroy_dynamicArray(struct dynamicarray*arr)
{
    if(arr==NULL)return ;
    //内部维护在堆区数组指针先释放
    if(arr->paddr!=NULL)
    {
        free(arr->paddr);
        arr->paddr=NULL;
    }
    free(arr);
    arr=NULL;
}
struct person
{
    char name[50];
    int age;
};
//-------------------------------------------------------------------------
//回调函数 打印数据
void printPerson(void*date)
{
    struct person*person=date;
    printf("name:%s  age:%d\n",person->name,person->age);
}
//回调函数 对比数据
int comparePerson(void*date1,void*date2)
{
    struct person*p1=date1;
    struct person*p2=date2;
   // if(strcmp(p1->name,p2->name)==0&&p1->age==p2->age)
 // return 1;
  //  else
   // return 0;  
   return strcmp(p1->name,p2->name)==0&&p1->age==p2->age;
}
//测试动态数组
void test01()
{
    //初始化动态数组
    struct dynamicarray*arr=init_dynamincarray(5);
    struct person p1={"赵云",18};
    struct person p2={"张飞",19};
    struct person p3={"关关羽",20};
    struct person p4={"刘备",18};
    struct person p5={"诸葛亮",22};
    struct person p6={"黄忠",17};
    printf("former_capasity:%d\n",arr->m_capacity);
    printf("size:%d\n",arr->m_size);

    //插入数据
    insert_dynamicarray(arr,&p1,0);
    insert_dynamicarray(arr,&p2,1);
    insert_dynamicarray(arr,&p3,-1);
    insert_dynamicarray(arr,&p4,1);
    insert_dynamicarray(arr,&p5,4);
    insert_dynamicarray(arr,&p6,5);

    foreach_dynamicArray(arr,printPerson);
    printf("now_capasity:%d\n",arr->m_capacity);
    printf("size:%d\n",arr->m_size);
    
    //按照位置删除诸葛亮法测试 
    removeByPos_dynamicArray(arr,4);
    foreach_dynamicArray(arr,printPerson);
    printf("\n");
    //按照值删除刘备
    struct person p={"刘备",18};
    removeByValue_dynamicArray(arr,&p,comparePerson);
    foreach_dynamicArray(arr,printPerson);

    //测试销毁
    destroy_dynamicArray(arr);
    
    return ;
    
}

int main()
{
    test01();
    return 0;
}