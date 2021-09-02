class Solution {
public:
    std::vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, std::pair<int, int>> umap;
        vector<int> result;
        int order = 0;
        for (auto num : nums)
        {
            umap.insert(std::pair<int, std::pair<int, int>>(order, std::pair<int, int>(num, target - num)));
            order++;
        }
        for (auto num : umap)
        {
            auto found = std::find_if(std::begin(umap), std::end(umap), [num](auto p) {return (p.second.second == num.second.first) && (p.first != num.first); });
            if (found != std::end(umap))
            {
                result.push_back(found->first);
                result.push_back(num.first);
                break;
            }
        }
        return result;
    }
};