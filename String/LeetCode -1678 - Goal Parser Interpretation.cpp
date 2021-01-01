class Solution {
public:
    string interpret(string command) {
        std::string str;
        std::list<char>l;
        for(auto it:command)
        {
            if(it=='G')
            {
                str+='G';
            }
            else
            {
                l.push_back(it);
            }
            if(l.back()==')' && l.size()==2)
            {
                    str+='o';
                    l.clear();
            }
            else if(l.back()==')' && l.size()==4)
            {
                str+="al";
                l.clear();
            }
        }

        return str;
    }
};
