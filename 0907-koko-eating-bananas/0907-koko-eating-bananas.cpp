class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h)  
    {
        int maxi=*max_element(piles.begin(),piles.end()); 
        int high=maxi; 
        int low=1; 
        int ans=maxi;
        while(low<=high)
        {
            int mid=(low+high)/2; 
            if(check(mid,piles,h))
            {
                high=mid-1; //as we want the minimum hr/banana , so check the lower values as well
                ans=mid;
            }  
            else 
            {
                low=mid+1;
            }

        } 
        return ans;
    } 
    bool check(int hr,vector<int>&piles,int total)
    {
        long long ans=0; 
        for(auto it:piles)
        {
            ans += ceil((double)it / hr);
        } 
        if(ans<=total)
        {
            return true;
        }
        return false;
    }
};