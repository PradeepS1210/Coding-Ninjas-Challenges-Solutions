/******************************************************************************
Problem statement
There are 'N' days. You are given an array 'A' of length 'N', representing the scores of the 'N' days.

You are working on each of these days, and your mood can be either good or bad. A "mood assignment" is the collection of your mood on all 'N' days.

If your mood is good on a given day, its score is added to the total score. On the other hand, if your mood is bad on a given day, its score is subtracted from the total score. If your total score ever reaches a negative number, you just forget about the negative sign and replace it with its absolute value.

Your boss will be satisfied if the final score has a non-zero bitwise AND with 'K'. Count the number of unique mood assignments that satisfy your boss. Return the answer modulo 10^9 + 7.

For Example :
Let 'N' = 2, 'A' = [ 5, 3 ], 'K' = 3.
There are 4 possible mood assignments.
1. [ Good, Good ] resulting in a score of '8'.
2. [ Good, Bad ] resulting in a score of '2'.
3. [ Bad, Good ] resulting in a score of '8'.
4. [ Bad, Bad ] resulting in a score of '2'.
Exactly 2 Assignments, '2' and '4', satisfy your boss.
Thus, the answer is '2'.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= 'T' <= 10
1 <= 'N' <= 100
1 <= 'A[i], K' <= 10^4

Time Limit: 1 sec
Sample Input 1 :
2
3 4
4 9 2
3 1
1 2 3
Sample Output 1 :
4
0
Explanation of sample input 1 :
First test case:-
The following mood assignments satisfy the boss:
1. [ Good, Good, Good ] resulting in a score of '15'.
2. [ Bad, Good, Good ] resulting in a score of '15'.
3. [ Bad, Bad, Good ] resulting in a score of '7'.
4. [ Good, Bad, Good ] resulting in a score of '7'.
It can be shown that all other mood assignments do not satisfy your boss.
Thus, the answer is '4'.

Second test case:-
It can be shown that no mood assignment can satisfy your boss.
Thus, the answer is '0'.
Sample Input 2 :
2
5 9
11 3 7 9 6
5 6
100 16 13 1 4
Sample Output 2 :
12
32
******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int countValidAssignments(int day, long long score, const vector<int> &A, int K, vector<vector<long long>> &memo) {
    if (day == A.size()) {
        return (score & K) ? 1 : 0;
    }

    if (memo[day][score] != -1) {
        return memo[day][score];
    }

    long long goodMoodScore = score + A[day];
    long long badMoodScore = abs(score - A[day]);

    int count = 0;
    count = (count + countValidAssignments(day + 1, goodMoodScore, A, K, memo)) % MOD;
    count = (count + countValidAssignments(day + 1, badMoodScore, A, K, memo)) % MOD;

    memo[day][score] = count;
    return count;
}

int dichotomy(int N, vector<int> &A, int K) {
    vector<vector<long long>> memo(N + 1, vector<long long>(20000, -1));
    return countValidAssignments(0, 0, A, K, memo);
}
