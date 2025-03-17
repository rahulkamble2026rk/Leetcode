class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set<int> uniqueNumbers;
        int n = digits.size();

        for (int i = 0; i < n; i++) {       // Hundreds place
            if (digits[i] == 0) continue;   // Skip leading zero

            for (int j = 0; j < n; j++) {   // Tens place
                if (j == i) continue;       // Avoid using the same digit
                
                for (int k = 0; k < n; k++) {  // Units place
                    if (k == i || k == j) continue;  // Ensure uniqueness
                    if (digits[k] % 2 != 0) continue; // Last digit must be even

                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    uniqueNumbers.insert(num);
                }
            }
        }
        return uniqueNumbers.size();
    }
};
