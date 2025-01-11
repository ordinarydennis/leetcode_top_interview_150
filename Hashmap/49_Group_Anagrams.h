class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> m;

        for (int i = 0; i < strs.size(); i++)
        {
            string str = strs[i];
            sort(str.begin(), str.end());
            m[str].emplace_back(std::move(strs[i]));
        }

        vector<vector<string>> ret;

        for (auto& [str, v] : m)
        {
            ret.emplace_back(std::move(v));
        }

        return ret;
    }
};