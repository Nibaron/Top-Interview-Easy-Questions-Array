# Top-Interview-Questions-Array-easy

**Task #1**
## Remove Duplicates from Sorted Array
> Sample Input Output
```
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
```
> Approach

We will use a variable called `len`. First, element will always unique, so the loop will start with 1.
The array is already sorted, so repeated value comes in neighbourhood.
If the `nums[i]` not equal to `nums[n-1]` its unique. so replace `nums[len]` with `nums[i]`.
```
Example:
1-2(i & len)-2-2-3-4-4
1st iteration
2 != 1 so, 2(len) will be upadted with 2(i).

1-2-2(i & len)-2-3-4-4
2nd iteration
2==2 so, i will be incremented, not len.

1-2-2(len)-2(i)-3-4-4
3rd iteration
2==2 so, i will be incremented, not len.

1-2-2(len)-2-3(i)-4-4
4th iteration
3!=2, so 2 (len) will be upadted with 3 (i).

it will continue like this.

```
> The Code
```
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
     if(nums.size()==0) //for null vector
         return 0;
		 
    int len=1;
    for(int i=1; i<nums.size(); i++)
    {
        if(nums[i]!=nums[i-1])
        {
            nums[len]=nums[i]; //nums[len] will store the unique numbers only
            len++;
        }
    }
        return len;
    }
};
```
**Task #2**
## Best Time to Buy and Sell Stock II

> Sample Input Output
```
Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
```
**To calculate profit we need to consider each `Local Minima` and Next `Local Maxima`.**
 

![image](https://assets.leetcode.com/users/images/1331ada2-8d61-4da7-a44d-5544fcdfbcb7_1662411077.8817523.jpeg)

# profit = (7-2) + (6-3) + (4-1) =11
**See the last profit criteria,**
here we have avoided value 2, because our maxima is 4.
so, ( 4-1) = 3 
but,
**2-1 = 1   &     4-2 = 2
and 1+2 = 3**

That gives the same result.

so, we can simply calculate the profit, without avoid middle values.
```
if(prices[i]>prices[i-1])
      profit += (prices[i]-prices[i-1]);
```
The code is simple and clean:
```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        
        for( int i=1; i< prices.size(); i++)
        {
            if(prices[i]>prices[i-1])
                profit += (prices[i]-prices[i-1]);
        }
        return profit;
    }
};
```
**Task #3**
## Rotate Array
> Sample Input Output
```
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
```
> Approach

reverse last k numbers first, then 0th to k-1 numbers should be reversed.
then fully reverse the array.

> Example

```
1-2-3-4-5-6-7
k=3
(1-2-3-4)-(5-6-7)
(4-3-2-1)-(7-6-5)
5-6-7-1-2-3-4
```


> My Code
```
class Solution {
public:
    void reverse(vector<int>& num, int low, int high)
    {
        while(low<high)
        {
            swap(num[low],num[high]);
            low++;
            high--;
        }   
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        reverse(nums,0,n-k-1);
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-1);
        
    }
};
```
**Task #4**
## Contains Duplicate
> Sample Input Output
```
Input: nums = [1,2,3,1]
Output: true
Input: nums = [1,2,3,4]
Output: false
```
> Approach
copy the vector into map, map means no repect.
so,both vector and map same size means no duplicate.


> My Code
```
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int s=nums.size();
        map <int,int> m;
        for(int i=0; i<s;i++)
        {
            m[nums[i]]++;
        }
        if(m.size()==s)
            return false;
        else
            return true;
    }
};
```
**Task #5**
## Single Number

Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

> Sample Input Output
```
Input: nums = [4,1,2,1,2]
Output: 4
```

> My Code
```
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        
        sort(nums.begin(),nums.end());
        int i=0;
        while(i<nums.size())
        {
            if(nums[i]==nums[i+1])
                i+=2;
            else
                break;
        }
        return nums[i];
    }
};
```
**Task #6**
## Intersection of Two Arrays II
Given two integer arrays `nums1` and `nums2`, return an array of their intersection. 
Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

> Sample Input Output
```
Input: nums1 = [4,9,5,5], nums2 = [5,4,9,8,4]
Output: [4,9,5]
Explanation: [9,4] is also accepted.
```
> Approach
search nums 1 in nums2, if found push it to another vector 
and remove the matching number from nums2.


> My Code
```
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
       
         vector<int> r;
        for(int i=0; i< nums1.size(); i++)
        {
            for(int j=0; j< nums2.size(); j++)
            {  
                if(nums1[i]==nums2[j])
                {
                    r.push_back(nums1[i]);
                    nums2.erase(nums2.begin() + j); 
                    break;
                }
            }
            
        }
         return r;      
    }
};
```
**Task #7**
## Plus One
You are given a large integer represented as an integer array digits, where each `digits[i]` is the `ith` digit of the integer. 
The digits are ordered from most significant to least significant in left-to-right order. 
The large integer does not contain any leading 0's.
Increment the large integer by one and return the resulting array of digits.

> Sample Input Output

```
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
```
> Approach
You will face 3 kinds of problems here.
for,
* 1 2 3
* 2 9 9
* 9 9 9

we will check the digits from behind.
 **CASE 1**: if, not 9 in last digit found, then just increment it by one and finish. 
 ---> 1 2 3 --> 1 2 4
**CASE 2**: for 9 in last digits, we will change it to 0, and check for non 9 value, if found increment it by 1 and finish.
---> 2 9 9 ---> 2 0 0 ---> 3 0 0
**CASE 3**: for only 9 in digits, we will make them 0 first, then add one more digits and change 1st digit to 1. 
---> 9 9 9 ---> 0 0 0 ---> 0 0 0 0 ----> 1 0 0 0 

> My Code
```
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
       int size =digits.size();
        
       for(int i=size-1; i>=0; --i)
       {
           if(digits[i]==9)
           {
               digits[i]=0;
           }
           
           else
           {
               digits[i]++;
               return digits;
           }
        
       }
       digits.push_back(0);
        digits[0]=1;
        return digits;
    }
    
};
```
