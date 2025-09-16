from math import gcd
from typing import List

class Solution:
    def replaceNonCoprimes(self, nums: List[int]) -> List[int]:
        stack = []
        for num in nums:
            stack.append(num)
            flag = True
            while len(stack) >= 2 and flag:
                first = stack.pop()
                second = stack.pop()
                if self.coprime(first, second):
                    stack.append(self.lcm(first, second))
                else:
                    flag = False
                    stack.append(second)
                    stack.append(first)
        return stack

    def coprime(self, a: int, b: int) -> bool:
        return gcd(a, b) > 1

    def lcm(self, a: int, b: int) -> int:
        return (a * b) // gcd(a, b)