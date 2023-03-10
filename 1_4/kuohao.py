s = [3,5,6,4]
print(s.pop(3)) #pop内的参数是index

def isValid(s): #leetcode Q20, 有效的括号 
    if(len(s)%2==1): return False
    dic = {"(":")","[":"]","{":"}","?":"?"}
    stack = ["?"]
    for c in s:
        if c in dic:
            stack.append(c)
        elif dic[stack.pop()]!=c:
            return False
    return len(stack)==1