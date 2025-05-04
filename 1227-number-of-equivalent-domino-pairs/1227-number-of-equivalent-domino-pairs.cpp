class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes)  
    {
        vector<int>mark(dominoes.size(),0); 
         
         int ans=0;
        for(int i=0;i<dominoes.size();i++)
        {
            if(mark[i]==0)
            { 
                ans+=check(dominoes,i,mark);
            }
        } 
        return ans;
    } 

    int check(vector<vector<int>>dominoes,int i,vector<int>&mark)
    {   
        int num1=dominoes[i][0];
        int num2=dominoes[i][1]; 
        int n=dominoes.size(); 
        int count=0;
        for(int j=i;j<n;j++)
        {
            if( !mark[j]&&((dominoes[j][0]==num1 && dominoes[j][1]==num2)||(dominoes[j][0]==num2 && dominoes[j][1]==num1))) 
            {
                count++;  
                cout<<"First pair is: "<<dominoes[j][0]<<" "<<dominoes[j][1]<<" & second one is : "<<num1<<" "<<num2<<endl;
                mark[j]=1;
            }
        } 
         return (count * (count - 1)) / 2;
    }
};