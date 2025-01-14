class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B)  
    {
        vector<int>ans; 
        int n=A.size();
        for(int i=0;i<n;i++)
        {
            ans.push_back(check(A,B,i));
        } 
        return ans;
    } 
    int check(vector<int>A,vector<int>B,int n)
    {  
        int count=0;
        for(int i=0;i<=n;i++)
        {
            if(find(B.begin(),B.begin()+n+1,A[i])!=B.begin()+n+1)
            {
                count++;
            }
        } 
        return count;
    }
};