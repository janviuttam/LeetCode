class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int L = 0, R = 0, blank = 0;

        for(char c : moves) {
            if(c == 'L') L++;
            else if(c == 'R') R++;
            else blank++;
        }

        int option1 = abs((L + blank) - R); // all blanks → L
        int option2 = abs(L - (R + blank)); // all blanks → R

        return max(option1, option2);
    }
};