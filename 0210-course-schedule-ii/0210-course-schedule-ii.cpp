class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {   
        int n= numCourses; 
        vector<int>indegree(n);
        vector<vector<int>>adjList(n);
         
        //step1:create the adjList
        for(int i=0;i<prerequisites.size();i++)
        {
            int x= prerequisites[i][0]; 
            int y= prerequisites[i][1]; 
            adjList[y].push_back(x); 
            indegree[x]++;
        } 
        
        //step2:puhs the 0base indgree node in the queue 
        queue<int>que; 
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]==0)
            {
                que.push(i);
            }
        }

        //step3:traverse over the queue 
        vector<int>ans; 
        while(!que.empty())
        {
            int node=que.front();  
            que.pop(); 
            ans.push_back(node); //this is the 0indgree element 
            for(auto it:adjList[node])
            {
                indegree[it]--;  
                if(indegree[it]==0)
                {
                    que.push(it);
                }
            } 

        }
        if(ans.empty())
        {
            return {};
        } 
        return (ans.size() == numCourses) ? ans : vector<int>();
    }
};