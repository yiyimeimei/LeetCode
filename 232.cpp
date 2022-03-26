class MyQueue {
private:
    stack<int> s1,s2;
public:
    MyQueue() {

    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty())
        {
            dump();      
        }
        int x = s2.top();
        s2.pop();
        return x;
    }
    
    int peek() {
        if(s2.empty())
        {
            dump();      
        }
        return s2.top();
    }

    void dump()
    {
        int len = s1.size();
        for(int i = 0; i < len; ++i)
        {
            s2.push(s1.top());
            s1.pop();
        }  
    }
    
    bool empty() {
        if(s1.empty() && s2.empty())
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