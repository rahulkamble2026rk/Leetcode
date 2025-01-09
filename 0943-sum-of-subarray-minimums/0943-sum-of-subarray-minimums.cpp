// class Solution {
// public:
//     int sumSubarrayMins(vector<int>& arr) 
//     {   
//         const int MOD = 1000000007;
//         int sum=0;
//         for(int i=0;i<arr.size();i++)
//         {   int mini=INT_MAX;
//             for(int j=i;j<arr.size();j++)
//             {
//                 mini=min(mini,arr[j]); 
//                 sum=(sum+mini)%MOD;
//             }
//         } 
//         return sum;
//     }
// };  

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) 
    {   
        const int MOD = 1000000007;  
         
         vector<int>NSE=getNSE(arr);
         vector<int>PSE=getPSE(arr); 
        long long sum=0; 
        int left=0,right=0;
         for(int i=0;i<arr.size();i++)
         {
            left=i-PSE[i]; //this will give the previous smaller element index 
            right=NSE[i]-i;   //this will give the next smaller element index 
            sum=(sum+right*left*1LL*arr[i])%MOD;
         } 
         return sum;
    } 
    vector<int> getNSE(vector<int>arr)
    {
        vector<int>nse; 
        stack<int>stk; 
        int n=arr.size(); 
        for(int i=n-1;i>=0;i--)
        {
            int x=arr[i]; 
            while(!stk.empty()&&arr[stk.top()]>=x)  //instead of comparing hte element we are comapring the indcies here
            {
                stk.pop();
            } 
            if(!stk.empty())
            {
                nse.push_back(stk.top());
            } 
            else 
            {
                nse.push_back(n);
            } 
            stk.push(i); ///storing the index to find the no.of the subarray*number[i];
        }  
        reverse(nse.begin(),nse.end());
        return nse;
    } 
    vector<int> getPSE(vector<int>arr)
    {
        vector<int>gse; 
        int n=arr.size();  
        stack<int>stk;
        for(int i=0;i<n;i++)
        {
            int x=arr[i]; 
            while(!stk.empty()&&arr[stk.top()]>x)
            {
                stk.pop();
            } 
            if(!stk.empty())
            {
                gse.push_back(stk.top());
            } 
            else
            {
                gse.push_back(-1);
            } 
            stk.push(i);
        }  
       
        return gse;
    }
};