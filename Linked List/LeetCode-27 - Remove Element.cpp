class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        std::list<int>l(nums.begin(),nums.end());
        l.remove(val);
        nums.clear();

        for(auto it:l)
        {
            nums.push_back(it);
        }

        return (nums.size());
    }
};
