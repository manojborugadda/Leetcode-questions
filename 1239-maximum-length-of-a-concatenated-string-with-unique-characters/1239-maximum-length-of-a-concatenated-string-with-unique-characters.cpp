class Solution {
public:
	bool isunique(string &s){
		vector<int> v(26,0);
		for(auto &it: s){
			if(v[it-'a']==0)
				 v[it-'a']++;
			else
				return false;
		}
		return true;
	}
    
	int max(int a,int b){
		return (a>b)?a:b;
	}
    
	int maxLength(vector<string>& arr) {
			 int res=0;

			for(int i=0;i<(1<<arr.size());i++){
				 string ans;
				for(int j=0;j<arr.size();j++){
						  if(i&(1<<j)){
							  ans+=arr[j];
						  }    
				}

				if(isunique(ans)){
					res=max(res,ans.length());
				}
			}

		  return res;
	}
};