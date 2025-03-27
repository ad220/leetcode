class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            // search for dominant element
            int max = 0;
            int i = 0;
            int n_max, count_i;
            vector<int> checked;
            while (max<nums.size()/2+1) {
                if (std::find(checked.begin(), checked.end(), nums[i])==checked.end()) {
                    checked.push_back(nums[i]);
                    count_i = std::count(nums.begin(), nums.end(), nums[i]);
                    if (count_i>max) {
                        n_max = nums[i];
                        max = count_i;
                    }
                }
                i++;
            }
    
            if (nums.size()%2 && max<=nums.size()/2 + 1)
                return -1;
    
            int count_j = 0;
            for(int j=0; j<nums.size(); j++) {
                if (nums[j] == n_max) {
                    count_j++;
                    if (count_j >= (j+1)/2+1)
                        return j;
                }
            }
            return -1;
        }
    };