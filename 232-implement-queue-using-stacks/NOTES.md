class MyQueue {
// two stack to perform queue
stack<int>s1,s2;
public:
MyQueue() {
}
// NO hesitation in push operation directly push to s1
void push(int x) {
s1.push(x);
}
// main game in pop and peek operations since stack is LIFO but we want fifo so before popping , first push all element to second stack s2 and then pop from second
int pop() {
// checking second stack empty if yes toh fill all element from s1 if no then return top from s2
if(s2.empty()){
while(!s1.empty()){
s2.push(s1.top());
s1.pop();
}
int x=s2.top();
s2.pop();
return x;
}
else{
int x=s2.top();
s2.pop();
return x;
}
}
int peek() {
if(s2.empty()){
while(!s1.empty()){
s2.push(s1.top());
s1.pop();
}
int x=s2.top();
return x;
}
else{
int x=s2.top();
return x;
}
}
bool empty() {
return (s1.empty() && s2.empty());
}
};