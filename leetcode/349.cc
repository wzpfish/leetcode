/*
 * 水题..练习标准库用的吗..
 */
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        auto end1 = unique(nums1.begin(), nums1.end());
        auto end2 = unique(nums2.begin(), nums2.end());
        vector<int> result;
        for (auto it = nums1.begin(); it != end1; ++it) {
            for (auto it2 = nums2.begin(); it2 != end2; ++it2) {
                if (*it == *it2) {
                    result.push_back(*it);
                    break;
                } 
            }
        }
        return result;
    }
};
