https://www.youtube.com/watch?v=vRPDOZ2U0hs

https://leetcode.com/problems/design-add-and-search-words-data-structure/solutions/3314943/day-78-trie-dfs-easiest-beginner-friendly-sol/


```
Time complexity :
The time complexity of the addWord function is O(k), where k is the length of the word being added. This is because we are traversing through the characters of the word and creating new nodes in the Trie for each character. Therefore, the total time complexity of adding n words of total length m is O(m*n).

The time complexity of the search function depends on the length of the input word and the size of the Trie. In the worst case, we have to search through all the nodes of the Trie, which is O(26^k), where k is the length of the input word. Therefore, the time complexity of the search function is O(26^k), where k is the length of the input word.

However, in the best case, we can return early if the prefix of the input word does not exist in the Trie, which can reduce the time complexity significantly. Moreover, if the input word contains '.', we need to search through all possible child nodes of the current node, which is 26 in this case. Therefore, the actual time complexity of the search function can be much less than the worst-case scenario.

Space complexity :
The space complexity of the Trie is O(nm), where n is the number of words and m is the average length of the words. This is because we are creating a new node for each character of each word. Therefore, the total number of nodes in the Trie is proportional to nm. However, in the worst case, when all the words have no common prefix, the space complexity can be as high as O(26^m), where m is the length of the longest word. Therefore, the space complexity of the Trie depends on the input data and can be very high in certain cases.
```

