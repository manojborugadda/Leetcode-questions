map<char,int>mp;
for(auto &i:s){
mp[i]++;
}
for(auto &c:t){
mp[c]++;
}
for(auto it:mp){
if(it.second%2!=0){
return it.first;
}
}
return 0;
// second method
map<char, unsigned int> smap, tmap;
char unique;
for (char sc: s) smap[sc]++;
for (char tc: t) tmap[tc]++;
for (char tc: t) {
if (smap[tc] < tmap[tc]) {
unique = tc;
break;
}
}
return unique;
}
// third method
char c;
unordered_map<char,int>m;
for(auto i=0;i<t.length();i++){
m[t[i]]++;
}
for(auto i=0;i<s.length();i++){
m[s[i]]--;
}
for(auto i=m.begin();i!=m.end();i++){
if(i->second>0){
c=i->first;
}
}
return c;
}