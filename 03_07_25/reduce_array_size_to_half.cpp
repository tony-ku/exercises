/*
Reduce Array Size to The Half

You are given an integer array arr. You can choose a set of integers and remove all the occurrences of these integers in the array.

Return the minimum size of the set so that at least half of the integers of the array are removed.

 

Example 1:

Input: arr = [3,3,3,3,5,5,5,2,2,7]
Output: 2
Explanation: Choosing {3,7} will make the new array [5,5,5,2,2] which has size 5 (i.e equal to half of the size of the old array).
Possible sets of size 2 are {3,5},{3,2},{5,2}.
Choosing set {2,7} is not possible as it will make the new array [3,3,3,3,5,5,5] which has a size greater than half of the size of the old array.
Example 2:

Input: arr = [7,7,7,7,7,7]
Output: 1
Explanation: The only possible set you can choose is {7}. This will make the new array empty.
 

Constraints:

2 <= arr.length <= 105
arr.length is even.
1 <= arr[i] <= 105
*/
class Solution {
    public:
        int minSetSize(vector<int>& arr) {
            unordered_map<int, int> freq;
            
            priority_queue<int> q;
            for (auto x: arr)
            {
                freq[x]++;
            }
            
            /* Just store the size, will be sorted by the max first */
            for (auto it = freq.begin(); it != freq.end(); ++it)
            {
                q.push(it->second);     
            }
        
            int val = 0;
            int count = 0;
            while (!q.empty())
            {
                int temp = q.top();
                q.pop();
                count++;
                val += temp;
    
                if (val >= arr.size() / 2)
                    break;
            }
            return count;
        }
    };