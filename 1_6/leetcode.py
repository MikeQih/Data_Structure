s=[5,2,1,3,4]
# s = sorted(s,reverse=True)
ranks = [(s[i], i) for i in range(len(s))]
print(ranks)

ranks.sort(reverse=True)
print(ranks)

res = [0]*len(s)
print(res)

print(ranks[0])#(5,0)
r=ranks[0]
print(res[r[1]])#(0)