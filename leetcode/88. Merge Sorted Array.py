class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        M = 0
        N = 0
        nums = []
        
        while M < m and N < n:
            if nums1[M] <= nums2[N]:
                nums.append(nums1[M])
                M += 1
            else:
                nums.append(nums2[N])
                N += 1

        while M < m:
            nums.append(nums1[M])
            M += 1
        
        while N < n:
            nums.append(nums2[N])
            N += 1
            
        nums1.clear()
        nums1 += nums
        return nums1
