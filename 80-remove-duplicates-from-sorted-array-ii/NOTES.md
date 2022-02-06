unordered_map<int,int>mp;
int n = nums.size();
for(int i = 0 ; i < nums.size() ; ){
mp[nums[i]]++;
if(mp[nums[i]]>2){
nums.erase(nums.begin()+i);
}
else i++;
}
return nums.size();
/////////////
unordered_map<int, int>ump;
for(int i=0;i<nums.size();i++){
ump[nums[i]]++;
}
vector <int> vec;
for(auto& x: ump){
while(x.second>2){x.second--;}
if(x.second==1){vec.push_back(x.first);}
else if(x.second==2){vec.push_back(x.first);vec.push_back(x.first);}
}
nums.clear();
sort(vec.begin(),vec.end());
nums=vec;
return nums.size();