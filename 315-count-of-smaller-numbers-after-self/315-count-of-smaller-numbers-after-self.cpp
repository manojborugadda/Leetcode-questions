// //Giving RUNTIME error

// class SegmentTree{   
//         public:
//         int start , end;
//         SegmentTree *right , *left;
//         int sum;
//                   ///parameterised constructor
//         SegmentTree(int start , int end){
//             this->start = start;
//             this->end = end;
//             this->right = NULL;
//             this->left = NULL;
//             this->sum = 0;
//         }
//     };
    
// class Solution {
// public:
    
//     SegmentTree* constructSegmentTree(int start,int end){
//         //base condition
//         if(start > end){
//             return NULL;
//         }
//         //creating the node in SEGMENT TREE-------------
//         SegmentTree* node = new SegmentTree(start,end);
        
//         if(start == end){
//             return node;
//         }
//        int mid = (start+end)>>1;
        
//         node->left = constructSegmentTree(start,mid);
//         node->right = constructSegmentTree(mid+1,end);
//         return node;
//     }
    
//      void updateSegmentTree(SegmentTree* node,int index){
//          if(node == NULL){
//             return;
//         }
         
//          if(node->start == index and  node->end == index){ //if leaf node to be updated
//             node->sum += 1;
//         }else{
//             int mid = (node->start  + node->end)>>1;
//             if(index <= mid){
//                 updateSegmentTree(node->left,index);
//             }else{ //if(index > mid)
//                 updateSegmentTree(node->right,index);
//             }
//              node->sum  = node->left->sum + node->right->sum;
//         }  
//      }
    
//     int SumRangeSegmentTree(SegmentTree* node,int left,int right){
//         if(left > right) return 0;
//         if(node == NULL){
//             return 0;
//         }
//         if(node->start == left and node->end == right ){ //if leaf node
//             return node->sum;
//         }else{
//              int mid = (node->start + node->end)>>1;
//             if(right <= mid){ //move left
//                 return SumRangeSegmentTree(node->left,left,right);
//             }else if(left > mid){ //move right
//                 return SumRangeSegmentTree( node->right,left, right);
//             }else{//consider both sides
//                 return SumRangeSegmentTree(node->left,left,mid) + SumRangeSegmentTree( node->right,mid+1, right);
//             }
//         }
//     }
    
//     vector<int> countSmaller(vector<int>& nums) {
//         int n = nums.size();
//         if(n == 0) return {};
//         int mini = INT_MAX;
//         int maxi = INT_MIN;
//         for(int i = 0;i<n;i++){
//             mini = min(nums[i],mini);
//             maxi = max(nums[i],maxi);
//         }
        
//         //SegmentTree* root; ///root is initially NULL
//         vector<int>counts; 
        
//         SegmentTree* root = constructSegmentTree(mini,maxi);
        
//         for( int i = nums.size() - 1; i >= 0; i--){
//             //sum of particular element updated
//             updateSegmentTree(root,nums[i]);
//             //counting the elements which lies between the [min,nums[i]-1]
//             counts[i] = SumRangeSegmentTree(root,mini,nums[i]-1);
//         }
//         return counts;
//     }
// };


///https://leetcode.com/problems/count-of-smaller-numbers-after-self/discuss/1805978/Using-dynamic-Segment-Tree

//TC:O(LOGN) SC:(LOGN)
class Node{
public:
Node*left;
Node*right;
int start;
int end;
int sum;
};

class Solution {
public:
    Node*buildTree(int mini,int maxi){
    
    //base case
    if(mini==maxi){
        Node*newNode=new Node();
        newNode->left=NULL;newNode->right=NULL;
        newNode->sum=0;
        newNode->start=mini;
        newNode->end=mini;
        return newNode;
    }
    
    
    Node*root=new Node();
    int mid=mini+(maxi-mini)/2;
    root->left=buildTree(mini,mid);
    root->right=buildTree(mid+1,maxi);
    root->sum=0;
    root->start=mini;
    root->end=maxi;
    
    return root;
    
}

	void update(Node*root,int index){
    
    if(root==NULL) return;

    if(root->start==index && root->end==index){
        root->sum+=1;
        return;
    }
    int mid=root->start+(root->end-root->start)/2;
    if(index<=mid)
        update(root->left,index);
    else 
        update(root->right,index);
    root->sum=root->left->sum+root->right->sum;
    
    
  
}
 int SumRange(Node *root, int start, int end) {
if (root == NULL || start >end) {
  return 0;
}

if (root->start == start && root->end == end) {
  return root->sum;
}
int mid = root->start + (root->end - root->start) / 2;
if (end <= mid) {
  return SumRange(root->left, start, end);
}
else if (start > mid) {
  return SumRange(root->right, start, end);
}
return SumRange(root->left, start, mid) + SumRange(root->right, mid + 1, end);
  }

	vector<int> countSmaller(vector<int>& nums) {
    int mini=INT_MAX;
    int maxi=INT_MIN;
    for(int x:nums){
        if(x>maxi)maxi=x;
        if(x<mini)mini=x;
    }
  Node*root=buildTree(mini,maxi);
    vector<int>res;
     //so we have a binary indexed tree now fuck
    //we will make a update function which is not that tough to make
    for(int i=nums.size()-1;i>=0;i--){
        update(root,nums[i]);
        res.push_back(SumRange(root,mini,nums[i]-1));
    }
    reverse(res.begin(),res.end());
    return res;

		}
	};

