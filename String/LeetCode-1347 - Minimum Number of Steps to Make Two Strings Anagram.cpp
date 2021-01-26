class Solution {
public:
    int minSteps(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        int count=0;
        if(s==t)
        {
            return count;
        }
        else
        {
            std::map<char,int>ms,mt;
            std::vector<char>v1;
            for(auto it:t)
            {
                if(mt[it]==0)
                {
                    v1.push_back(it);
                }
                mt[it]++;
            }
            for(auto it:s)
            {
                ms[it]++;
            }
            for(auto it:v1)
            {
                if(mt[it]>ms[it])
                {
                    count+=(mt[it]-ms[it]);
                }
            }
            return count;
        }
    }
};
