class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        std::vector<int>v1;
        for(int i=0;i<nums.size()/2;i++)
        {
            v1.push_back(nums[i]);
            v1.push_back(nums[i+n]);
        }
        return std::vector<int> (v1.begin(),v1.end());
    }
};
