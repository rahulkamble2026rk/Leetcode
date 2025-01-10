class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // here we have to keep the maximum the k maximum zero's in our slide
        int l = 0;
        int r = 0;
        int zerocount = 0;
        int maxsize = 0;
        int n = nums.size();
        while (r < n) 
        {
            if (nums[r] == 0) 
            {    
                zerocount++;
            }
                while(zerocount > k) 
                {
                    if(nums[l]==0)
                    {
                         zerocount--;
                    }
                   l++;
                } 
            
            if(zerocount<=k) 
            {
                maxsize = max(maxsize, r - l + 1); 
                r++;
            }
        }
        return maxsize;
    }
};