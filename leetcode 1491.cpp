class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(), salary.end());

        double sum = 0;
        int mx = INT_MIN, mn = INT_MAX;
        for(auto num : salary){
            mx = max(mx, num);
            mn = min(mn, num);
            sum += num;
        }

        sum -= mx + mn;

        return sum / (salary.size() - 2);
    }
};