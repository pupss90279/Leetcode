int size;
vector<int> stack;

CustomStack(int maxSize) {
    size = maxSize;
}

void push(int x) {
    
    if(stack.size() < size) {
        
        stack.push_back(x);
    }
}

int pop() {
    
    if(stack.size() > 0) {
        
        int temp = stack.back();
        stack.pop_back();
        return temp;
        
    } else {
        
        return -1;
    }
}

void increment(int k, int val) {
    
    for(int i=0; (i<k && i<stack.size()); ++i) {
        
        stack[i] += val;
    }
}
