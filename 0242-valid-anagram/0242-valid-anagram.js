/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    if(s.length!==t.length){
        return false;
    }
    let mp={};

    for(let ch of s){
        mp[ch]=(mp[ch]||0)+1;
    }
    for(let ch of t){
        if(!mp[ch]){
            return false;
        }
        mp[ch]--;
    }
    return true;
};