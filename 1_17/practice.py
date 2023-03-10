a="mike"
b="smikeeemike"
print(a in b)
print(b.find(a))

needle = "abb"
haystack = "bbbbababbbaabbba"

if needle not in haystack:
    print(-1)
lc=rc=ct=0
while ct!=len(needle):
    if(haystack[rc]==needle[ct]):
        rc+=1
        ct+=1
    else:
        lc+=1
        rc=lc
        ct=0
        
print(lc)
print([1,2])

s="mkee"
words=["m",'mike']
# print(s[0])
t = [i for i in words]
print(t[0]==s[0])
