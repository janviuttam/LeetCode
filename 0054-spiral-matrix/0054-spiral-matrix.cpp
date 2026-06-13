class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int top=0, bottom=n-1, left=0, right=m-1;
        vector<int> ans;

        while(top<=bottom && left<=right){
            //for top values
            for(int j=left; j<=right; j++){
                ans.push_back(matrix[top][j]);
            }
            top++;

            //for right values
            for(int j=top; j<=bottom; j++){
                ans.push_back(matrix[j][right]);
            }
            right--;
            //for bottom values
            if(top<=bottom){
                for(int j=right; j>=left; j--){
                    ans.push_back(matrix[bottom][j]);
                }
                bottom--;
            }
            //for left values
            if(left<=right){
                for(int j=bottom; j>=top; j--){
                    ans.push_back(matrix[j][left]);
                }
                left++;
            }
        }
        return ans;
    }
};