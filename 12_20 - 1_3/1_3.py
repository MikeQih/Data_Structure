import copy #检查句子中数据是否递增
s="1 box has 3 blue 4 red 6 green and 12 yellow marbles"
ls=[]
s = s.split(" ")
result = 1
for i in s:
    if (i.isdigit()==True):
        if int(i) in ls:
            result = 0
            break
        ls.append(int(i))

if result!=0:
    lss = copy.deepcopy(ls)
    ls.sort()
    if lss!=ls:
        print(False)
    else:
        print(True)
else:
    print(False)


scopy="1 box has 3 blue 4 red 6 green and 12 yellow marbles"
def areNumbersAscending(s):
    ls=[]
    s = s.split(" ")
    for i in s:
        if (i.isdigit()==True):
            if int(i) in ls:
                return False
            ls.append(int(i))
            
    lss = copy.deepcopy(ls)
    ls.sort()
    if lss==ls:
        return True
    else:
        return False

res = areNumbersAscending(scopy)
print("res",res)

