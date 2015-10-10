class Solution:
    # @param prices, a list of integer
    # @return an integer
    def maxProfit(self, prices):
        B=[0 for i in range(len(prices))]
        C=list(B)
        if len(prices) <= 1 : return 0
        minF, maxB = prices[0], prices[len(prices)-1]
        for i in range(len(prices)) :
            minF = min(minF, prices[i])
            B[i] = prices[i] - minF
            maxB = max(maxB, prices[len(prices)-i-1])
            C[len(prices)-i-1] = maxB - prices[len(prices)-i-1]
        maxF, maxB = B[0], C[len(C)-1]
        for i in range(len(B)) :
            B[i] = max(maxF, B[i])
            C[len(C)-i-1] = max(maxB, C[len(C)-i-1])
            maxF, maxB = B[i], C[len(C)-i-1]
        maxR = 0
        for i in range(0, len(prices)) :
            maxR = max(maxR, (0 if i-1<0 else B[i-1])+C[i])
        return maxR
