typedef long long ll;
class Solution {
public:
    int minOperations(vector<int>& nums, int k) 
    {
        priority_queue<ll, vector<ll>,greater<ll>>que; 
        for(int i:nums) 
        {
            que.push(i);
        } 

        int count=0; 
        while(1 && que.size()>=2)
        {
            ll x=que.top(); 
            que.pop(); 
            ll y=que.top(); 
            que.pop(); 
            if(min(x,y)>=k)
            {
                break;
            } 
            else
            {
                que.push(min(x,y)*2+max(x,y)); 
                count++;
            }
        } 
        return count;
    }
};