max1=0
height = [1,8,6,8,3,7]
i,j,res= 0,len(height)-1,0
while(i<j):
    if(height[i]>height[j]):
        res = max(res,height[j]*(j-i))
        j-=1
    else:
        res = max(res,height[i]*(j-i))
        i+=1
print(res)

t = [ [0]*3 for i in range(3)]
print(t)


def convert(s, numRows): #重点看
        if numRows<2:
            return s
        res=["" for _ in range(numRows)]
        print(res)
        i = 0
        flag = -1
        for c in s:
            res[i]+=c
            # print("res[{}]={}".format(i,res[i]))
            if(i==0 or i==numRows-1):
                flag=-flag
            i+=flag
        return "".join(res)

s = "PAYPALISHIRING"
numRows = 3
r = convert(s,numRows)
print(r)

d=[1,2,2,3,5]
c=0
for i in d:
    if i==2:
        c+=1
while c>0:
    d.remove(2)
    c-=1
print(d)