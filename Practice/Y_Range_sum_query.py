N,Q=map(int,input().split())
A=list(map(int,input().split()))
prefix=[0]*(N+1)
for i in range (1,N+1):
    prefix[i]=prefix[i-1]+A[i-1]
for j in range(Q):
    L,R=map(int,input().split())
    print(prefix[R]-prefix[L-1])    