long long int l=0,r=x,mid;
while(l<=r){
mid = (l+r)/2;
if(mid*mid==x) return mid;
else if(mid*mid > x)  r=mid-1;
else l=mid+1;
}
return r;