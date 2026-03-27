class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        
        k = k % m; // important optimization
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                
                if(i % 2 == 0){
                    // even row → right shift
                    if(mat[i][j] != mat[i][(j - k + m) % m])
                        return false;
                }
                else{
                    // odd row → left shift
                    if(mat[i][j] != mat[i][(j + k) % m])
                        return false;
                }
            }
        }
        
        return true;
    }
};