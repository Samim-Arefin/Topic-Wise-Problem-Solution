class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        std::vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            int temp=nums[i]+ans[i-1];
            ans.push_back(temp);
        }
        return std::vector<int> (ans.begin(),ans.end());
    }
};
