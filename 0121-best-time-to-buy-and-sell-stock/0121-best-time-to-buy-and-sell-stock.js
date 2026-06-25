/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let bestBuy=prices[0];
    let maxProfit=0;
    for(let i=1;i<prices.length;i++){
        if(prices[i]>bestBuy){
            maxProfit=Math.max(maxProfit,prices[i]-bestBuy);
        }
        bestBuy=Math.min(bestBuy,prices[i]);
    }
    return maxProfit;
};