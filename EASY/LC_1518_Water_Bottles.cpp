class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
        int maxBottles   = numBottles;
        int emptyBottles = 0;

        while (numBottles)
        {
            int bottles  = (numBottles + emptyBottles) / numExchange;
            emptyBottles = (numBottles + emptyBottles) % numExchange;
            maxBottles  += bottles;
            numBottles   = bottles;
        }
        return maxBottles;
    }
};
