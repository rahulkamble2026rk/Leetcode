class Solution {
public:
    int minimumRecolors(string blocks, int k)  
    { 
        int n=blocks.size();  
        int ans=1e9;
        for(int i=0;i<=n-k;i++)
        { 
            int white=0;
            for(int j=i;(j-i)<k;j++)
            {
                if(blocks[j]=='W')
                {
                    white++;
                }
            } 
            cout<<white<<endl;
            ans=min(ans,white);
        } 
        if(ans==1e9) return 0; 
        return ans;
    }
};