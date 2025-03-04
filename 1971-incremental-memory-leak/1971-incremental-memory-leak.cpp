class Solution {
public:
    vector<int> memLeak(int memory1, int memory2)  
    { 
         int second=1; 
         while (true) 
         {
            if (memory1 >= memory2) {
                if (memory1 >= second) {
                    memory1 -= second;
                } else {
                    break; // memory1 cannot satisfy allocation
                }
            } else {
                if (memory2 >= second) {
                    memory2 -= second;
                } else {
                    break; // memory2 cannot satisfy allocation
                }
            }

            // Check for potential overflow before incrementing
            if (second == INT_MAX) 
            {
                break; // Stop incrementing to avoid overflow
            }
             
            second++;
        }

        return {second, memory1, memory2};
    
    }
};