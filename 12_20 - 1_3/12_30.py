nums1=[1,3]
nums2=[2]

nums3 = nums1+nums2
nums3.sort()
print(nums3)


if len(nums3)%2==0:
    left = int(len(nums3)/2-1)
    right=int(len(nums3)/2)
    print("left",left)
    print("right",right)
    ans = (nums3[left]+nums3[right])/2.0
    print("ans",ans)
else:
    index = int(len(nums3)/2)
    print(index)
    print("ans",nums3[index])

# 3数之和
#i<j<k,答案里无重复的三元组
nums=[-1,0,1,2,-1,-4]
nums.sort()
ans=[]
n = len(nums)
for i in range(n-2):
    x = nums[i]
    if i>0 and x==nums[i-1]:
        continue
    if x+nums[i+1]+nums[i+2]>0:
        break
    if x+nums[-1]+nums[-2]<0:
        continue
    j = i+1
    k = n-1
    while j<k:
        s = x+nums[j]+nums[k]
        if s>0:
            k-=1
        elif s<0:
            j+=1
        else:
            ans.append([x,nums[j],nums[k]])
            j+=1
            while j<k and nums[j-1]==nums[j]:
                j+=1
            k-=1
            while k>j and nums[k+1]==nums[k]:
                k-=1
print(ans)


def searchRange(nums, target):
    if target<nums[0] or target>nums[-1] or len(nums)==0:#这句为啥错了？
        return [-1,-1]
    # start = lower_bound(nums,target)
    # end = lower_bound(nums,target+1)
    
b=searchRange([1,2,2,3],0)
print(b)


def lower_bound(nums,target):
        left = 0
        right = len(nums)
        while left<right:
            mid = (left+right)//2
            if target>nums[mid]:
                left = mid+1
            else:
                right = mid
        return left


def searchRange(nums, target):
    start = lower_bound(nums,target)
    
    # if len(nums) or target<nums[0] or target>nums[-1]==0://这句为啥不行？？
    #     return [-1,-1]
    if start==len(nums) or nums[start]!=target:
        return [-1,-1]
    # if nums[start]!=target or start==len(nums): //还有这句咋不行？？
    #     return [-1,-1]
    end = lower_bound(nums,target+1)-1
    return [start,end]

r = searchRange([5,7,7,8,8,10],8)
print(r)#二分查找还得看

        