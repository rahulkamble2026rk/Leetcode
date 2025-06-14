class Solution {
public:
    int minMaxDifference(int num)  
    {
        int rem = 0;   
        vector<int> store;
        int temp = num;

        
        while (num > 0) {
            rem = num % 10;  
            store.push_back(rem);
            num /= 10;
        }

        reverse(store.begin(), store.end());
        vector<int> store2 = store;

        int flag1 = 0, flag2 = 0;
        int first_value = 0, second_value = 0;

     
        for (int i = 0; i < store.size(); i++) {
            if (store[i] != 9 && flag1 == 0) {
                first_value = store[i];
                flag1 = 1;
            }
            if (store2[i] != 0 && flag2 == 0) {
                second_value = store2[i];
                flag2 = 1;
            }
        }

   
        for (int i = 0; i < store.size(); i++) {
            if (store[i] == first_value) store[i] = 9;
            if (store2[i] == second_value) store2[i] = 0;
        }

        
        int num1 = 0, num2 = 0, mul = 1;
        for (int i = store.size() - 1; i >= 0; i--) {
            num1 += store[i] * mul;
            num2 += store2[i] * mul;
            mul *= 10;
        }

        return num1 - num2;
    }
};
