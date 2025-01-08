class MinStack {
public:
    stack<int> stk;
    stack<int> minStk;  // Stack to track minimum values

    MinStack() {}

    void push(int val) {
        stk.push(val);
        // Push the minimum value (either val or the current minimum)
        if (minStk.empty() || val <= minStk.top()) {
            minStk.push(val);
        } else {
            minStk.push(minStk.top());
        }
    }

    void pop() {
        stk.pop();
        minStk.pop();  // Pop from both stacks
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minStk.top();
    }
};
