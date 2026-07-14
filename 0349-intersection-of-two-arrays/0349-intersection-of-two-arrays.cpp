class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st;

        for(int n:nums1){
            st.insert(n);
        }

        vector<int> ans;

        for(int x:nums2){
            if(st.count(x)){
                ans.push_back(x);
                st.erase(x);
            }
        }

        return ans;
    }
};