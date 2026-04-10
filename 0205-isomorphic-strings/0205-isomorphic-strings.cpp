class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> m1, m2;

        for(int i = 0; i < s.size(); i++) {
            char c1 = s[i];
            char c2 = t[i];

            // check s -> t
            if(m1.count(c1) && m1[c1] != c2) return false;

            // check t -> s
            if(m2.count(c2) && m2[c2] != c1) return false;

            m1[c1] = c2;
            m2[c2] = c1;
        }

        return true;
    }
};