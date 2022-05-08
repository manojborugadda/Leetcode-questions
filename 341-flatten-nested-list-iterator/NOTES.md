https://leetcode.com/problems/flatten-nested-list-iterator/discuss/2018658/C%2B%2B-Simple-Solution-Explained-Using-Recursion
​
​
​
class NestedIterator {
public:
​
//Initialize the global vector which will be our flatten list and our answer, which we will make by pushing elements
vector<int> result;
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
void Solve(vector<NestedInteger> nestedList) {
//Iterating over the list
for(auto u : nestedList) {
//If integer, simply push to result
if(u.isInteger()) {
result.push_back(u.getInteger());
}
//If a list otherwise, call recursively again
else {
Solve(u.getList());
}
}
}