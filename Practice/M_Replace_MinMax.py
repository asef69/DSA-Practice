n=int(input())
a=list(map(int,input().split()))
min_val=min(a)
max_val=max(a)
min_index=a.index(min_val)
max_index=a.index(max_val)
a[min_index],a[max_index]=a[max_index],a[min_index]
print(' '.join(map(str,a)))