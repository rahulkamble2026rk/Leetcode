class Solution {
public:
    int jump(vector<int>& nums) 
    {
        int jump=0; 
        int l=0; 
        int r=0;  
        int n=nums.size();
        while(r<n-1)
        {
           int farpoint=0; 
            for(int ind=l;ind<=r;ind++)
            {
                farpoint=max(ind+nums[ind],farpoint);
            } 
            l=r+1; 
            jump+=1; 
            r=farpoint;
        } 
        return jump;
    }
};