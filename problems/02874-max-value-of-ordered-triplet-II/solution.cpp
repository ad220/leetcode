class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            long long max_triplet=0;
            long long triplet;
    
            vector<int> prefix_max({nums.front()});
            vector<int> suffix_max({nums.back()});
            int s = nums.size()-1;
            for (int i=1; i<nums.size(); i++) {
                prefix_max.push_back(max(nums[i], prefix_max.back()));
                suffix_max.push_back(max(nums[s-i], suffix_max.back()));
            }
    
            for (int j=1; j<nums.size()-1; j++) {
                triplet = (long long) (prefix_max[j-1] - nums[j]) * suffix_max[s-j-1];
                if (triplet>max_triplet)
                    max_triplet=triplet;
            }
            return max_triplet;
        }
    };