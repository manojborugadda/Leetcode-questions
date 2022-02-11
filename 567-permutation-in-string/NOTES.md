* In case the size if s1 > s2, its permutation can't exist in s2->return false.
* Otherwise run a loop till length of s1 string,store in v1 and v2 vectors, the int value for chars in s1 and s2 storing a as 0, b as 1...
* check if both vectors match, freq of both strings' char match->return true.
* Otherwise, start a loop from i=sz1 till end of s2, remove out of scope char and include current char in v2
* compare each time for vector matching and return true
* Else return false.