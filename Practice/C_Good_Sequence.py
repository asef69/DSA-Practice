N=int(input())
A=list(map(int,input().split()))
freq={}
for num in A:
    if num in freq:
        freq[num]+=1
    else:
        freq[num]=1
remove=0
for num in freq:
    count=freq[num]
    if count<num:
        remove+=count
    elif count>num:
        remove+=(count-num)
print(remove)                        
