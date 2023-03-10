import string
s = "   123,,,mmm"
s = s.strip().lower()
for character in string.punctuation:
    s = s.replace(character,"")
for c in s:
    if c.isalpha():
        # print("cc",c)
        s=s.replace(c,"")
        # print("ss",s)
s = int(s)
print(s)

x = input("PLease enter a number:")
print(x)

import string
# from string import ascii_lowercase

def myAtoi(s):#字符串转换整数
    s = s.strip()
    if (len(s))==0:
        return 0
    if s[0].isdigit()==False and s[0]!='-' and s[0]!='+':
        return 0
    # for character in string.punctuation:
    #     if character=='-':
    #         continue
    #     s = s.replace(character,"")
    idx=0
    if s[0]=='-':
        for c in range(1,len(s)):
            if s[c].isdigit()==True:
                idx=c
            else:
                break
    elif s[0]=='+':
        for c in range(1,len(s)):
            if s[c].isdigit()==True:
                idx=c
            else:
                break       
    else:
        for c in range(len(s)):
            if s[c].isdigit()==True:
                idx = c
            else:
                break
                
    s = s[0:idx+1]
    if '-' in s and len(s)==1:
        return 0
    if '+' in s:
        s = s.replace("+","")
        if len(s)==0:
            return 0
    s = int(s)
    if s>2**31-1:
        s = 2**31-1
    elif s<(-1)*(2**31):
        s = (-1)*2**31
    return(s)


