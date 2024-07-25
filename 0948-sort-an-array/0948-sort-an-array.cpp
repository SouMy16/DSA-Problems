class Solution {
public:
    void merge(vector<int>& nums, int s1, int s2, int e)
    {
        int i = 0, j = 0;
        int n1 = s2-s1;
        int n2 = e-s2+1;
        vector<int> left, right;
        for(int x=s1; x<s2; x++) left.push_back(nums[x]);
        for(int x=s2; x<=e; x++) right.push_back(nums[x]);
        int x = s1;
        while(i<n1 && j<n2)
        {
            if(left[i]<=right[j])
            {
                nums[x] = left[i];
                i++, x++;
            }
            else if(right[j]<left[i])
            {
                nums[x] = right[j];
                j++, x++;
            }
        }
        while(i<n1)
        {
            nums[x] = left[i];
            i++, x++;
        }
        while(j<n2)
        {
            nums[x] = right[j];
            j++, x++;
        }
        return;
    }
    
    void mergeSort(vector<int> &nums, int s, int e)
    {
        if(e==s || e<s) return;
        int mid = s+(e-s)/2;
        mergeSort(nums, s, mid);
        mergeSort(nums,mid+1,e);
        merge(nums, s, mid+1, e);
        return;
    }
    
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};