class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
     vector<int>inDegree(numCourses,0);  
        vector<vector<int>>adj_list(numCourses);
        for(auto it:prerequisites)
        {
            int depend=it[0]; 
            int preq=it[1];  
            adj_list[preq].push_back(depend);  //Direct push karasthi vector chi size agoadar declare keli pahijech
        } 
        for(int i=0;i<numCourses;i++)
        {
            for(auto it:adj_list[i])
            {
                inDegree[it]++;
            }
        } 

        queue<int>que; 
        for(int i=0;i<numCourses;i++)
        {
            if(inDegree[i]==0)
            {
                que.push(i);
            }
        } 

        vector<int>topo; 

        while(!que.empty())
        {
            int node=que.front(); 
            que.pop(); 
            topo.push_back(node); 
            for(auto it:adj_list[node])
            {
                inDegree[it]--;
                if(inDegree[it]==0)
                {
                    que.push(it);
                }
            }
        } 
        if(topo.size()!=numCourses)
        {
            return {};
        } 
        return topo;
    }
};