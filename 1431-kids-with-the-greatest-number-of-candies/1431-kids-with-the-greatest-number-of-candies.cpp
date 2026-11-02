class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxNum=candies[0];
        for(int i=1;i<candies.size();i++){
            if(candies[i]>maxNum){
                maxNum=candies[i];
            }
        }
        vector<bool> ans;

        for(int i=0;i<candies.size();i++){
            if(candies[i]+extraCandies >= maxNum){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};