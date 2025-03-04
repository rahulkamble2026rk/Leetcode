class Solution {
public:
    bool checkPowersOfThree(int n)  
    {
        vector<int>vct; 
        for(int i=1;i<=(1e7+3);i*=3)
        {
                vct.push_back(i); 
        } 

        //  for(auto &i:vct)
        // {
        //         cout<<i<<endl;
        // }   
        int size=vct.size(); 
         unordered_map<int, unordered_map<int, int>> dp;
        return findoccurance(vct,n,size-1,dp);
       
    }  
    bool findoccurance(vector<int>vct,int target,int ind,unordered_map<int, unordered_map<int, int>>&dp)
    {   
        if(target==0)
        {
            return true;
        } 
         
         if(dp[ind].count(target))
         {
            return dp[ind][target];
         }
        if(ind==0) 
        {
            if(vct[ind]==target)
            {
                return true;
            } 
            else
            {
                return false;
            }
        } 
        
        bool nottake=findoccurance(vct,target,ind-1,dp); 
        bool  take=false; 
        if(target>=vct[ind])
        { 
            take=findoccurance(vct,target-vct[ind],ind-1,dp); 
           if (take) cout << "Selected: " << vct[ind] << endl;  
        } 
        return dp[ind][target]=(take||nottake);
    }
   
};