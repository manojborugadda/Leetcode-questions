class Trie {
    
private:
    struct TrieNode
    {
        struct TrieNode *child[26];
        bool isEnd;
    };
    TrieNode* node;
    
public:
    Trie() {
        node = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = node;
        for(auto x :word){
            if(curr->child[x-'a'] == NULL){
                curr->child[x-'a'] = new TrieNode();
            }
            curr = curr->child[x-'a'];
        }
        
        curr->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* curr = node;
        for(auto x :word){
            if(curr->child[x-'a'] == NULL){
                return false;
            }
            curr = curr->child[x-'a'];
        }
        
       return (curr->isEnd);
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = node;
        for(auto x : prefix){
            if(curr->child[x-'a'] == NULL){
               return false;
            }
            curr = curr->child[x-'a'];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */