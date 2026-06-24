/**
 * @param {number[]} nums
 * @return {boolean}
 */
var containsDuplicate = function(nums) {
    let st=new Set();

    for(let n of nums){
        if(st.has(n)){
            return true;
        }
        st.add(n);
    }
    return false;
};