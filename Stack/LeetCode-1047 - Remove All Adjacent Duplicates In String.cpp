class Solution {
public:
    string removeDuplicates(string S) {
        std::string str;
        std::stack<char>s;
        for(int i=0;i<S.size();i++)
        {
            if(!s.empty() && s.top()==S[i])
            {
                s.pop();
            }
            else
            {
                s.push(S[i]);
            }
        }
        while(!s.empty())
        {
            str+=s.top();
            s.pop();
        }
        reverse(str.begin(),str.end());
        return str;
    }
};
