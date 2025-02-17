class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {   
        int sum = 0; 
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {    
            bool flag = false; 
            bool flag2=false;
            if (i - k >= 0 && nums[i] > nums[i - k]) { 
                flag = true; 
            }
            
            if (i + k < n && nums[i] > nums[i + k]) { 
                flag2 = true; 
            }
            
            // If neither i-k nor i+k exists, nums[i] is automatically "good"
           if ((i - k >= 0 && i + k < n && flag && flag2) || // Both indices exist, both must be satisfied
    (i - k < 0 && i + k >= n) ||                  // Neither index exists
    (i - k >= 0 && i + k >= n && flag) ||         // Only left index exists
    (i - k < 0 && i + k < n && flag2))            // Only right index exists
 {  
                sum += nums[i];
            }
            
            
        } 
        
        return sum;
    }
};
