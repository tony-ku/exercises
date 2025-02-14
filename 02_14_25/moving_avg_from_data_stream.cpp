/*
Moving Average from Data Stream

Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

Implement the MovingAverage class:

MovingAverage(int size) Initializes the object with the size of the window size.
double next(int val) Returns the moving average of the last size values of the stream.
 

Input
["MovingAverage", "next", "next", "next", "next"]
[[3], [1], [10], [3], [5]]
Output
[null, 1.0, 5.5, 4.66667, 6.0]

Explanation
MovingAverage movingAverage = new MovingAverage(3);
movingAverage.next(1); // return 1.0 = 1 / 1
movingAverage.next(10); // return 5.5 = (1 + 10) / 2
movingAverage.next(3); // return 4.66667 = (1 + 10 + 3) / 3
movingAverage.next(5); // return 6.0 = (10 + 3 + 5) / 3

Constraints:

1 <= size <= 1000
-105 <= val <= 105
At most 104 calls will be made to next.
*/

class MovingAverage {
    private:
        vector<int> q;
        int q_size = 0;
    public:
        MovingAverage(int size) {
            q_size = size;
        }
        
        double next(int val) {
            int count = 0;
            double ans = 0;
            q.push_back(val);
            
            if (q.size() > q_size)
                q.erase(q.begin());
    
            for (int i = 0; i < q.size(); i++)
            {
                ans += (double)q.at(i);
            }
    
            return ans / q.size();
        }
    };
    
/**
 * Your MovingAverage object will be instantiated and called as such:
 * * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */