class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) 
    {
    //     int xorsum=0; 
    //     for(int i=0;i<nums1.size();i++) 
    //     {
    //         for(int j=0;j<nums2.size();j++)
    //         {
    //             xorsum^=(nums1[i]^nums2[j]);
    //         }
    //     } 
    //     return xorsum;
    // } 

    int xorsum1 = 0, xorsum2 = 0;
        
      
        for (int num : nums1) {
            xorsum1 ^= num;
        }
        
      
        for (int num : nums2) {
            xorsum2 ^= num;
        }
        
        
        if (nums1.size() % 2 == 1 && nums2.size() % 2 == 1) {
            return xorsum1 ^ xorsum2;
        }
        else if (nums1.size() % 2 == 1) 
        {
            return xorsum2;
        } 
        else if (nums2.size() % 2 == 1) 
        {
            return xorsum1;
        }
        
        return 0;
    }
};