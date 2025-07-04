class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        priority_queue<int>que; 
        for(auto it:stones)
        {
            que.push(it);
        } 

        while(que.size()!=1 && que.size()!=0)
        {
            int x=que.top(); 
            que.pop();  
            int y=que.top(); 
            que.pop(); 

            if(x!=y)
            {
                que.push(abs(y-x));
            }
        } 

        if(que.size()==1)
        {
            return que.top();
        } 
        return 0;
    }
};