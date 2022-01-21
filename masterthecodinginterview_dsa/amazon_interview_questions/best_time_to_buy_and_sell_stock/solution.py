#python3
class Solution:
    def maxProfit(self, prices: 'List[int]') -> int:
        maxprofit = 0
        small = 0

        for i in range(1,len(prices)):
            if prices[i] < prices[small]:
                small = i
            else:
                profit = prices[i] - prices[small]
                maxprofit = profit if profit > maxprofit else maxprofit

        return maxprofit
