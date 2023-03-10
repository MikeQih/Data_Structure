class daynames:
    def __init__(self,dataval):
        self.dataval= dataval
        self.nextval= None

e1 = daynames("Mon")
e2 = daynames("Tue")
e3 = daynames("Wed")
e4 = daynames("Thu")
e5 = daynames("Fri")

e1.nextval = e2
e2.nextval = e3
e3.nextval = e4

thisvalue = e1

    

    
while thisvalue: #单链表找数据 eg.e3
    if thisvalue==e3:
        print(thisvalue.dataval)
    thisvalue = thisvalue.nextval

while thisvalue: #遍历单链表
    print(thisvalue.dataval)
    thisvalue = thisvalue.nextval
    
