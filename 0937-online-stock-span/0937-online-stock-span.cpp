class StockSpanner {
public: 
    stack<pair<int,int>>stk; 
    int ind=-1; 
    int ans=0;
    StockSpanner() 
    {
        ind=-1;
    }
    
    int next(int price) 
    {  
        ind+=1;
        int x=price; 
        while(!stk.empty()&&x>=stk.top().first)   //find teh previous greater element along with it's index
        {  
            stk.pop();
        } 
        ans=ind-(stk.empty()?-1:stk.top().second); 
        stk.push({x,ind}); 
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */