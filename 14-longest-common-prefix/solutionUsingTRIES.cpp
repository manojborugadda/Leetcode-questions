class Trie
{
    public:
    char data;
    bool isTerminal;
    int child;
    Trie* children[26];
    Trie(char ch)
    {
        data=ch;
        child=0;
        isTerminal=false;
        for(int i=0;i<26;i++)
        this->children[i]=NULL;
    }
    void insert(Trie* root,string word)
    {
        Trie* curr=root;
       for(int i=0;i<word.length();i++)
       {
           int index=word[i]-'a';
            if(curr->children[index]==NULL)
            {
                 curr->children[index]=new Trie(word[i]);
                 curr->child++;
            }
            curr=curr->children[index];
       }
       curr->isTerminal=true;
    }
    void common(Trie* root,string first,string &ans)
    {
        Trie* curr=root;
        for(int i=0;i<first.length();i++)
        {
            char ch=first[i];
             int index=ch-'a';
            if(curr->child==1)
            {
                ans+=ch;
                curr=curr->children[index];
            }
            else if(curr!=root)
            return;
            if(curr!=root&&curr->isTerminal)return;
        }
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
          Trie* root = new Trie('\0'); 
          string ans="";
        for (auto x : strs) {
            if(x.length()==0)return x;
            root->insert(root,x);
        }
        root->common(root,strs[0],ans);
        return ans;
     
    }
};
