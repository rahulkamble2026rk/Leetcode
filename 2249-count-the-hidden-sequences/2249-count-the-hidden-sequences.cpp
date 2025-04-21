class Solution {
public:
    int numberOfArrays(vector<int>& diff, int lower, int upper)  
    {
        long sum=0,maxi=0,mini=0; 
        for(int i:diff)
        { 
            sum+=i; 
            maxi=max(maxi,sum); 
            mini=min(mini,sum);
        }  
        int Bound=upper-lower; 
        int Range=maxi-mini;
        return max(0, (Bound-Range )+1);
    }
};