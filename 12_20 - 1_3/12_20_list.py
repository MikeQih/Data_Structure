def list_insert(ls,index,value):
    if index>=len(ls) or index<0:
        return None
    newl = [None]*(len(ls)+1)
    if index==0:
        newl[0]=value
        for i in range(len(ls)):
            newl[i+1] = ls[i]
        return newl
    elif index == len(ls)-1:
        for i in range(len(ls)):
            newl[i]=ls[i]
        # newl.append(value)
        newl[len(ls)]=value
        return newl
    else:
        for i in range(0,index):
            newl[i]=ls[i]
        newl[index]=value
        for i in range(index,len(ls)):
            newl[i+1]=(ls[i])
        return newl

def list_delete(ls,index):
    if index>=len(ls) or index<0:
        return None
    newl = []
    if index==0:
        for i in range(1,len(ls)):
            newl.append(ls[i])
        return newl
    elif index == len(ls)-1:
        for i in range(0,len(ls)-1):
            newl.append(ls[i])
        return newl
    else:
        for i in range(0,len(ls)):
            if i == index:
                continue
            newl.append(ls[i])
        return newl

a=[1,4,2,5,32]
print(a)
new_ls = list_insert(a,4,9) #看，问怎么无insert给list填加
print(new_ls,"\n")

b = [3,1,2,5,3,99,212,21]
print(b)
new_ls = list_delete(b,3)
print(new_ls)

