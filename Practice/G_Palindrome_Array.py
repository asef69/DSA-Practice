number = int(input())
A = list(map(int, input().split()))
A_reversed = A.copy()  
A_reversed.reverse()    
if A == A_reversed:
    print("YES")
else:
    print("NO")