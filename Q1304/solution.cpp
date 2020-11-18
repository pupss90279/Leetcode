// Derive rule from: f(i) + f(n-1-i) = 0

vector<int> sumZero(int n) {
        
    vector<int> result(n, 0);
    
    for(int i=0; i<n; ++i) {
        
        result[i] = 2*i-n+1;
    }
    
    return result;
}
