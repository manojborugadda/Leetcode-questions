class Solution {    ///TC:O(nlogn)  SC:O(n)
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        //sorting the folders lexicographically so that parent folders comes in the beginning
        sort(begin(folder),end(folder));
        vector<string>ans;
        ans.push_back(folder[0]);

        for(int i =1 ;i<folder.size();i++) {
            //adding the slash to the last added folder path from ans vector and will compare if the current folder is a subfolder or not
            string lastFolder = ans.back();
            lastFolder += '/';

            if(folder[i].compare(0,lastFolder.size(),lastFolder) != 0) {
                ans.push_back(folder[i]);
            }
        }
        return ans;
    }
};
