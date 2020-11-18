bool canMakeArithmeticProgression(vector<int>& arr) {
        
    if(arr.size() == 2) return true;
    
    sort(arr.begin(), arr.end());
    
    for(int i=0; i<arr.size()-2; ++i) {
        
        if((arr[i+1]-arr[i]) != (arr[i+2]-arr[i+1])) return false;
    }
    
    return true;
}
