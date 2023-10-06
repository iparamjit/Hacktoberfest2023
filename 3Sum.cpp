#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++) {
        if (i != 0 and nums[i] == nums[i - 1]) {
            continue;
        }
        int target = -1 * nums[i];
        int s = i + 1, e = n - 1;
        while (s < e) {
            int value = nums[s] + nums[e];
            if (value == target) {
                result.push_back({nums[i], nums[s], nums[e]});
                while (s < e and nums[s] == nums[s + 1]) {
                    s = s + 1;
                }
                while (s < e and nums[e] == nums[e - 1]) {
                    e = e - 1;
                }
                s = s + 1;
                e = e - 1;
            } else if (value > target) {
                while (s < e and nums[e] == nums[e - 1]) {
                    e = e - 1;
                }
                e = e - 1;
            } else {
                while (s < e and nums[s] == nums[s + 1]) {
                    s = s + 1;
                }
                s = s + 1;
            }
        }
    }
    return result;
}
