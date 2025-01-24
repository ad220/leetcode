// stupid solution, as the naive search is O(n)

class Solution {
public:
    int findZero(vector<int>& nums) {
        if (nums.size()==1) return 0;
        if (nums[nums.size()/2]==0) return nums.size()/2;

        std::vector<int> new_nums;
        if (nums[nums.size()/2]>0) {
            new_nums = std::vector<int>(nums.begin(), nums.begin()+nums.size()/2);
            return findZero(new_nums);
        } else {
            new_nums = std::vector<int>(nums.begin()+nums.size()/2, nums.end());
            return findZero(new_nums)+nums.size()/2;
        }
    }

    int findClosestNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        
        int k=findZero(nums);
        printf("k: %d", k);
        if (nums[k]<0 && k<nums.size()-1) return abs(nums[k]) < abs(nums[k+1]) ? nums[k] : nums[k+1];
        if (nums[k]>0 && k>0) return abs(nums[k-1]) < abs(nums[k]) ? nums[k-1] : nums[k];
        return nums[k];        
    }


};