class NumArray {  //TC:O(LOGN) 
    
    class SegmentTree{   
        public:
        int start , end;
        SegmentTree *right , *left;
        int sum;
                  ///parametirised constructor
        SegmentTree(int start , int end){
            this->start = start;
            this->end = end;
            this->right = NULL;
            this->left = NULL;
            this->sum = 0;
        }
    };
    
    SegmentTree* root; ///root is initially NULL
    vector<int>numbers; 
    
public: /// TC: O(N)
    SegmentTree* constructSegmentTree(vector<int>& nums,int start,int end){
        //base condition
        if(start > end){
            return NULL;
        }
        //creating the node in SEGMENT TREE-------------
        SegmentTree* node = new SegmentTree(start,end);
        
        if(start == end){
            node->sum = nums[start];
            return node;
        }
        
        int mid = start + (end-start)/2;
        
        node->left = constructSegmentTree(nums,start,mid);
        node->right = constructSegmentTree(nums,mid+1,end);
        
        if(node->left != NULL and node->right != NULL){
            node->sum = node->left->sum + node->right->sum;
        }else if(node->left != NULL){
            node->sum = node->left->sum;
        }else if(node->right != NULL){
            node->sum = node->right->sum;
        }
        //else
        return node;
    }
    
    // TC : O(logn)
    void updateSegmentTree(vector<int>& nums,int index,int val,SegmentTree* node){
        
        if(node == NULL){
            return;
        }
        
        if(node->start == node->end){ //if leaf node to be updated
            node->sum = val;
        }else{
            int mid = (node->start  + node->end)>>1;
            if(index <= mid){
                updateSegmentTree(nums,index,val,node->left);
            }else{ //if(index > mid)
                updateSegmentTree(nums,index,val,node->right);
            }
             node->sum  = node->left->sum + node->right->sum;
        }
        
    }
    
    // TC : O(logn)
    int getSumRangeSegmentTree(int left , int right ,SegmentTree* node ){
         if(node == NULL){
            return 0;
        }
        
        if(left > right){
            return 0;
        }
        
        if(node->start == left and node->end == right ){ //if leaf node
            return node->sum;
        }else{
            int mid = (node->start + node->end)>>1;
            if(right <= mid){ //move left
                return getSumRangeSegmentTree(left,right,node->left);
            }else if(left > mid){ //move right
                return getSumRangeSegmentTree(left, right, node->right);
            }else{//consider both sides
                return getSumRangeSegmentTree(left,mid,node->left) + getSumRangeSegmentTree(mid+1, right, node->right);
            }
        }
        
        
    }
    ///////////////////////
    NumArray(vector<int>& nums) {//Initializes the object with the integer array nums.
        if(nums.size()==0) return;
        numbers = nums;
        root = constructSegmentTree(nums,0,nums.size()-1);
    }
    
    void update(int index, int val) {
        updateSegmentTree(numbers,index,val,root);
        return;
    }
    
    int sumRange(int left, int right) {
       return getSumRangeSegmentTree(left,right,root);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */