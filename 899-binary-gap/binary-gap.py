class Solution:
    def binaryGap(self, n: int) -> int:
        binary=bin(n)[2:]
        max_gap=0
        prev_pos=0

        for i,bit in enumerate(binary):
            if bit=='1':
                if prev_pos is not None:
                    max_gap = max(max_gap, i - prev_pos)
                prev_pos=i   

        return max_gap         


        