// class Solution {
// public:
//     vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B)  
//     {
//         vector<int>ans; 
//         int n=A.size();
//         for(int i=0;i<n;i++)
//         {
//             ans.push_back(check(A,B,i));
//         } 
//         return ans;
//     } 
//     int check(vector<int>A,vector<int>B,int n)
//     {  
//         int count=0;
//         for(int i=0;i<=n;i++)
//         {
//             if(find(B.begin(),B.begin()+n+1,A[i])!=B.begin()+n+1)
//             {
//                 count++;
//             }
//         } 
//         return count;
//     }
// };

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B)  
    { 
        map<int,int>freqA; 
        map<int,int>freqB;  
        vector<int>ans;
        int n=A.size();  
        int commonCount=0;
        for(int i=0;i<n;i++)
        {
            freqA[A[i]]++; 
            freqB[B[i]]++; 
            if (freqB[A[i]] == 1) 
            { 
                commonCount++;
            } 
             if(A[i] != B[i] && freqA[B[i]] == 1) 
             { 
                commonCount++;
            }
             ans.push_back(commonCount);
        } 
       return ans;
        
    }
};