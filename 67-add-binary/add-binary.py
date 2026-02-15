class Solution:
    def addBinary(self, a: str, b: str) -> str:
        num1=int(a,2)
        num2=int(b,2)
        summation=num1+num2
        result=bin(summation)[2:]
        return result
        