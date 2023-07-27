class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = accumulate(begin(batteries), end(batteries), 0LL);
        priority_queue<int> pq(begin(batteries), end(batteries));
        while (pq.top() > sum / n) {
            sum -= pq.top(); 
            pq.pop();
            --n;
        }
        return sum / n;
    }
};