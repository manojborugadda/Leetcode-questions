//Time Complexity:- O(N+M) //considering size of string 1 is N and string 2 is M
//Space Complexity O(1)
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int p1 = 0, p2=0, count1 = 0, count2 = 0, n1 = version1.size() , n2 = version2.size();
        
        while(p1 < n1 || p2  < n2){
            
            while(p1<n1 and version1[p1]!='.'){
                count1 = count1*10+version1[p1]-'0';
                //store the values upto '.' in an count1 variable for version 1
                p1++;
            }
            
            while(p2<n2 and version2[p2]!='.'){
                count2 = count2*10+version2[p2]-'0';
                //store the values upto '.' in an count2 variable for version 2
                p2++;
            }
            
            if(count1 < count2) return -1;
            else if(count1 > count2){
                return 1;
            }
            
            
            count1 = 0,count2 = 0; //reset the variables
            p1++,p2++; // increasing the pointers
        }
        return 0; // if both are equal return 0
    }
};