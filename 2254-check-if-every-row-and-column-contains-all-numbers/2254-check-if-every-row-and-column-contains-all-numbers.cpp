class Solution {
public:
    bool checkValid(vector<vector<int>>& board)  
    {
        int n=board.size(); 
        int m=board[0].size(); 

        for(int i=0;i<n;i++)
        {
            vector<int>vct=board[i]; 
            if(check(vct,n)==false)
            {
                return false;
            }  
            vct.clear();  
        } 

        vector<int>vct2;
        for(int j=0;j<m;j++)
        {
           for(int i=0;i<n;i++)
           {
                vct2.push_back(board[i][j]);
           } 

           if(check(vct2,n)==false)
           {
                return false;
           }  
            vct2.clear();
        } 

        return true; 
    } 

    bool check(vector<int>vct,int n)
    {  
        map<int,int>stdmap; 
        for(int i=0;i<vct.size();i++)
        {
            stdmap[vct[i]]++;
        }   

        for(int i=1;i<=n;i++)
        {
            if(stdmap.find(i)==stdmap.end())
            {
                return false;
            }
        }

        return true; 
    }
};