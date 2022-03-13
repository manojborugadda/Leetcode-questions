bool isValid(string s) {
stack<char> temp;
for(int i = 0;i < s.length();i++){
if(s[i] == '{' or s[i] == '(' or s[i] == '['){
temp.push(s[i]);
} else if(temp.empty()){
return false;
} else if(s[i] == '}' and temp.top() == '{') {
temp.pop();
} else if(s[i] == ')' and temp.top() == '(') {
temp.pop();
} else if(s[i] == ']' and temp.top() == '[') {
temp.pop();
} else {
return false;
}
}
return temp.empty();
}