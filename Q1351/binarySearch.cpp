// Runtime 40ms
// Reference (https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/discuss/510217/C%2B%2B-Three-Methods)

int countNegatives(vector<vector<int>>& grid) {
        
    int result = 0;
    
    for(const vector<int>& row: grid) {
        
        result += (upper_bound(row.rbegin(), row.rend(), -1) - row.rbegin());
    }
    
    return result;
}
