/**
 * @param {string} word1
 * @param {string} word2
 * @return {string}
 */
var mergeAlternately = function(word1, word2) {
    let n=word1.length;
    let m=word2.length;
    let ans="";
    let i=0; 
    let j=0;

    while(i<n || j<m){
        if(i<n){
            ans+=word1[i];
            i++;
        }
        if(j<m){
            ans+=word2[j];
            j++;
        }
    }
    return ans;
};