class Solution {
public:

    void MaxProfitFromHead(vector<int>& prices, vector<int>& res)
    {
        res.push_back(0);
        int min = prices[0];
        res.push_back(0);
        for(int i = 1; i < prices.size(); i++)
        {
            min = min < prices[i - 1] ? min : prices[i - 1];
            int profile = prices[i] - min;
            if(profile > res.back()) {res.push_back(profile);}
            else {res.push_back(res.back());}
        }
    }
    
    void MaxProfitFromTail(vector<int>& prices, vector<int>& res)
    {
        res.push_back(0);
        int max = prices[prices.size() - 1];
        res.push_back(0);
        for(int i = (int)(prices.size()) - 2; i >= 0; i--)
        {
            max = max > prices[i + 1] ? max : prices[i + 1];
            int profile = max - prices[i];
            if(profile > res.back()) {res.push_back(profile);}
            else {res.push_back(res.back());}
        }
    }
    
    int maxProfit(vector<int> &prices) {
        if(prices.size() == 0) {return 0;}
        vector<int> max1, max2;
        MaxProfitFromHead(prices, max1);
        MaxProfitFromTail(prices, max2);
        int max = 0;
        int n = prices.size();
        for(int i = 0; i < max1.size(); i++)
        {
            int profile = max1[i] + max2[n - i];
            max = max > profile ? max : profile;
        }
        return max;
        
    }
};
