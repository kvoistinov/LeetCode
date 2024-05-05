// 08.04.2024
class Solution {
public:
    int countStudents(const std::vector<int>& students, const std::vector<int>& sandwiches)
    {
        std::queue<int> q;
        
        for (int s : students) {
            q.push(s);
        }
        bool   loop   = false;
        int    num_st = 0;
        size_t curr_sandwich = 0;

        while (!q.empty() && !loop) 
        {
            if (q.front() == sandwiches[curr_sandwich]) {
                curr_sandwich++;
                q.pop();
                num_st = 0;
            }
            else {
                int curr = q.front();
                q.pop();
                q.push(curr);
                num_st++;

                if (num_st == q.size()) {
                    loop = true;
                }
            }
        } 
        return q.size();   
    }
};
