#include <stdio.h>
#define MaxSize 10
typedef int ElemType;
typedef struct{
    ElemType data;
    int next;
} SLinkList[MaxSize];

int main(int argc, char const *argv[])
{
    /*
    静态链表：分配一整片连续的内存空间，各个结点集中安置
    包括数据元素和下一个结点的数组下标 (游标)(游标充当“指针”)
    0号结点充当“头结点”，游标为-1表示已经到达表尾
    用数组的方式实现的链表
    优点：增，删 操作不需要大量移动元素
    缺点：容量固定不可变！不能随机存取，只能从头结点开始依次往后查找
    */

    SLinkList a;
    printf("size a = %lu\n",sizeof(a));//80 每个数据和游标都是4B 8*10=80
    /*
    插入位序为i的结点：
    1.找到一个空的结点，存入数据元素 (可让next为某个特殊值，eg.-2，判断结点是否为空)
    2.从头结点出发找到位序为i-1的元素
    3.修改新结点的next (eg.改成-1)
    4.修改i-1号结点的next
    */

   /*
   删除某个结点：
   1.从头结点出发找到前驱结点
   2.修改前驱结点的游标
   3.被删除结点next设为-2
   */
    return 0; 
}
