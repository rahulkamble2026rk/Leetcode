// class Solution {
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites)  
//     {
//         //1.firstly create the adjecny list:          
//         vector<vector<int>>adjancy_list(numCourses); 
//         for(auto it:prerequisites) 
//         {
//             adjancy_list[it[1]].push_back(it[0]); 
//         }  

//         //If there is formation of the cycle then it is not possible to complete the course so for cycle use the BFS Apply the  
//         //2.BFS require: queue , visited array  
//         queue<pair<int,int>>que;  //one is child and another is the parent where teh child is get form
//         vector<int>visited(numCourses,0);
//         vector<int>ans;
//         for(int i=0;i<numCourses;i++)
//         {
//             if(visited[i]==0)
//             { 
//                 if(detect_cycle(i,que,adjancy_list,visited,ans)==true) //use this one for the any type of the bfs question when there is no any source is mentioned 
//                 {
//                     return false;
//                 }
//             }
//         }
//         return true;
//     } 
    
//     bool detect_cycle(int node,queue<pair<int,int>>&que, vector<vector<int>>adjancy_list,vector<int>&visited,vector<int>&ans)
//     {
//         que.push({node,-1});  //intially the parent of the source is -1 
//         visited[node]=1;  
//         ans.push_back(node);
//         while(!que.empty())
//         {
//             int child_node=que.front().first; 
//             int parent_node=que.front().second; 
//              que.pop();
//             for(auto it:adjancy_list[child_node])
//             {
//                 if(!visited[it])
//                 {   
//                     visited[it]=1;
//                     que.push({it,child_node}); 
//                     ans.push_back(it);
//                 }  
//                 else if(visited[it] && it!=parent_node)
//                 {
//                     return true; //then there is presence of the cycle
//                 }
//             }
//         } 
//         return false;
//     }
// }; 

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)  
    {   
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
            return false;
        } 
        return true;
    }
};