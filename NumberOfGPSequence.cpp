// Companies asking this question: HSBC, Paytm, SAP Labs 

/****************************************************************
Problem statement
You are given an array containing ‘N’ integers. You need to find the number of subsequences of length 3 which are in Geometric progression with common ratio ‘R’.

A geometric progression (GP), also called a geometric sequence, is a sequence of numbers that differ from each other by a common ratio. For example, the sequence 2,4,8,16,… is a geometric sequence with common ratio 2.

Note:
As the answer can be very large you need to return the answer in mod 10^9+7.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 50
3 <= N <= 10^4  
1 <= R <= 10^4  
1 <= A[i] <= 10^9

Time Limit: 1 sec
Sample Input 1:
2
4 2
3 4 6 12
5 3
2 6 6 18 20
Sample Output 1:
1
2
Explanation for sample input 1:
Test case 1:
The indexes (1 based indexing) of possible subsequence [1,3,4].
The sequence ->  3, 6 (3*2 = 6), 12 ( 3*2*2 = 12) is having first term 3 and common ratio 2.

Test case 2:
The indexes (1 based indexing) of possible subsequence [1,2,4], [1,3,4].
The first sequence ->  2, 6 (2*3 = 6), 18 ( 2*3*3 = 18) is having first term 2 and common ratio 3.
The second sequence is also the same as the first but they only differ in indexes of the middle element.
Sample Input 2:
2
5 5
0 10 1 2 2
6 2
2 4 8 11 22 44
Sample Output 2:
0
2
*****************************************************************/

#include <vector>
#include <unordered_map>
using namespace std;

#define MOD 1000000007

int countGpSubsequence(vector<int> &a, int r, int n) {
    unordered_map<int, long long> count;
    unordered_map<int, long long> pairCount;

    long long answer = 0;

    for (int i = 0; i < n; ++i) {
        int current = a[i];

        if (current % r == 0) {
            int first = current / r;
            if (pairCount.find(first) != pairCount.end()) {
                answer = (answer + pairCount[first]) % MOD;
            }
        }

        if (current % r == 0) {
            int first = current / r;
            if (count.find(first) != count.end()) {
                pairCount[current] = (pairCount[current] + count[first]) % MOD;
            }
        }

        count[current]++;
    }

    return answer;
}
