bool hash2(string pattern, vector<string> &words)
{
map<string, char> w; // map unique words to pattern
map<char, string> p; // map pattern to unique words
for(int i=0; i<words.size(); i++)
{
if(w[words[i]]=='\0') // check if unique word exists in map or not
w[words[i]] = pattern[i];
if(p[pattern[i]]=="") // check if pattern exists in map or not
p[pattern[i]] = words[i];
if(w[words[i]]!=pattern[i] || p[pattern[i]]!=words[i]) // check if pattern mapped to unique words is same as current pattern or not. also check if unique word mapped to pattern is same as current word or not
return false;
}
return true;
}
                                                        
bool wordPattern(string pattern, string str) {
stringstream ss(str);
string word;
vector<string> words;
while(ss>>word) // extract all words from str into vector words using stringstream
{
words.push_back(word);
}
if(pattern.size()!=words.size()) // if pattern and unique word length differ then return false
return false;
return hash2(pattern, words);
}
