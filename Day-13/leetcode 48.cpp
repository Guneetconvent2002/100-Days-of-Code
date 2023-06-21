class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int temp = arr[i][j];
                arr[i][j] = arr[j][i];
                arr[j][i] = temp;
            }
        }
    }
};