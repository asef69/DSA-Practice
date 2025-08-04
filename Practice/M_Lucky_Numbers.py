A, B = map(int, input().split())

lucky_numbers = []

for num in range(A, B + 1):
    temp = num
    is_lucky = True
    while temp > 0:
        digit = temp % 10
        if digit != 4 and digit != 7:
            is_lucky = False
            break
        temp = temp // 10
    if is_lucky:
        lucky_numbers.append(str(num))

if not lucky_numbers:
    print(-1)
else:
    print(' '.join(lucky_numbers))