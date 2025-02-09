class Solution {
public:
    int findPairs(vector<int>& nums, int k) 
    {  
        int count=0; 
        set<pair<int,int>>st;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i;j<nums.size();j++)
            {  
                if (i != j && abs(nums[i] - nums[j]) == k )
                {  
                    int small = min(nums[i], nums[j]);
                    int large = max(nums[i], nums[j]);
                    
                    // Insert only if it's not already present
                    if (st.find({small, large}) == st.end()) {
                        cout << nums[i] << " " << nums[j] << endl;
                        st.insert({small, large});
                    }
                }
               
            }
        } 
        return st.size();
    }
};