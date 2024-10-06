class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        // recursive call bcoz we need sentence1 to be smaller
        if(sentence1.length()>sentence2.length()){
            return areSentencesSimilar(sentence2,sentence1);
        }
        vector<string>smaller,larger;
        stringstream ss1(sentence1),ss2(sentence2);
        string word;
        // Split sentence1 into words and store in smaller vector.
        while(ss1>>word){
            smaller.push_back(word);
        }
        // Split sentence2 into words and store in larger vector.
        while(ss2>>word){
            larger.push_back(word);
        }
        int start=0;
        int end1=smaller.size()-1;
        int end2=larger.size()-1;
        while(start<=end1 && smaller[start]==larger[start]){
            start++;
        }
        while(start<=end1 && smaller[end1]==larger[end2]){
            end1--;
            end2--;
        }
        return start>end1;
    }
};
