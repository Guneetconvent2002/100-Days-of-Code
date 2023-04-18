class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int i;

        for(i=0; i<min(word1.size(), word2.size()); i++){
            ans.push_back(word1[i]);
            ans.push_back(word2[i]);
        }

        if(word1.size() > word2.size())
            ans += word1.substr(i);
        
        if(word1.size() < word2.size())
            ans += word2.substr(i);
        
        return ans;
    }
};