// Companies asking this question: Goldman Sachs, HCL Technologies, TCS, Amazon, TAta Communications, Accenture, Wipro, Capegemini, Jio

/*****************************************************************************************
Problem statement
Given an array of non-negative integers ‘A’ and an integer ‘P’, find the total number of subsequences of ‘A’ such that the product of any subsequence should not be more than ‘P’.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.
Note
You need to print your answer modulo 10^9 + 7.
For Example
Let us take  A = [1,2,3] and P = 4. 
All the subsequences not having product more than ‘4’ are {1}, {2}, {3}, {1,2}, {1,3}. Therefore count is equal to ‘5’.
Detailed explanation ( Input/output format, Notes, Images )
Constraints
1 <= T <= 10
1 <= N <= 10^3
1 <= A[i] <= 10^3
1 <= P <= 10^3

Where A[i] is array element at index ‘i’,  ‘P’ is product value.
The Sum of 'N' over all test cases is <= 10 ^ 3.

Time Limit: 1 sec
Sample Input 1:
2
3 8
2 3 5  
4 10
15 20 30 25 
Sample Output 1:
4
0
Explanation For Sample Input 1:
Test Case 1: The given array is [2,3,5]. 
All the possible subsequences of this array are {2}, {3}, {5}, {2,3}, {2,5}, {3,5}, {2,3,5}. But product of elements of subsequence {2,5}, {3,5}, {2,3,5} is more than p i.e 8. Therefore required count is 4.

Test Case 2: The given array is [15, 20. 30, 25] and p=10. 
As all the subsequences have product more than10’. So answer equals 0.    
Sample Input 2
2
5 6
2 7 3 6 1
6 24
1 5 4 9 8 16
Sample Output 2
9
13
Explanation For Sample Input 2:
Test Case 1: The given array is [2, 7, 3, 6, 1]. 
The total number of subsequences having product less than 6 are 9.

Test Case 2: The given array is [1, 5, 4, 9, 8, 16] 
The total number of subsequences having product less than 24 are 13.
*****************************************************************************************/

#include <bits/stdc++.h> 
using namespace std;

const int MOD_VALUE = 1e9 + 7;

void countSubsequencesUtil(int idx, long long product, vector<int> &a, int n, int p, int &count) {
    if (idx == n) {
        if (product <= p) {
            count = (count + 1) % MOD_VALUE;
        }
        return;
    }

    if (product * a[idx] <= p) {
        countSubsequencesUtil(idx + 1, product * a[idx], a, n, p, count);
    }

    countSubsequencesUtil(idx + 1, product, a, n, p, count);
}

int countSubsequences(vector<int> &a, int n, int p) {
    int count = 0;
    countSubsequencesUtil(0, 1, a, n, p, count);
    
    count = (count - 1 + MOD_VALUE) % MOD_VALUE; 
    
    return count;
}
