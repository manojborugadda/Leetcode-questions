https://www.youtube.com/watch?v=pVs1RjhmHwU
​
​
​
// Consider every index as a center, take two pointers, one on the left and one on the right
// keep checking and expanding these pointers, till the characters on left-right match
// We need to check above scenarios for both even length and odd length strings, considering every index starting from 1, as the center
// So for even length string, center = i, left = i-1, right = i (because we have two mid points for even length string)
// For odd length string, center = i, left = i-1 and right = i+1.
string longestPalindrome(string s) {
int n = s.length();
int start = 0, maxlen = 1;
for (int i = 1; i<n; i++) {
int low = i-1;
int high = i;
while(low >= 0 and high < n) {
if (s[low] == s[high]) {
if (maxlen < high - low + 1) {
maxlen = high-low+1;
start = low;
}
}
else break;
low--;
high++;
}
low = i-1;
high = i+1;
while(low >= 0 and high < n) {
if (s[low] == s[high]) {
if (maxlen < high - low + 1) {
maxlen = high-low+1;
start = low;
}
}
else break;
low--;
high++;
}
}
return s.substr(start, maxlen);
}