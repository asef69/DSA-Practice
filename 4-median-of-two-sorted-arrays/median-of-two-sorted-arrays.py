class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        arr=nums1+nums2
        i=j=k=0
        while i<len(nums1) and j<len(nums2):
            if nums1[i]<nums2[j]:
                arr[k]=nums1[i]
                i+=1
            else:
                arr[k]=nums2[j]  
                j+=1
            k+=1
        while i<len(nums1):
                arr[k]=nums1[i]
                i+=1
                k+=1
        while j<len(nums2):
                arr[k]=nums2[j]
                j+=1
                k+=1   
        if len(arr) % 2 == 0:
                return float((arr[(len(arr)//2)-1] + arr[(len(arr)//2)]) / 2)
        else:
                return float(arr[((len(arr)-1)//2)])
            
