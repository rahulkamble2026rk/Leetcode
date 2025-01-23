class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {  
        int n=numCourses;
        vector<int>indegree(n,0);  
        vector<vector<int>>adjList(n); //we don't know the col number here , so use the  n only here

        for(int i=0;i<prerequisites.size();i++)
        {  
            int x=prerequisites[i][0]; 
            int y=prerequisites[i][1];

            adjList[y].push_back(x); // before going to the y you have to travers tehe x so y->x
            indegree[x]++;
        }
        queue<int>que; 
         
         for(int i=0;i<indegree.size();i++)
         {
            if(indegree[i]==0)
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

            for(auto it:adjList[node])
            {
                indegree[it]--; 
                if(indegree[it]==0)
                {
                    que.push(it);
                }
            }
         } 
         return topo.size()==numCourses;
    }
};