S=input().strip()
balance=0
ans=[]
substring=[]
for char in S:
    substring.append(char)
    if char=='L':
        balance+=1
    else:
        balance-=1
    if balance==0:
        ans.append(''.join(substring))
        substring=[]
print(len(ans))
for sub in ans:
    print(sub)                