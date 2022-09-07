class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> v;
          unordered_map <int,int> m;
        
        for(int i=0;; ++i)
        {
          int ser=target-nums[i];
            
          if(m.find(ser)!=m.end())
          {
              v.push_back(m[ser]);
              v.push_back(i);
              return v;
          }
            else
                m[nums[i]]=i;
        }
        return v;
    }
};