https://www.youtube.com/watch?v=EsWBGoAdm4I
​
​
​
​
​
class Trie {
​
private:
​
struct TrieNode{
struct TrieNode *child[26];
bool isEnd;
};
TrieNode* node;
public:
​
Trie() {
node=new TrieNode();
}
​
void insert(string word) {
TrieNode* cur=node;
for(char c: word){
if(cur->child[c-'a']==NULL) cur->child[c-'a']=new TrieNode();
cur=cur->child[c-'a'];
}
cur->isEnd=true;
}