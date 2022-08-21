class Solution {
public:
    bool cmp(string& stamp, string& target, int i)
    {
        bool flag = false;
        for(int j=0;j<stamp.size();j++)
        {
            if(target[i+j] != '?') flag = true;
            if(stamp[j]!=target[i+j] && target[i+j]!='?') //while comparing, the target string can also have "?"
                return false;
        }
        return flag;
    }
    
    vector<int> movesToStamp(string stamp, string target) {
        int m = stamp.size(), n = target.size();
        vector<int> res;
        vector<int> vis(n,0);
        string s = "";
        for(int i=0;i<n;i++)
            s+="?"; //this is the initial string s.
        for(int k=0;k<n;k++)
        {
            bool found=false;
            for(int i=0;i<=n-m;i++)
            {
                if(vis[i]==0 && cmp(stamp,target,i))
                {
                    for(int j=i;j<i+m;j++)
                        target[j]='?'; //since the stamp is matched, we replace all matched characters with "?"
                    vis[i]=1; //an optimization using visited array. a stamp at one position only happens once.
                    res.push_back(i);
                    found=true;
                }
            }
            if(target==s) //if there is no more character left in target then break.
                break;
            if(!found) return {}; //if there is no match for any stamp then we cannot obtain target from s using the stamp
        }
        reverse(res.begin(),res.end());//since we went in reverse order, we need to reverse the vector to get the answer.
        if(target==s)
            return res;
        else return {};
    }
};