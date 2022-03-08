}
}
return 0;
}
int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
int ans=0;
sort(arr2.begin(),arr2.end());
for(auto i : arr1)
{
if(binary_search_closest_value_finder(arr2,i,d))
{
ans++;
}
}
return arr1.size()-ans;
}
};
​
​
​
​
​
​
​
​
​
​
​
​
​