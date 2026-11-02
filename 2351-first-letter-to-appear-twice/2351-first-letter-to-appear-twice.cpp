class Solution {
public:
    char repeatedCharacter(string s) {
        map<char,int>mp;

        for(int i=0;i<s.size();i++){
            if(mp[s[i]]==1){
                mp[s[i]]++;
                return s[i];
            }
            else
                mp[s[i]]++;
        }
        return s[0];
    }
};