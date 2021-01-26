class Trie {
std::unordered_map<char,Trie*>map;
bool isEnd;
public:
    Trie* root=nullptr;
    Trie* CreateNode() {
        Trie* Node=new Trie;
        Node->isEnd=false;
        return Node;
    }

    /** Inserts a word into the trie. */
    void Build(Trie*& root,std::string str)
    {
        if(root==nullptr)
        {
            root=CreateNode();
        }
        Trie* Curr=root;
        for(auto ch:str)
        {
            if(Curr->map.find(ch)==Curr->map.end())
            {
                Curr->map[ch]=CreateNode();
            }
            Curr=Curr->map[ch];
        }
        Curr->isEnd=true;
    }

    void insert(string word) {
         Build(root,word);
    }


    /** Returns if the word is in the trie. */
    bool search(string word) {
        if(root==nullptr)
        {
            return false;
        }
        int count=0;
        Trie* Curr=root;
        for(auto ch:word)
        {
            if(Curr->map.find(ch)==Curr->map.end())
            {
                return false;
            }
            else
            {
                Curr=Curr->map[ch];
            }
        }
        return Curr->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if(root==nullptr)
        {
            return false;
        }
        int count=0;
        Trie* Curr=root;
        for(auto ch:prefix)
        {
            if(Curr->map.find(ch)==Curr->map.end())
            {
                count=0;
            }
            else
            {
                count++;
                Curr=Curr->map[ch];
            }
        }
        if(count==prefix.size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
