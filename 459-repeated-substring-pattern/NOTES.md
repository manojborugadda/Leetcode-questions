https://leetcode.com/problems/repeated-substring-pattern/solutions/3942459/o-n-2-time-and-o-n-space-but-easily-understandable-solution/

```
class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        length = len(s)
        for i in range(1, len(s)//2+1):
            substring = s[0:i]
            lengthSub = len(substring)
            if length % lengthSub== 0:
                coefficient = length// lengthSub
                if substring*coefficient == s:
                    return True
        return False
```



https://leetcode.com/problems/repeated-substring-pattern/solutions/3942314/easy/​
