class Solution {
public:

    void solve(vector<string> &v, int open, int close, string s, int n){
        if(open == n && close == n){
            v.push_back(s);
            return;
        }
        
        if(close > open) return;

        if(open < n)
        solve(v, open+1, close, s + "(", n);
        
        if(close < n)
        solve(v, open, close+1, s + ")", n);
    }

    vector<string> generateParenthesis(int n) {
        int open = 0, close = 0;
        string s = "";
        vector<string> ans;
        
        solve(ans, open, close, s, n);
        return ans;
    }
};