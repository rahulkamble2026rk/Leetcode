//Here there is need of teh two stack to maintain the front of the queue property
class MyQueue {
public: 
    stack<int>stk1; 
    stack<int>stk2;
    MyQueue()  
    {
        
    }
    
    void push(int x)  
    {
        //when we want to push the element then we have to put all element in teh another stack 
        while(!stk1.empty())
        {
            stk2.push(stk1.top()); 
            stk1.pop();
        } 

        stk1.push(x);  

        while(!stk2.empty())
        {
            stk1.push(stk2.top()); 
            stk2.pop();
        }

    }
    
    int pop()  
    {   
        if(!stk1.empty())
        {
            int val=stk1.top();  
            stk1.pop();
            return val; 
        } 
       return -1;
        
    }
    
    int peek()  
    {
        return stk1.top();
    }
    
    bool empty()  
    {
        if(stk1.size()==0)
        {
            return true;
        } 
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */