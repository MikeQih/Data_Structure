# strs = ["fr","flow","fright"]
strs = ["dog","racecar","carszs"]
# cnt=0
# while cnt<len(strs):
#     strs[cnt][0]
print(strs[0].find("m"))
strs.sort()
print(strs)
print(abs(-1-5))

def threeSumClosest(nums, target):
    #16. 最接近的三数之和 leetcode 没做完
    if len(nums)==3:
        return sum(nums)
    nums.sort()#小到大
    ans = nums[-1]
    l = 1
    r = len(nums)-1
    for i in range(len(nums)):
        if abs(nums[i]+nums[l]+nums[r]-target)<=ans:
            ans = abs(nums[i]+nums[l]+nums[r]-target)
            if ans==0:
                return target
            l+=1
        else: #大于的情况
            r-=1
    return ans
    
r = threeSumClosest([1,1,1,1],0)
print(r)
