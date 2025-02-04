class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        result_max = 0
        i=0
        j=1
        while j<=len(nums):
            if self.isAscending(nums[i:j]):
                if sum(nums[i:j])>result_max: result_max = sum(nums[i:j])
                j+=1
            else: i=j-1

        return result_max

    def isAscending(self, nums: List[int]) -> bool:
        if len(nums)==1: return True
        for i in range(len(nums)-1):
            if nums[i]>=nums[i+1]: return False
        return True
