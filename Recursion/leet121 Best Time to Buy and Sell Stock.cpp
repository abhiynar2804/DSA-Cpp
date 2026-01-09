//121. Best Time to Buy and Sell Stock

//recursive approach
class Solution {
public:
    void maxProfitHelper(vector<int>& prices, int i, int& minPrice, int& maxProfit) {
        if (i == prices.size()) return;   

        minPrice = min(minPrice, prices[i]);
        maxProfit = max(maxProfit, prices[i] - minPrice);

        maxProfitHelper(prices, i + 1, minPrice, maxProfit);
    }

    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;     

        int minPrice = INT_MAX;
        int maxProfit = 0;                

        maxProfitHelper(prices, 0, minPrice, maxProfit);
        return maxProfit;
    }
};


//optimal approach
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int help = prices[0];   
        int ans = 0;            

        for (int i = 1; i < n; i++) {
            if (prices[i] < help) {
                help = prices[i];           
            } else {
                ans = max(ans, prices[i] - help); 
            }
        }
        return ans;
    }
};

//iterative approach
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int least = prices[0];
        int profit = 0;
        for(int i=0; i<prices.size();i++){
                profit = max(-least + prices[i], profit);
                if(least>prices[i]){
                    least = prices[i];
                }
        }
        return profit;
    }
};
