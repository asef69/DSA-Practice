N = input().strip()

reversed_N = N[::-1].lstrip('0')
if not reversed_N:  
    reversed_N = '0'
else:
    reversed_N = reversed_N

if N == N[::-1]:
    is_palindrome = "YES"
else:
    is_palindrome = "NO"

print(reversed_N)
print(is_palindrome)