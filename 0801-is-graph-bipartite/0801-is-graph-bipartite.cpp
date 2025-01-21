class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n=graph.size(); 
        vector<int>colour(n,-1); 

        for(int i=0;i<n;i++)
        {
            if(colour[i]==-1)
            {
                if(dfs(i,0,colour,graph)==false)
                {
                    return false;
                }
            }
        } 
        return true;
    } 

    bool dfs(int node,int col,vector<int>&colour,vector<vector<int>>&adj)
    {
        colour[node]=col; 
        for(auto it:adj[node])
        {
            if(colour[it]==-1)
            {
                if(dfs(it,!col,colour,adj)==false)
                {
                    return false;
                }
            } 
            else if(colour[it]==col)  //same colour as the  current node and the previous colour 
            {
                return false;
            }
        } 
        return true;
    }
};