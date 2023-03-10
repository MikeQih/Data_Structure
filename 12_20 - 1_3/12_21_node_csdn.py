#创建结点类
class ListNode(object):
    def __init__(self,data):
        self.data = data
        self.next = None

#创建链表类
class CreateList(object):
    def __init__(self):
        self.head = ListNode(None)

    #链表初始化函数
    def InitList(self,data):
        #创建头结点
        self.head = ListNode(data[0]) #??
        p = self.head #e1?
        for i in data[1:]:
            node = ListNode(i)
            p.next = node
            p = p.next

    #链表判空
    def IsEmpty(self):
        p = self.head
        if p.next == None:
            print("Empty List")
            return 1 #True
        else:
            return 0 #False
    
    #计算链表长度
    def GetLength(self):
        if self.IsEmpty():
            return 0
        p = self.head
        count=0
        while p:
            count += 1
            p = p.next
        return count

    #遍历链表，输出每个链表的每个结点值，用“，”隔开
    def ReadList(self):
        if self.IsEmpty():
            return 0
        p = self.head
        while p:
            print(p.data,end=",")
            p = p.next
        print('')
    
    #获取链表第i个结点数据
    def GetList(self,i):
        if i > self.GetLength():
            print("第%d个元素不存在",i)
            return 0
        p = self.head
        index=1
        while index<i:
            p = p.next
            index+=1
        print("第%d个数据为：%d" % (i,p.data))
    
    #链表插入数据，在第i个结点后插入数据data
    def InsertList(self,i,data):
        if i > self.GetLength():
            print("Failed to insert")
            exit(0)
        p = self.head
        index=1
        while index<i:
            p = p.next
            index+=1
        node = ListNode(data)
        node.next = p.next
        p.next = node

    #链表删除函数，删除第i个结点
    def DeleteList(self,i):
        if i > self.GetLength():
            print("Failed to delete")
            exit(0)
        p = self.head
        index = 1
        while index < i:
            pre = p
            index += 1
            p = p.next
        pre.next = p.next
        p = None
    
    #链表逆序
    def reverse(self):
        p = self.head
        q = None
        while p:
            temp = p.next
            p.next = q #?
            q = p
            p = temp
        self.head = q

#创建链表类
list = CreateList()
list.ReadList()

#链表数据
data=[1,5,2,12,3]
list.InitList(data)
list.ReadList()
print(list.GetLength())

#读取链表值
list.GetList(4)

#插入结点
list.InsertList(1,60)
print("insert")
list.ReadList()

#删除结点
list.DeleteList(3)
list.ReadList()

#反转链表
list.reverse()
list.ReadList()



        
        