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
