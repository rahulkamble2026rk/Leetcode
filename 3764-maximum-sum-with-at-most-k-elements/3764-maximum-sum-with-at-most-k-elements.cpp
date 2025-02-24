class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) 
    {
        //At most k element from teh matrix 
        //The number of the elemetns taken from ith row does not exceed limits[i] 

        for(int i=0;i<grid.size();i++)
        {
            sort(grid[i].rbegin(),grid[i].rend());
        }
        priority_queue<int> pq;

        for(int i=0;i<grid.size();i++)
        {
            int size=limits[i]; 
            for(int j=0;j<size;j++)
            {   
                //cout<<"I am going inside the priority queue"<<grid[i][j]<<endl;
                pq.push(grid[i][j]);
            }
        } 

        long long sum=0;
        for(int i=0;i<k;i++)
        {
            sum+=pq.top(); 
           // cout<<"I am at the top"<<pq.top()<<endl;
            pq.pop();
        } 
        return sum;
    }
};