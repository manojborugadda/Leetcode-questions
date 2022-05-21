class Solution {
public:
    int convertTime(string current, string correct) {
        
        int ans = 0;
        
        // first of all we have to convert these above times to MINUTES
        
        //----------- Extracting the HOUR information
        
        //                  for example   current = "02:30", correct = "04:35"
        string s1 = current.substr(0,2); // it gives the 02
        string s2 = correct.substr(0,2);   // it gives 04
        
        //The stoi() function takes a string as an argument and returns its value
        int x = stoi(s1) , y = stoi(s2);
        
         //----------- Extracting the MINUTES information
        //                  for example   current = "02:30", correct = "04:35"
        string s3 = current.substr(3,5); // it gives the 30
        string s4 = correct.substr(3,5);   // it gives 35
        
        int a = stoi(s3) , b = stoi(s4);
        
        /// summing the HOURS and MINUTES into minutes
        int p = x*60 + a;  // it gives 150 minutes total
        int q = y*60 + b;  // it gives 4*60+35 = 275 minutes
        
        int diff = q - p;  // difference of the minutes
//// we are dividing the "diff" until it becomes  0 and we increments the "ans" simultaneously
        for(auto &x : {60,15,5,1} ){ 
            ans  = ans + diff/x;
            diff = diff%x;
        }
     return ans;   
    }
};