#Geek and his friend are playing a car racing game. Given an input array, Geek and his friend can start at any index in and can move their car either one index left or one right if it exists. Also, geek and his friend can't move their car to any index such that the value of A on that index is smaller than the value at the current index.

Your task is to find the maximum possible distance between geek and his friend's cars.

Notethat geek and his friend's car will start at the same index and Given Array are 0th based indexed.

Example 1:

Input: 
N = 5
A[] = {1,2,3,4,5}
Output: 4
Explanation: 
Geek and his friend will start at 1st index.
While geek move his car to 5th index , his 
friend will keep his car at 1st.


Example 2:

Input: 
N = 3
arr[] = {4,3,3}
Output: 2
Explanation: 
Geek and his friend start at 2nd index. 
Geek move his car to 3rd index , and his 
friend move his car to 1st index.

Your task:

You don't have to read input or print anything. Your task is to complete the function MaxDistance() which takes the array and it's size N as input and returns maximum possible distance between geek and his car.



Expected Time Complexity: O(N)

Expected Auxiliary Space:O(1)

Constraints:

1 ≤ N, A[i]≤ 1000000
