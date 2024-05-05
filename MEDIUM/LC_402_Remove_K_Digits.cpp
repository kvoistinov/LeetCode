// WRANG ANSWER:
class Solution {
public:
    std::string removeKdigits(std::string num, int k) 
    {
        if (num.size() == k) {
            return "0";
        }
        size_t s_curr = 0; // current position in the string
        size_t size   = num.size();
        //int iter = 1;

        while (s_curr < size && k)
        {
            //std::cout << iter << ":\n";

            if (num[s_curr] == '0') {
                //std::cout << "prepare to remove before 0:\n";

                // remove possible digits
                size_t digits_count = s_curr;

                if (digits_count > k) {
                    // find max digits
                    while (k--)
                    {
                        size_t max_digit_pos = 0;
                        size_t search_pos    = 0;

                        while (search_pos < s_curr)
                        {
                            if (num[max_digit_pos] < num[search_pos]) {
                                max_digit_pos = search_pos;
                            }
                            search_pos++;
                        }
                        num.erase(max_digit_pos, 1);
                        s_curr--;
                    }
                    num.erase(0, 1);
                    s_curr = 0;
                }
                else {
                    int need_remove = digits_count + 1;

                    if ((size - need_remove) > 0) {
                        num.erase(0, need_remove);
                    }
                    else {
                        num = "0";
                        return num;
                    }
                    k -= digits_count;
                    s_curr  = 0;
                }
            }
            else {

                size_t max_digit_pos = 0;
                size_t search_pos    = 1;
                bool   increase      = true;

                while (search_pos < size && num[search_pos] != '0')
                {                     
                    if (increase && num[search_pos - 1] > num[search_pos] && search_pos != size - 1) {
                        increase = false;
                    }
                    //std::cout << "Not 0: " << search_pos << " " << num[search_pos] << '\n';

                    if (num[max_digit_pos] < num[search_pos]) 
                    {
                        if (search_pos != size - 1) {
                            max_digit_pos = search_pos;
                        }
                        else if (k == 1) {
                            if (increase) {
                                max_digit_pos = size - 1;
                            }

                        }
                    }
                    else if (!increase) {
                        break;
                    }
                    search_pos++;
                }
                if (num[search_pos] != '0' || search_pos != size - 1 )
                {
                    num.erase(max_digit_pos, 1);

                    if (num[0] == '0') {
                        num.erase(0, 1);
                    }
                    k--;
                    s_curr++;
                }
                else {
                    s_curr = search_pos;
                }
                
            }
            size = num.size();

            // std::cout << num << " (" << size << ")\n";
            // iter++;
        }
        while (num[0] == '0') {
            num.erase(0, 1);
        }
        
        return num.empty() ? "0" : num;
    }
};

// Solution 1:

