class Solution {
public:
    int furthestDistanceFromOrigin(string moves)  
    {
        // 'L' 'R' and '_'  
        // string rep/ your movement on number line from starting from origin 0 

        // ith move you can choose one of the follwing direcctions: 
        //move to left if moves[i]='L' or moves[i]='_' 
        // move to right if moves[i]='R' or moves[i]='_' 

        int L = 0, R = 0, B = 0;
        for (auto c : moves) {
            if (c == 'L') {
                L++;
            } else if (c == 'R') {
                R++;
            } else {
                B++;
            }
        }
        return abs(L - R) + B;
    }
};