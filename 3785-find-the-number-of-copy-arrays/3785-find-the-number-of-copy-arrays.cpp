class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) 
    {
        // vector<int>c; 
        // int n=original.size(); 
        // c.push_back(0); 

        // for(int i=1;i<n;i++)
        // {
        //     c.push_back(original[i]-original[i-1]);
        // } 

        // for(int i=1;i<n;i++)
        // {
        //     c[i]+=c[i-1];
        // } 

        // int maxi=bounds[0][1],mini=bounds[0][0];
        // for(int i=1;i<n;i++)
        // {
        //     int x=bounds[i][0],y=bounds[i][1]; 
        //     maxi=min(maxi,y-c[i]); 
        //     mini=max(mini,x-c[i]);
        // } 
        // if(maxi<mini) 
        // {
        //     return 0;
        // } 
        // return maxi-mini+1;

        vector<int>diff; 
        for(int i=1;i<original.size();i++)
        {
            diff.push_back(original[i]-original[i-1]);
        } 
             
        int low=bounds[0][0],high=bounds[0][1];
        for(int i=1;i<original.size();i++)
        {
            int x=low+diff[i-1]; 
            int y=high+diff[i-1]; 
            low=max(x,bounds[i][0]); 
            high=min(y,bounds[i][1]); 

            if(low>high) return 0;
        } 
        return high-low+1;
    }
};