class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        std::string str,ch;
        for(auto it:word1)
        {
            str+=it;
        }
        for(auto it:word2)
        {
            ch+=it;
        }
        if(str==ch)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
