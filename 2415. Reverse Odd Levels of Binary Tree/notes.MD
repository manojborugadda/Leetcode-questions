https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/solutions/6166691/c-solution-bfs-solution-detailed-explanation/?envType=daily-question&envId=2024-12-20

https://www.youtube.com/watch?v=QY0YQTzECUA

Perform a level-order traversal using a queue.
For each level:
Collect the nodes in a vector.
If the level is odd, reverse the node values by swapping values symmetrically.
Continue until all levels are processed.
Return the modified tree.

Time Complexity:
O(n), where n is the number of nodes in the binary tree. Each node is visited once, and for odd levels, reversing node values takes linear time with respect to the number of nodes at that level.
Space Complexity:

O(w), where w is the maximum width of the tree (i.e., the number of nodes at the largest level). This is required to store nodes at each level in the queue and vector.
