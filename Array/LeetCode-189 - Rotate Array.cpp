class Solution {
public:
    void rotate(vector<int>& nums, int k) {

            std::vector<int>v1,v2;
            int diff=nums.size()-(k%nums.size())-1;
            for(int i=0;i<nums.size();i++)
            {
                if(i>diff)
                {
                    v1.push_back(nums[i]);
                }
                else
                {
                    v2.push_back(nums[i]);
                }
            }
            for(auto it:v2)
            {
                v1.push_back(it);
            }
            nums.clear();
            for(auto it:v1)
            {
                nums.push_back(it);
            }
    }
};
