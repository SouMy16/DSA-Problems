class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        long long int n = nums.size();
        priority_queue<long long int> pq1;
        priority_queue<long long int, vector<long long int>, greater<long long int>> pq2;
        for(int i=0; i<n; i++)
        {
            pq1.push(nums[i]);
            pq2.push(nums[i]);
        }
        long long int mx = pq1.top(), mn = pq2.top();
        long long int ans = mx-mn;
        cout<<mx<<" "<<mn<<" "<<n<<'\n';
        if(mn%2 == 0)
        {
            if(mx%2 == 1) ans = min(ans, mx-mn);
            else{
                while(!pq1.empty() && pq1.top()%2==0)
                {
                    long long int x = pq1.top();
                    pq1.pop();
                    pq1.push(x/2);
                    pq2.push(x/2);
                    ans = min(ans, abs(pq1.top()-pq2.top()));
                }
            }
        }
        else if(mx%2 == 1)
        {
            while(!pq2.empty() && pq2.top()%2==1)
            {
                long long int x = pq2.top();
                pq2.pop();
                pq2.push(x*2);
                pq1.push(x*2);
                ans = min(ans, abs(pq1.top()-pq2.top()));
            }
        }
        else{
            // mn is odd and mx is even
            while(pq2.top()%2==1)
            {
                long long int x = pq2.top();
                x *= 2;
                pq2.pop();
                pq2.push(x);
                pq1.push(x);
                ans = min(ans, abs(pq1.top()-pq2.top()));
            }
            while(pq1.top()%2==0)
            {
                long long int x = pq1.top();
                x /= 2;
                pq1.pop();
                pq1.push(x);
                pq2.push(x);
                ans = min(ans, abs(pq1.top()-pq2.top()));
            }
        }
        return ans;
    }
};