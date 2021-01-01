class Solution {
public:
    string defangIPaddr(string address) {
        std::string str,ch="[.]";
        for(auto it:address)
        {
            if(it=='.')
            {
                str+=ch;
            }
            else
            {
                str+=it;
            }
        }
        return str;
    }
};
