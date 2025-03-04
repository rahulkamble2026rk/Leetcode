class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) 
    {
        //Firstly find teh LCS by tabulzation:  
        int size1=str1.size(); 
        int size2=str2.size();
        vector<vector<int>>dp(size1+1,vector<int>(size2+1,0)); 

        for(int i=0;i<=size1;i++)
        {
            if(i==0)
            {
                dp[i][0]=0;
            }
        }   

        for(int j=0;j<=size2;j++)
            {  
                if(j==0)
                {
                    dp[0][j]=0;
                }
            } 



        for(int i=1;i<=size1;i++)
        {
            for(int j=1;j<=size2;j++)
            {
                if(str1[i-1]==str2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                } 
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }  
 

        // for(int i=0;i<=size1;i++)
        // {
        //     for(int j=0;j<=size2;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     } 
        //     cout<<endl;
        // }
        //step2: print the lcs string
        string ans=""; 
        int i=size1,j=size2;  
        
        while(i>0 && j>0)
        {
            if(str1[i-1]==str2[j-1])
            {
                ans+=str1[i-1]; 
                // cout<<"I am going "<<str1[i-1]<<endl;
                i--; 
                j--;
            } 
            else if(dp[i-1][j]>dp[i][j-1])
            {
                ans+=str1[i-1];  
                // cout<<"I am going "<<str1[i-1]<<endl;
                i--;
            } 
            else 
            {
                ans+=str2[j-1];  
                // cout<<"I am going "<<str2[j-1]<<endl;
                j--;
            }
        } 
 

 //step3:this step is for the last remaingin element which remains at ind=0
        while(i>0)
        {
            ans+=str1[i-1]; 
            i--;
        }  
        while(j>0)
        {
            ans+=str2[j-1]; 
            j--;
        }


        //as we traverse from the bottom of the table to the top of the table so there is the reverse string is get printed  
        //so reverse the string  
        reverse(ans.begin(),ans.end()); 
        return ans;
    }
};