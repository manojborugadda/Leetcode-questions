/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    //Initialize the global vector which will be our flatten list and our answer, which we will make by pushing elements
    vector<int>result;
    //Initialize the current iterator for the flatten list we declared above, to check if we are out of bounds or not for is hasNext() method
    int i = 0;
    
    //This is a recursive function
	// Why we are using recursion here ?
	// Ans: As in this test case nestedList = [1,[4,[6]]]
	
	// We start iterating the list, we found 4 as integer, we pushed it into our result vector.
	// Then we get a nested list, which infact has a nested list in itself [4, [6]],6 here is in nested list of this list
	
	// So, we check if an element is integer, we simply pushes that to our result
	// Otherwise if the element is a list we call the function recursively for this element
	// And if this list contains more nested lists, it will call for them too
	
    
    
//From the above NestedInteger interface defination we have 3 functions which we can use:

//1) isInteger() : To check whether the element is integer or or a nested list, it returns true in case of integer
//2) getInteger(): Get that integer after using isInteger() method
//3) getList(): If isInteger() returns false, it means it is a nested list which we cant get from this method

    
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        Solve(nestedList);
    }
    
   void Solve(vector<NestedInteger> &List) {
       for(int i = 0;i<List.size();i++){
           if(List[i]. isInteger() == true){ // if it is INTEGER we pushed it into the vector
               result.push_back(List[i].getInteger());
           }
           else{ // if it is Nested LIST we call the recursive Function 
               Solve(List[i].getList());
           }
       }
   }
    
    int next() {
        return result[i++];
    }
    
    bool hasNext() {
        if(i< result.size() ){
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */