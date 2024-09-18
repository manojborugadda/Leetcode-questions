class Solution {//TC:O(nlogn)  SC:O(n)
public:
    static bool compare(int& a, int &b) {// comparator function
        string x = to_string(a);
        string y = to_string(b);
        return x + y > y + x;
    }
    string largestNumber(vector<int>& nums) {
        string ans = "";
//The third parameter of the sort function contains our comparator. The comparator function checks which of the two sum of the two numbers(added as a string) is lexographically larger.(when a+b and b+a). Returns TRUE if first option is true otherwise FALSE.
        sort(begin(nums),end(nums),compare);

        if(nums[0] == 0) return "0"; //special case ------------

        for(int i =0 ;i<nums.size();i++) {
            ans+= to_string(nums[i]);
        }
        
        return ans;
    }
};

/**

consider the example nums = [3,30,34,5,9]
Firstly, Convert the numbers to strings: ["3", "30", "34", "5", "9"].
Now use custom comparator,
Comparing "3" and "30": "330" vs. "303" => "330" comes first.
Comparing "3" and "34": "334" vs. "343" => "343" comes first.
Comparing "3" and "5": "35" vs. "53" => "53" comes first.
Comparing "3" and "9": "39" vs. "93" => "93" comes first.
Comparing "30" and "34": "3430" vs. "3034" => "3430" comes first.

*/
