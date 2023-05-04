class Solution {
public:
    string predictPartyVictory(string senate) {
        if(senate.size() == 1 || senate.size() == 2) return senate[0] == 'R' ? "Radiant" : "Dire";

        queue<int> qr, qd;

        int n = senate.size();

        for(int i=0; i<n; i++)
            senate[i] == 'R' ? qr.push(i) : qd.push(i);


        while(!qr.empty() && !qd.empty()){
            int rfront = qr.front(), dfront = qd.front();
            qr.pop(); qd.pop();
            
            rfront < dfront ? qr.push(rfront + n) : qd.push(dfront + n);
        }

        return !qr.empty() ? "Radiant" : "Dire";
    }
};