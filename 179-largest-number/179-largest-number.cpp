class Solution {
public:
    static bool mycmp(string a,string b){  // comparator function
        return a+b >b+a;
    }
    
    string largestNumber(vector<int>& nums) 
    {
          vector<string>str;
        
        for(int i=0;i<nums.size();i++){
            str.push_back(to_string(nums[i]));
        }
        
        //The third parameter of the sort function contains our comparator. The comparator function checks which of the two sum of the two numbers(added as a string) is lexographically larger.(when a+b and b+a). Returns TRUE if first option is true otherwise FALSE.
        sort(str.begin(),str.end(),mycmp);
        string ans;
        if(str[0]=="0") return "0";
        for(auto x:str){
            ans = ans+x;
        }
        
        return ans;
    }
};