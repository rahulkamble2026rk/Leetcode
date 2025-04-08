class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        deque<int> dq(nums.begin(), nums.end());
        int steps = 0;

        while (dq.size() >= 3) {
            map<int, int> seen;
            bool hasDuplicates = false;

            for (int val : dq) {
                seen[val]++;
                if (seen[val] > 1) {
                    hasDuplicates = true;
                    break;
                }
            }

            if (!hasDuplicates) break;

            
            for (int i = 0; i < 3 && !dq.empty(); i++) {
                dq.pop_front();
            }
            steps++;
        }

     
        map<int, int> finalSeen;
        for (int val : dq) {
            finalSeen[val]++;
            if (finalSeen[val] > 1) {
                steps++; 
                break;
            }
        }

        return steps;
    }
};
