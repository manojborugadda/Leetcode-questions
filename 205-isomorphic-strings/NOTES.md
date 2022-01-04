bool isIsomorphic(string s, string t) {
if(s.length()!=t.length()) return false;
unordered_map<char,char>smap,tmap;
for(int i=0; i<s.size(); i++){
if(smap.count(s[i])==0){
if(tmap.find(t[i])!=tmap.end()) return false;
smap[s[i]]=t[i];
tmap[t[i]]=s[i];
} else if(t[i]!=smap[s[i]]) return false;
}
return true;
}
bool isIsomorphic(string s, string t) {
if(s.length()!=t.length()) return false;
unordered_map<char,char>smap,tmap;
for(int i=0; i<s.size(); i++){
if(smap.count(s[i])==0){
if(tmap.find(t[i])!=tmap.end()) return false;
smap[s[i]]=t[i];
tmap[t[i]]=s[i];
} else if(t[i]!=smap[s[i]]) return false;
}
return true;
}