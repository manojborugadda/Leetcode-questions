class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count=0;
        for(int i=low;i<=high;i++){
            int sum1=0,sum2=0;
            string ans=to_string(i);
            int mid=(ans.size())/2;
            for(int j=0;j<mid;j++){
                sum1=sum1+ans[j];
            }
            for(int k=mid;k<ans.size();k++){
                sum2=sum2+ans[k];
            }
            if(sum1==sum2) count++;
        }return count;
    }
};
