class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        std::vector<int>v1;
        std::set<int>s(nums.begin(),nums.end());
        std::map<int,int>mp,mp2;

        for(auto it:nums)
        {
        	mp[it]++;
        }

        int count=0;
        for(auto it:s)
        {
        	mp2[it]=count;
        	count+=mp[it];
        }

        for(auto it:nums)
        {
            v1.push_back(mp2[it]);
        }

        return std::vector<int> (v1.begin(),v1.end());
    }
};
