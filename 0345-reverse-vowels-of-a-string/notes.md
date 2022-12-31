vector<int> vowelIndex;
for(int i=0; i<s.size(); i++){
if(s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u' or s[i] == 'A' or s[i] == 'E' or s[i] == 'I' or s[i] == 'O' or s[i] == 'U'){
vowelIndex.push_back(i);
}
}
int first = 0;
int last = vowelIndex.size()-1;
while(last>first){
swap(s[vowelIndex[first]],s[vowelIndex[last]]);
first++;
last--;
}
return s;
