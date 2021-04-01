```C++
//合并两个有序表（由大到小排列）

template<ElemType Class>
OrdSeqList<ElemType>::OrdSeqList<Elemtype>(const ElemType &sa,const ElemType &sb)
{
    int saLength = sa.GetLength();
    int sbLength = sb.GetLength();

    ElemType e1, e2;                      //用于存放，两个顺序表最大元素的值（表头元素）

    if(sa.maxLength >= sb.maxLength)        //设置新表的最大长度
    {
        maxLength = 2*sa.maxLength;
    }
    else
    {
        maxLength = 2 *sb.maxLength;
    }

    length = 0;                             //新表的表长，也是存数的引索

    elems = new ElemType [maxLength];       //申请新表的空间，容量为maxLength

    int i =1, j = 1;
    sa.GetElem(i,e1);
    sb.GetElem(j,e2);

    while(i <= saLength && j <= sbLength)   //当两张表中均有元素时，需要比较标头元素的大小
    {
        if(e1 < e2)
        {
            elems[length++] = e1;
            sa.GetElem(++i,e1);            //不是sa.getElem(i++,e1);，要先++在取数值；
                                            //等价于：i++; sa.getElem(i,e1);
        }
        else
        {
            elems[length++] = e2;
            sa.GetElem(++j,e1);
        }
        while(i<=saLength)                  //当其中一张表，数取完了，直接把其他元素存入表中即可。
        {
            elems[length++] = e1;
            sa.GetElem(++i,e1);
        }
        while(j<=sbLength)
        {
            elems[length++] = e2;
            sa.GetElem(++j,e2);
        }
    }
}
```

```C++
//顺序表和线性表的原地逆置；要求：空间复杂度为 O(1).
//顺序表
template<ElemType Class>
void SeqList<ElemType>::Reverse(ElemType &e)
{
    int length = e.GetLength();
    int i,j,temp;
    int pos = 0;
    for(i = 0, j = length - 1;j-i==1||j-i==2;i++,j--)
    {
        temp = e.elems[i];
        e.elems[i] = e.elems[j];
        e.elems[j] = temp;
    }
    return 0;
}

//链式
template<ElemType Class>
void LinkList<ElemType>::Reverse(){
    Node<ElemType>*p = head -> next, *q;
    head -> next = NULL;
    while(p->next !=NULL)
    {
        q = p->next;
        p -> next = head -> next;
        head -> next = p;
        p = q;
    }
}
```
（未完成）
```C++
//单循环链表表示多项式，编写一个函数polynomial::calc(x)，根据参数x，计算多项式值。
struct PolyItem
{
    //数据成员：
    double coef;
    int expn;
    //构造函数：
    PolyItem();
    PolyItem(double cf, int ex);
}
PolyItem::PolyItem()
{
    expn = -1;
}

PolyItem::PolyItem(double cf, int ex)
{
    expn = ex;
    coef = cf;
}

double polynomial::calc(x){
    double sum = 0, powX =0,cf = 0;
    int cf = 0;
    PolyItem it;
    Polynomial<ElemType> *p = head;
    while(p ->next != NULL)
    {
        it = p.Get
    }
}

```