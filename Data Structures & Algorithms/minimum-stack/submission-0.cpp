class MinStack {
private:
        stack <int> pilha;
        stack <int> pilha_min;
        int mini = INT_MAX;
public:
    MinStack() {
    }
    
    void push(int val) {
        pilha.push(val);
        if(!pilha_min.empty()) mini = min(val, pilha_min.top());
        else mini = val;
        pilha_min.push(mini);
        return;
    }
    
    void pop() {
        pilha.pop();
        pilha_min.pop();
        return;
    }
    
    int top() {
        return pilha.top();
    }
    
    int getMin() {
        return pilha_min.top();

    }
};
