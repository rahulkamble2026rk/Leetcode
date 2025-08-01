class MyStack {
public: 
    queue<int>que;
    MyStack()  
    {
        
    }
    
    void push(int x)  
    {
        int size=que.size(); 
        que.push(x); 
        for(int i=1;i<=size;i++)
        {
            que.push(que.front()); 
            que.pop();
        } 

    }
    
    int pop()  
    {
        if(!que.empty())
        {
           int val=que.front();  
           que.pop(); 
           return val;
        } 
        return -1;
    }
    
    int top()  
    {
        return que.front();
    }
    
    bool empty()  
    {
        if(que.size()==0)
        {
            return true;
        } 
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */