class MyStack {
public:
    queue<int> q1, q2;
    int f=0;
    MyStack() {
        
    }
    
    void push(int x) {
        if(f==0) q1.push(x);
        else q2.push(x);
    }
    
    int pop() {
        if(f==0) {
            if(q1.size() == 0) return -1;
            while(q1.size() > 1) {
                q2.push(q1.front());
                q1.pop();
            }
            int ans = q1.front();
            q1.pop();
            f=1;
            return ans;
        }
        else {
            if(q2.size() == 0) return -1;
            while(q2.size() > 1) {
                q1.push(q2.front());
                q2.pop();
            }
            int ans = q2.front();
            q2.pop();
            f=0;
            return ans;
        }
    }
    
    int top() {
        if(f==0) {
            return q1.back();
        }
        else return q2.back();
    }
    
    bool empty() {
        if(f==0) return q1.empty();
        else return q2.empty();
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