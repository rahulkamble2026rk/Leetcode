class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) 
    {
        int n=arr.size(); 
        vector<vector<int>>dp(n,vector<int>(n,0)); 
        int maxLen=0; 
        for(int cur=2;cur<n;cur++)
        {
            int start=0; 
            int end=cur-1; 
            while(start<end)
            {
                int sum=arr[start]+arr[end]; 
                if(sum<arr[cur])
                {
                    start++;
                } 
                else if(sum>arr[cur])
                {
                    end--;
                } 
                else
                {
                    dp[end][cur] = dp[start][end] + 1;
                    maxLen = max(maxLen, dp[end][cur]);
                    start++;
                    end--;
                }

            }
        } 
        return (maxLen==0)?0:maxLen + 2;
    }
};