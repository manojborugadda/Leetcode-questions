class Solution {
public:
int findPeakElement(vector<int>& arr) {
return max_element(arr.begin(), arr.end()) - arr.begin();
}
};