A, B = map(int, input().split())
S = input().strip()

if len(S) != A + B + 1:
    print("No")
else:
    if S[A] != '-':
        print("No")
    else:
        valid = True
        for i in range(len(S)):
            if i != A and not S[i].isdigit():
                valid = False
                break
        print("Yes" if valid else "No")