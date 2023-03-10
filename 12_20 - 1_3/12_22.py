def lengthOfLongestSubstring(s):
    maxrecord=[]
    # count=0
    countrecord=[]
    if len(s)==1:
        return 1
    if len(s)==0:
        return 0

    for i in s:
        if i not in maxrecord:
            # count+=1
            maxrecord.append(i)
            countrecord.append(len(maxrecord))
        else: 
            # count=0
            del(maxrecord[:]) 
            maxrecord.append(i)
          
    return max(countrecord)


a=[1,2,1,3]
r = lengthOfLongestSubstring(a)
print("result",r)

print()

vec1 = [1,1,2]
vec2 = [4,5,6]
a = [x*y for x in vec1 for y in vec2]
print(a)

matrix = [
    [1, 2, 3, 4],
    [5, 6, 7, 8],
    [9, 10, 11, 12],
]
r = [[row[i] for row in matrix]for i in range(0,4)]
print(r)

print()
map= dict()
map[a[0]]+=1
print(map[a[0]])

