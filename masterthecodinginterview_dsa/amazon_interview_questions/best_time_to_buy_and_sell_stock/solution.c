int maxProfit(int* prices, int pricesSize){
    if(pricesSize<2) return 0;
    
    int maxProfit=0;
    int buyPrice = prices[0];
    int profit;
    
    for(int i=1; i<pricesSize; i++){
        if(prices[i]<=buyPrice){
            buyPrice = prices[i];
        }else{
            profit = prices[i] - buyPrice;
            if(profit > maxProfit) maxProfit = profit;
        }
    }
    
    return maxProfit;
}
