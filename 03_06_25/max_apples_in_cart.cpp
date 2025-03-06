/*
How Many Apples Can You Put into the Basket

You have some apples and a basket that can carry up to 5000 units of weight.

Given an integer array weight where weight[i] is the weight of the ith apple, return the maximum number of apples you can put in the basket.

 

Example 1:

Input: weight = [100,200,150,1000]
Output: 4
Explanation: All 4 apples can be carried by the basket since their sum of weights is 1450.
Example 2:

Input: weight = [900,950,800,1000,700,800]
Output: 5
Explanation: The sum of weights of the 6 apples exceeds 5000 so we choose any 5 of them.
 

Constraints:

1 <= weight.length <= 103
1 <= weight[i] <= 103


*/

/* lots of way to do this, can sort, then use highest value and count, or use priority queue as minimum queue.
   to fit max apples you'll need to accumulate lowest weights first.

   This implementation uses a priority queue with min as the value (hence negative for the values)
*/
class Solution {
    public:
        int maxNumberOfApples(vector<int>& weight) {
            priority_queue<int> queue;
            for (auto w: weight)
                queue.push(-w);
            int count = 0;
            int total_weight = 0;
            while (!queue.empty())
            {
                int top = -queue.top();
                queue.pop();
                total_weight += top;
                if (total_weight > 5000)
                    break;
                count++;
            }
            return count;
        }
    };