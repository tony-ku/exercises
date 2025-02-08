#include <unordered_map>
#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;


class Solution {
    public:
        int findMaxLength(vector<int>& nums) {
            unordered_map<int, int> map{};
            map[0] = -1;
            int count = 0;
            int max_len = 0;

            for (int i = 0; i < (int)nums.size(); i++)
            {
                count = count + ((nums[i] == 1) ? 1 : -1);
                printf ("count: %d\n", count);
                if (map.find(count) != map.end())
                {
                    int check_max = i - map[count];
                    printf ("check_max: %d\n", check_max);
                    if (check_max > max_len)
                        max_len = check_max;
                }
                else
                    map[count] = i;
            }
            return max_len;
        }
    };


int main(void)
{
    Solution x;
    int max_len;
    vector<int> nums = {0, 1, 0};
    max_len = x.findMaxLength(nums);
    printf ("max_len:%d\n", max_len);
    return 0;
}