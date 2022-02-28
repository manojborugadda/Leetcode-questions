​
Time Complexity --> O(n) // where n is the length of the array
Space Complexity --> O(1) // we are not using anything extra from our side
​
​
​
​
class Solution {
public:
vector<string> summaryRanges(vector<int>& arr) {
int n = arr.size(); // extracting size of the array
vector<string> ans; // declaring answer array to store our answer
string temp = ""; // temproray string that stores all possible answer
for(int i = 0; i < n; i++) // start traversing from the array
{
int j = i; // declare anthor pointer that will move
// run that pointer until our range is not break
while(j + 1 < n && arr[j + 1] == arr[j] + 1)
{
j++;
}
// if j > i, that means we got our range more than one element