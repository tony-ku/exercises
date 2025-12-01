#include <bits/stdc++.h>
using namespace std;

void dfsPerm(const vector<int>& nums, vector<int>& path, vector<char>& used, vector<vector<int>>& result) {
    if (path.size() == nums.size()) {
        result.push_back(path);
        return;
    }
    for (size_t i = 0; i < nums.size(); ++i) {
        if (used[i])
            continue;
        // path is used
        used[i] = 1;
        path.push_back(nums[i]);
        dfsPerm(nums, path, used, result);
        path.pop_back();
        // mark path is unused
        used[i] = 0;
    }
}

vector<vector<int>> permutations(vector<int> nums) {
    vector<vector<int>> result;
    vector<int> path;
    vector<char> used(nums.size(), 0);
    dfsPerm(nums, path, used, result);
    return result;
}

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // empty ans
        vector<vector<int>> ans;
        // empty curr
        vector<int> curr = {};
        backtrack(curr, ans, nums);
        return ans;
    }

    void backtrack(vector<int>& curr, vector<vector<int>>& ans, vector<int>& nums) {
        // if we get the same size as nums, then time to go the next round.
        if (curr.size() == nums.size()) {
            printf ("   curr size is the same\n");
            printf ("  save answer: ");

            for (auto& v : curr) {
                cout << v << " ";;
            }
            cout << "\n";
            ans.push_back(curr);
            return;
        }

        // walk through each element of nums
        // initially it would be 1, 2, 3
        //   first time - 1,2,3, then 1, skip 2, 3, skip 3, 2 or 1 3 2.
        //   second loop num = 2, so look for 1, 3 (2 skipped), ans 2 1 3, etc.
        for (int num: nums) {
            printf ("for loop begin\n");
            // if it can't find the number
            if (find(curr.begin(), curr.end(), num) == curr.end()) {
                printf ("not found entry: %d\n", num);
                printf (" save to curr: %d\n", num);
                curr.push_back(num);
                printf ("run backtrack\n");
                backtrack(curr, ans, nums);
                printf ("remove last entry\n");
                curr.pop_back();
            }
        }
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    auto res = permutations(nums);
    cout << "First Solution\n";
    cout << "Permutations (" << res.size() << "):\n";
    for (auto& v : res) {
        cout << "[ ";
        for (int x : v) cout << x << " ";
        cout << "]\n";
    }

    Solution sol;
    res = sol.permute(nums);
    cout << "Second Solution\n";
    cout << "Permutations (" << res.size() << "):\n";
    for (auto& v : res) {
        cout << "[ ";
        for (int x : v) cout << x << " ";
        cout << "]\n";
    }
    return 0;
}
