n,k=map(int,input().split())
left=-1
right=n+1
while right-left>1:
    m=left+(right-left)//2
    if (n-m)*(n-m+1)//2-m>k:
        left=m
    else:
        right=m
print(right)