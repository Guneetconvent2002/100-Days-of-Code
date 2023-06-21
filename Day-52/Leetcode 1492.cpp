class Solution {
public:
    int kthFactor(int n, int k) {
        int position = 0;
        
        for(int i=1; i<=n; i++){
            if(n % i == 0){
                position++;
                if(position == k) return i;
            }
        }
        return -1;
    }
};