/**
 * @param {string} s
 * @return {boolean}
 */

var isPalindrome = function(s) {

    function isAlphaNumeric(ch) {
        return /[a-zA-Z0-9]/.test(ch);
    }

    let l= 0;
    let r=s.length-1;

    while(l<r){
        while(l<r && !isAlphaNumeric(s[l])){
            l++;
        }
        while(l<r && !isAlphaNumeric(s[r])){
            r--;
        }
        if(s[l].toLowerCase()!==s[r].toLowerCase()){
            return false;
        }
        l++;
        r--;
    }
    return true;

};