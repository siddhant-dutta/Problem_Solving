/*
https://leetcode.com/problems/online-stock-span/submissions/
*/

class StockSpanner {
public:
    // vector<int> span(10000), ;
    stack<pair<int,int>> s; 
    StockSpanner() {
        
    }
    
    int next(int price) {
        int res = 1;
        while(!s.empty() && price>=s.top().first){
            res += s.top().second;
            s.pop();
        }
        s.push({price, res});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
