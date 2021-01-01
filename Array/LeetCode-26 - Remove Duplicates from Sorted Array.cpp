class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        std::set<int> s(nums.begin(),nums.end());
        nums.clear();
        for(auto it:s)
        {
            nums.push_back(it);
        }
        return (nums.size());
    }
};
