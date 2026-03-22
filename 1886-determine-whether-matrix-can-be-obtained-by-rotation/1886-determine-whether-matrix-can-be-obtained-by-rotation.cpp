class Solution {
public:
    int n;

    void rotate(vector<vector<int>>& mat){
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                swap(mat[i][j],mat[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            reverse(mat[i].begin(),mat[i].end());
        }
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        n=mat.size();
        for(int i=0;i<4;i++) {
            bool equal=true;
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(mat[j][k]!=target[j][k]){
                        equal=false;
                        break;
                    }
                    if(!equal){
                        break;
                    }
                }
            }
            if(equal){
                return true;
            }
            rotate(mat);
        }
        return false;
    }
};