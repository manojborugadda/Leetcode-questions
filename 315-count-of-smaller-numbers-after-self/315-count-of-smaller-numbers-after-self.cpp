

class SegmentTree{   
        public:
        int start , end;
        SegmentTree *right , *left;
        int sum;
                  ///parameterised constructor
        SegmentTree(int start , int end){
            this->start = start;
            this->end = end;
            this->right = NULL;
            this->left = NULL;
            this->sum = 0;
        }
    };
    
class Solution {
public:
    
    SegmentTree* constructSegmentTree(int start,int end){
        //base condition
        if(start > end){
            return NULL;
        }
        //creating the node in SEGMENT TREE-------------
        SegmentTree* node = new SegmentTree(start,end);
        
        if(start == end){
            return node;
        }
       int mid = (start+end)>>1;
        
        node->left = constructSegmentTree(start,mid);
        node->right = constructSegmentTree(mid+1,end);
        return node;
    }
    
     void updateSegmentTree(SegmentTree* node,int index){
         if(node == NULL){
            return;
        }
         
         if(node->start == index and  node->end == index){ //if leaf node to be updated
            node->sum += 1;
        }else{
            int mid = (node->start  + node->end)>>1;
            if(index <= mid){
                updateSegmentTree(node->left,index);
            }else{ //if(index > mid)
                updateSegmentTree(node->right,index);
            }
             node->sum  = node->left->sum + node->right->sum;
        }  
     }
    
    int SumRangeSegmentTree(SegmentTree* node,int left,int right){
        if(left > right) return 0;
        if(node == NULL){
            return 0;
        }
        if(node->start == left and node->end == right ){ //if leaf node
            return node->sum;
        }else{
             int mid = (node->start + node->end)>>1;
            if(right <= mid){ //move left
                return SumRangeSegmentTree(node->left,left,right);
            }else if(left > mid){ //move right
                return SumRangeSegmentTree( node->right,left, right);
            }else{//consider both sides
                return SumRangeSegmentTree(node->left,left,mid) + SumRangeSegmentTree( node->right,mid+1, right);
            }
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return {};
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i = 0;i<n;i++){
            mini = min(nums[i],mini);
            maxi = max(nums[i],maxi);
        }
        
        
        vector<int>counts(n,0); 
        
        SegmentTree* root = constructSegmentTree(mini,maxi);
        
         for(int i=nums.size()-1;i>=0;i--){
            //sum of particular element updated
            updateSegmentTree(root,nums[i]);
            //counting the elements which lies between the [min,nums[i]-1]
            counts[i] = SumRangeSegmentTree(root,mini,nums[i]-1);
        }
        return counts;
    }
};
