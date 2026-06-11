#include <stack>

class MinStack {
private:
    stack<int> myStack;
    stack<int> orderStack;

public:

    MinStack() {
    }
    
    void push(int val) {
        myStack.push(val);
        if (orderStack.empty()){
            orderStack.push(val);
        }
        else {
            if (val < orderStack.top()){
                orderStack.push(val);
            }
            else {
                orderStack.push(orderStack.top()); //used to keep the size of btoh stacks the same
            }
        }
    }
    
    void pop() {
        myStack.pop();
        orderStack.pop();
    }
    
    int top() {
        return myStack.top();
    }
    
    int getMin() {
        return orderStack.top();
    }
};
