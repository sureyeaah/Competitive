class Solution {
public:
    deque<int> d;
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        for(int i = 0; i < nums.size(); i++) {
            while(!d.empty() && nums[d.back()] <= nums[i]) d.pop_back();
            d.push_back(i);
            if(i >= k-1) {
                if(d.front() == i-k) d.pop_front();
                ret.push_back(nums[d.front()]);
            }
            
        }
        return ret;
    }
};