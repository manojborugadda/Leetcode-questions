class Solution { //TC:O(NLOGN) + O(M) --> where M is the length of the first string in array 
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n =  strs.size();
        string ans = "";// answer string
        sort(strs.begin(),strs.end()); //// Sort the vector
        //we take the FIRST and LAST string in the sorted vector and compare 
        string a = strs[0] , b = strs[n-1];
        for(int i = 0;i<a.size();i++){
            if(a[i] == b[i]){
                ans = ans + a[i]; /// adding the character which are having common as PREFIX
            }else{
                break;
            }
        }
        return ans;
    }
};

////This problem is solved using the SORTING approach
