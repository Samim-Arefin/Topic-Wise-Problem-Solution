class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maximum=*max_element(candies.begin(),candies.end());
        std::vector<bool>v1;
        for(int i=0;i<candies.size();i++)
        {
            if(candies[i]+extraCandies>=maximum)
            {
                v1.push_back(true);
            }
            else
            {
                v1.push_back(false);
            }
        }
        return std::vector<bool> (v1.begin(),v1.end());
    }
};
