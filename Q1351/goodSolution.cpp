// Reference (https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/discuss/510217/C%2B%2B-Three-Methods)

int countNegatives(vector<vector<int>>& grid) {
        
    int m = grid.size();
    int n = grid[0].size();
    int i = 0;
    int j = n-1;
    
    
    int result = 0;
    
    while(i < m) {
        
        while(j > -1 && grid[i][j] < 0) --j;
        
        result += (n-j-1);
        
        ++i;
    }
    
    return result;
}
