class Solution:
    def lexicographicallySmallestArray(self, nums: List[int], limit: int) -> List[int]:
        sorted_nums = nums.copy()
        sorted_nums.sort()

        groups = [[]]
        for i in range(len(sorted_nums)):
            if i>0 and sorted_nums[i] - groups[-1][-1] > limit:
                groups.append([sorted_nums[i]])
            else:
                groups[-1].append(sorted_nums[i])
        
        groups_indexes = [0] * len(groups)
        for i in range(len(nums)):
            j = 0
            while groups[j][0] > nums[i] or nums[i] > groups[j][-1]: j+=1
            nums[i] = groups[j][groups_indexes[j]]
            groups_indexes[j] += 1
        
        return nums