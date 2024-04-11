class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        int empty = 0;
        while (1) {
            empty += numBottles;
            numBottles = 0;
            while (empty >= numExchange) {
                empty -= numExchange;
                numExchange ++;
                ans ++;
                numBottles ++;
            }
            if (numBottles == 0)
                break;
        }
        return ans;
    }
};