class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        bool swapped;
        for(int i=1; i<nums.size(); i++) {
            do {
                swapped = false;
                
                for(int j=0; j<i; j++) {
                    if (nums[i]<nums[j] && nums[j]-nums[i]<=limit) {
                        std::swap(nums[i], nums[j]);
                        i=j;
                        swapped = true;
                        break;
                    }
                }
            } while (swapped);
        }

        return nums;
    }
};