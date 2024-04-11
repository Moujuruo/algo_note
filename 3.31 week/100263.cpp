class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int k = x;
        int tot = 0;
        while (x > 0) {
            tot += x % 10;
            x /= 10;
        }

        if (k % tot == 0)
            return tot;
        else
            return -1;
        
    }
};