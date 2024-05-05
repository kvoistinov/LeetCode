// 10.04.2024
class Solution {
public:
    int timeRequiredToBuy(std::vector<int>& tickets, int k) 
    {
        std::queue<int> q;
        int time = 0;

        for (int i = 0; i < tickets.size(); ++i)
        {
            q.push(i);
        }

        while (!q.empty())
        {
            time++;
            int curr = q.front();
            q.pop();

            if (--tickets[curr] > 0) {
                q.push(curr);
            }
            if (curr == k && tickets[k] == 0) {
                break;
            }
        }
        return time;
    }
};
