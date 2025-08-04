def find_min_sum(test_cases):
    results = []
    for case in test_cases:
        N, A = case
        min_sum = float('inf')
        for i in range(N):
            for j in range(i + 1, N):
                current_sum = A[i] + A[j] + (j + 1) - (i + 1)  # Adjusting for 1-based indexing
                if current_sum < min_sum:
                    min_sum = current_sum
        results.append(min_sum)
    return results

T = int(input())
test_cases = []
for _ in range(T):
    N = int(input())
    A = list(map(int, input().split()))
    test_cases.append((N, A))

results = find_min_sum(test_cases)
for res in results:
    print(res)