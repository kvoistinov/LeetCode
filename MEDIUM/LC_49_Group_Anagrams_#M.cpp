/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
*/

class Solution {
public:
    std::vector<std::vector<string>> groupAnagrams(const std::vector<std::string>& strs) 
    {
        std::unordered_map<std::string, std::vector<std::string>> map;
        int counter[26] = { 0 };

        for (auto& s : strs) {
            std::memset(counter, 0, sizeof(int) * 26);

            for (auto ch : s) {
                counter[ch - 'a']++;
            }
            std::string sorted_str;
            sorted_str.resize(s.size());

            int s_pos = 0;

            for (int i = 0; i < 26; ++i) {
                if (counter[i] > 0) {
                    sorted_str[s_pos++] = i + 'a';
                }
            }  
            map[sorted_str].push_back( s );
        }
        std::vector<std::vector<std::string>> anagrams;

        for (auto& p : map)
        {
            anagrams.push_back(p.second);
        }

        return anagrams;
    }
};
