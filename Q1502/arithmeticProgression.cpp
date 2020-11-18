// Arithmetic Progression: 
// Reference (https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/discuss/720205/Two-Solution-or-Brute-Force-O(nlogn)-or-Optimize-O(n)-or-AP-Explained )

bool canMakeArithmeticProgression(vector<int>& arr) {
    
    int minNum = arr[0];
    int sum = 0;
    vector<int> numD(arr.size(), 0);
    
    for(int i=0; i<arr.size(); ++i) {
        
        if(arr[i]<minNum) minNum = arr[i];
        sum += arr[i];
    }
    
    if(sum == minNum*arr.size()) return true;
    
    if((sum-minNum*arr.size())%(arr.size()*(arr.size()-1)/2) != 0) return false;
    
    int d = (sum-minNum*arr.size())/(arr.size()*(arr.size()-1)/2);
    
    for(int i=0; i<arr.size(); ++i) {
        
        if((arr[i]-minNum)%d != 0) return false;
        
        int curNumD = (arr[i]-minNum)/d;
        
        if(curNumD<0 || curNumD>arr.size() || numD[curNumD]!=0) return false;
        ++numD[curNumD];
    }
    
    return true;
}
