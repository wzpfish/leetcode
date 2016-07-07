/*
 * 按第一小问的思路写的
 */
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;  
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        for (; i < nums1.size(); ++i) {
            for (; j < nums2.size(); ++j) {
                if (nums1[i] == nums2[j]) {
                    result.push_back(nums1[i]);
                    ++j;
                    break;
                }
                else if (nums1[i] < nums2[j]) break;
            }
        }
        return result;
    }
};
