bool isPalindrome(int st, int e, string &s){
while(st<=e) {
if(s[st++]!=s[e--]) return false;
}
return true;
}
bool validPalindrome(string s) {
// edge case
if(s.size() == 1) return true;
int i=0, j=s.size()-1;
bool flag = true;
while(i<j){
if(s[i]==s[j]) {i++;j--;continue;}
else{
if(isPalindrome(i+1,j,s) || isPalindrome(i,j-1,s))
flag = true;
else flag = false;
break;
}
}
return flag;
}