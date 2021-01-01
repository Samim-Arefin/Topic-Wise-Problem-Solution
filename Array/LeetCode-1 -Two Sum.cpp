class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int>v1(nums.begin(),nums.end());
        sort(v1.begin(),v1.end());
        int i=0;
        int j=v1.size()-1;
        int a,b;
        while(i<j)
        {
            if(v1[i]+v1[j]==target)
            {
                a=v1[i];
                b=v1[j];
                break;
            }
            else if(v1[i]+v1[j]<target)
            {
                i++;
            }
            else if(v1[i]+v1[j]>target)
            {
                j--;
            }

        }

            v1.clear();
            int samecheck;
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]==a)
                {
                    v1.push_back(i);
                    samecheck=i;
                    break;
                }
            }

            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]==b && i!=samecheck)
                {
                    v1.push_back(i);
                    break;
                }
            }

           return std::vector<int>(v1.begin(),v1.end());
    }

};
