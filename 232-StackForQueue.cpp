class Queue {
public:
    stack<int> s;
    // Push element x to the back of queue.
    void push(int x) {
        s.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        stack<int>tmp;
        while(!s.empty()){
            tmp.push(s.top());
            s.pop();
        }
        tmp.pop();
        while(!tmp.empty()){
            s.push(tmp.top());
            tmp.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        int res;
        stack<int>tmp;
        while(!s.empty()){
            tmp.push(s.top());
            s.pop();
        }
        res=tmp.top();
        while(!tmp.empty()){
            s.push(tmp.top());
            tmp.pop();
        }
        return res;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s.empty();
    }
};
