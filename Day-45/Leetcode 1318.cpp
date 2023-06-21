class Solution {
public:

    int numBits(int num){\
        int count = 0;
        while(num){
            if(num & 1) {count++;}
            num >>= 1;
        }

        return count;
    }

    int minFlips(int a, int b, int c) {
        return numBits((a | b) ^ c) + numBits(a & b & ((a | b) ^ c));
    }
};