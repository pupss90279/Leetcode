// Reference (https://leetcode.com/problems/count-good-triplets/discuss/769821/Java.-O(n).-Well-it-is-really-O(1000-*-n))

int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        
    vector<int> numBeforeI(1001, 0);
    vector<int> numAfterI(1001, 0);
    int n = arr.size();
    int ans = 0;
    
    // indicating whether this number is in arr 
    // and before the number of middle point
    // first middle point is arr[1] so only arr[0] is before it
    numBeforeI[arr[0]] = 1;
    
    // set up for number after middle point
    // from arr[2] is after first middle point arr[1] 
    for(int i=2; i<n; ++i) {
        
        numAfterI[arr[i]]++;
    }
    
    // number in arr and smaller than I
    for(int i=1; i<1001; ++i) {
        
        numAfterI[i] = numAfterI[i-1] + numAfterI[i];
    }
    
    // loop through different middle points
    for(int i=1; i<n-1; ++i) {
        
        int middlePoint = arr[i];
        int firstPointLowerBound = max(0, middlePoint-a);
        int firstPointUpperBound = min(1000, middlePoint+a);
        int thirdPointLowerBound = max(0, middlePoint-b);
        int thirdPointUpperBound = min(1000, middlePoint+b);
        
        for(int firstPoint=firstPointLowerBound; firstPoint<=firstPointUpperBound; ++firstPoint) {
            
            // firstPoint is not present in arr
            if(numBeforeI[firstPoint] == 0) continue;
            
            int thirdPointLowerBoundUpdated = max(thirdPointLowerBound, firstPoint-c);
            int thirdPointUpperBoundUpdated = min(thirdPointUpperBound, firstPoint+c);
            
            if(thirdPointUpperBoundUpdated >= thirdPointLowerBoundUpdated) {
                
                if(thirdPointLowerBoundUpdated == 0) {

                    // numBeforeI[firstPoint]: number firstPoint in arr before current middle point
                    // numAfterI[thirdPointUpperBoundUpdated]: 
                    // number in arr after current middle point and smaller than thirdPointUpperBoundUpdated
                    ans += 
                        numBeforeI[firstPoint] * numAfterI[thirdPointUpperBoundUpdated];
                } else {
                    
                    ans += 
                        numBeforeI[firstPoint] * 
                        (numAfterI[thirdPointUpperBoundUpdated] - numAfterI[thirdPointLowerBoundUpdated-1]);
                }
            }
        }
        
        // put current middle point into numBeforeI
        numBeforeI[middlePoint]++;
        
        // take next middle point out from numAfterI
        for(int j=arr[i+1]; j<1001; ++j) {
        
            numAfterI[j]--;
        }
    }
    
    return ans;
}
