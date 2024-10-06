class Solution {//TC:O(N+M)+O(min(n,m))  SC:O(n+m)
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
    if(sentence1.length() > sentence2.length()) {//recursive call bcoz we need sentence1 to be smaller
        return areSentencesSimilar(sentence2,sentence1);
    }
    vector<string>v1,v2;
    // Used for breaking words
    stringstream ss(sentence1);
    stringstream ss1(sentence1);
    // To store individual words
    string Word;
    while (ss >> Word) {
       v1.push_back(Word);
    }
    while (ss1 >> Word) {
       v2.push_back(Word);
    }


    int start = 0 , end1 = v1.size()-1 , end2 = v2.size()-1;
    //finding prefix words
    while(start <= end1 and sentence1[start] == sentence2[start]) {
        start++;
    }
    //finding suffix words
    while(start <= end1 and sentence1[end1] == sentence2[end2]) {
        end1--;
        end2--;
    }
    return start > end1; //if we traverse all the small string elements beyond end1 it means we can make the strings equal

    }
};
