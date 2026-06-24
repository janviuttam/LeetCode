class Solution {
public:
    string countAndSay(int n) {
        string s = "1";

        for (int i = 2; i <= n; i++) {
            string temp = "";
            int count = 1;

            for (int j = 1; j <= s.size(); j++) {
                if (j < s.size() && s[j] == s[j - 1]) {
                    count++;
                } else {
                    temp += to_string(count);
                    temp += s[j - 1];
                    count = 1;
                }
            }

            s = temp;
        }

        return s;
    }
};