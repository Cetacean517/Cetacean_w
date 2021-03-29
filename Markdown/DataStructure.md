### 第3章 线性表
```C++
//合并两个有序表（由大到小排列）

template<class ElemType>
OrdSeqList<ElemType>::OrdSeqList<Elemtype>(const ElemType 7&sa,const ElemType &sb)
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
template<class ElemType>
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
template<class ElemType>
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
### 第5章 树和森林
```C++ 
//二叉树层序遍历(借助队列)
template<ElemType>
voidBinaryTree<ElemType>::LevelOrder(void(*Visit)(const ElemType &))const
{
    LinkQueue<BinTreeNode<ElemType>*> q;    //定义队列q
    BinTreeNode<ElemType> *p;
    if(root!=NULL)                          //若根非空则根入队
    {
        q.EnQueue(root);
    }
    while(!isEmpty)
    {
        q.DelQueue(p);
        (*Visit)(p->data);
        if(p->leftChild!=NULL)
        {
            q.EnQueue(p->leftChild);
        }
        else if (p->rightChild!=NULL)
        {
            q.EnQueue(p->rightCHild);
        }
    }
}
```

```C++
//中序线索二叉树（功能实现）
// 1. 中序二叉树的建立
template<class ElemType>
InThreadHelp(ThreadBinTreeNode<ElemType> *p,ThreadBinTreeNode<ElemType> *&pre)
{
    if(p!=NULL)
    {
        InThreadHelp(p->leftChild,pre);

        if(p->leftChild==NULL)
        {
            p -> leftChild = pre;
            p -> leftTag = 1;
        }
        else
            p -> leftTag =0;
        
        if (pre != NULL && pre -> rightChild != NULL)
        {
            pre -> rightChild = p;
            pre -> rightTag = 1;
        }
        else if(pre != NULL)
        {
            pre -> rightTag = 0;
        }
        pre = p;

        InThreadHelp(p -> rightChild, pre);
    }
}

// 2. 在中序线索二叉树中寻找中序序列中第一个结点
template<class ElemType>
ThreadBinTreeNode<ElemType>*InThreadBinTree<ElemType>::GetFirst()const
{
    if(root == NULL)
        return NULL;
    else
    {
        ThreadBinTreeNode<ElemType> *q = root;
        while(q -> leftTag == 0)
        {
            q = q -> leftChild;
        }
        return q;
    }
}
// 3. 在中序线索二叉树中寻找指定结点p的后继
template<class ElemType>
ThreadBinNode<ElemType> *InThreadBinTree<ElemType>::GetNext(ThreadBinNode<ElemType> *p)const
{
    if(p -> rightTag == 1)
        p = p -> rightChild;
    else
    {
        p = p -> rightChild;
        while(p -> leftTag == 0)
        {
            p = p -> leftChild;
        }
        return p;
    }
}
// 4. 中序线索二叉树中的中序遍历
template<class ElemType>
void InThreadBinTree<ElemType>::InOrder(void(*Visit)(const ElemType &))const
{
    ThreadBinTreeNode<ElemType> *p;
    for(p = GetFirst();p!=NULL;p = GetNext(p)){
        (*Visit)(p -> data);
    }
}
// 5.在中序线索二叉树上，插入右孩子
template<class ElemType>
void InThreadBinTree<ElemType>::InsertRightChild(ThreadBinTreeNode<ElemType>*p,const ElemType &e)
{
    ThreadBinTreeNode<ElemType> *x, *q;
    if(p == NULL)
    {
        return;
    }
    else{
        x = new ThreadBinTreeNode<ElemType>(e,p,p->rightChild,1,p->rightTag); //x结点的肯定没有左孩子，因此左指针是线索，指向p;x的右指针如果继承p结点的右指针。
        if(p->rightTag == 0)
        {
            q = p ->rightChild;
            while(q->leftChild == 0)
            {
                q = q->leftChild;
            }
            q -> leftChild = x;
        }
        p -> rightChild = x;
        p -> rightTag = 0;
        return;
    }
}
```

```C++
// 1.堆的向上/下调整
template<class ElemType>
void MinHeap<ElemType>::FilterDown(const int Start)
{
    int i = Start, j; //Start是开始调整的根的下标
    ElemType temp = heapArr[i];
    j = 2 * i + 1;
    while(j <= CurrentSize -1)
    {
        if (j < CurrentSize - 1 && heapArr[j] > heapArr[j+1])   //i 有右孩子，且右孩子的关键字小于左孩子
            j++;
        if (temp <= heapArr[j])
        {
            heapArr[i] = heapArr[j];
            i = j;
            j = 2*j +1;
        }
    }
    heapArr[i] = temp;
}

// 2. 堆的向上调整算法
template<class ElemType>
void MinHeap<ElemType>::FilterUp(int End)
{
    int j = End, i;
    ElemType temp = heapArr[j];
    i = (j - 1) /2;
    while(j > 0)
    {
        if (heapArr[i] <= temp)
        {
            break;
        }
        else
        {
            heapArr[i] = heapArr[j];
            j = i;
            i = (j - 1) / 2;
        }
        heapArr[j] = temp;
    }
}
```

```C++
//模式匹配KMP算法
//模式匹配优化后的KMP算法
```

```C++
//数组三元组
```