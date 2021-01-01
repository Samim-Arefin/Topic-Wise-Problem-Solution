class Solution{
public:
    string removeOuterParentheses(string S){
        std::stack<char>s;
        int open=0;
        std::string str;
        for(int i=0; i<S.size(); i++)
        {
            if(s.empty() && S[i]=='(')
            {
                s.push(S[i]);
            }

            else if(!s.empty() && S[i]=='(' )
            {
                str+=S[i];
                open++;
            }
            else if(!s.empty() && S[i]==')' && open!=0)
            {
                str+=S[i];
                open--;
            }
            else if(!s.empty() && S[i]==')' && open==0)
            {
                while(!s.empty())
                {
                    s.pop();
                }
            }
        }
        return str;
    }
};
