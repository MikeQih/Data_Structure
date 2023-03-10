#p70开始 大话数据结构

def lengthOfLongestSubstring(s):#leetcode 无重复字符的最长子串
        # 哈希集合，记录每个字符是否出现过
        occ = set()
        n = len(s)
        # 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
        rk, ans = -1, 0
        for i in range(n):
            if i != 0:
                # 左指针向右移动一格，移除一个字符
                occ.remove(s[i - 1])
            while rk + 1 < n and s[rk + 1] not in occ:
                # 不断地移动右指针
                occ.add(s[rk + 1])
                rk += 1
            # 第 i 到 rk 个字符是一个极长的无重复字符子串
            ans = max(ans, rk - i + 1)
        return ans

# r = lengthOfLongestSubstring("abcabcb")
# print(r)

n = -321
if n<0:
    n = -n
    loopn=len(str(n))
    ans=0
    for i in range(loopn):
        digit = n%10 #1
        ans = ans*(10)+digit
        n = int(n/10)
    print(ans*-1)
else:
    loopn=len(str(n))
    ans=0
    print(ans)
    loopn=len(str(n))
    print(loopn)
    ans=0
    for i in range(loopn):
        digit = n%10 #1
        ans = ans*(10)+digit
        n = int(n/10)
    print(ans)


nums = [1,2,4,2,3,2,2,6] #leetcode 移除元素 有点问题为什么return index
val= 2
c=0
for i in nums:
    if i!=val:
        nums[c]=i
        c+=1
print(c)

