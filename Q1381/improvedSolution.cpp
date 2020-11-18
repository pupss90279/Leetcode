// O(1) increment: 
// Reference (https://leetcode.com/problems/design-a-stack-with-increment-operation/discuss/539716/JavaC%2B%2BPython-Lazy-increment-O(1))

int size;
vector<int> stack;
vector<int> inc;

CustomStack(int maxSize) {
    size = maxSize;
}

void push(int x) {
    
    if(stack.size() < size) {
        
        stack.push_back(x);
        inc.push_back(0);
    }
}

int pop() {
    
    int i = stack.size()-1;
    
    if(i < 0) return -1;
    if(i > 0) inc[i-1] += inc[i];
    
    int temp = stack[i] + inc[i];
    
    stack.pop_back();
    inc.pop_back();
    
    return temp;
}

void increment(int k, int val) {
    
    int i = min(k, (int)stack.size()) - 1;
    if (i >= 0) inc[i] += val;
}
