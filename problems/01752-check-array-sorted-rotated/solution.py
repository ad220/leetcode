class Solution:
    def check(self, nums: List[int]) -> bool:
        sorted_nums = nums.copy()
        sorted_nums.sort()
        for i in range(len(nums)):
            if sorted_nums == nums[i:] + nums[:i]:
                return True
        return False
        