class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>>adjList(n);  
        vector<int>indegree(n,0);
        //reverse the graph first for the outdegree 
        for(int i=0;i<edges.size();i++)
        {
            adjList[edges[i][0]].push_back(edges[i][1]); 
            indegree[edges[i][1]]++;
        } 
 
        vector<int>ans;
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]==0)
            {
                ans.push_back(i);
            }
        } 

        if(ans.size()==1)
        {
            return ans[0];
        } 
        return -1;
    }
};