https://www.youtube.com/watch?v=iHp7fjw1R28


Time Complexity and Space Complexity:
Time complexity: O(n^2*m) //where n is the number of words in the input array and m is the average length of the words.
The checkConcatenate() function is called for each word in the input array, and for each call, it iterates through the word to check for possible concatenation, which takes O(m) time. The find() function of the set data structure takes O(log(n)) time on average. So, the total time complexity of the checkConcatenate() function is O(nmlog(n)). Since this function is called for each word in the input array, the total time complexity of the findAllConcatenatedWordsInADict() function is O(n^2mlog(n)).

Space complexity: O(n*m) //where n is the number of words in the input array and m is the average length of the words.
The space complexity O(nm), where n is the number of words in the input array and m is the average length of the words. The set data structure is used to store all the words in the input array, which takes O(nm) space.

https://leetcode.com/problems/concatenated-words/solutions/3103568/day-27-simple-recursion-dfs-easiest-beginner-friendly-sol/
