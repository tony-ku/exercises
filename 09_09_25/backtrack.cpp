#include <bits/stdc++.h>
using namespace std;

void dfsSubsets(const vector<int>& nums, int i, vector<int>& path, vector<vector<int>>& result) {
    if (i == (int)nums.size()) {
        result.push_back(path);
        return;
    }
    // Exclude nums[i]
    dfsSubsets(nums, i + 1, path, result);
    // Include nums[i]
    path.push_back(nums[i]);
    dfsSubsets(nums, i + 1, path, result);
    path.pop_back();
}

vector<vector<int>> subsets(vector<int> nums) {
    vector<vector<int>> result;
    vector<int> path;
    dfsSubsets(nums, 0, path, result);
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    auto res = subsets(nums);
    cout << "Subsets (" << res.size() << "):\n";
    for (auto& v : res) {
        cout << "{ ";
        for (int x : v) cout << x << " ";
        cout << "}\n";
    }
    return 0;
}
