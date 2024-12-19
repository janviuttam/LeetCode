class Solution {
public:
    bool isValid(string s) {
        int n=s.length();
        stack<int> stack;
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                stack.push(s[i]);
            }
            else{
                if(stack.empty() || (s[i]==')' && stack.top()!='(')){
                    return false;
                }
                else if(stack.empty() || (s[i]=='}' && stack.top()!='{')){
                    return false;
                }
                else if(stack.empty() || (s[i]==']' && stack.top()!='[')){
                    return false;
                }
                stack.pop();
            }
        }
        if(stack.empty())
            return true;
        return false;
    }
};