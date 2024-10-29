// Companies asking this question: Uber, Facebook, HSBC, PayPal, Airtel, VMware

/*********************************************************************************
Problem statement
You are given a set of ‘N’ rectangular envelopes. The height and width of each envelope are given by arrays, ‘height’ and ‘width’ respectively, each consisting of ‘N’ positive integers. The height, width of the ith envelope is given by ‘height[i]’ and ‘width[i]’ respectively.

You can put one envelope inside another envelope if and only if both the height and width of one envelope is strictly greater than the height and width of the other envelope.

What is the maximum number of envelopes you can Russian doll? (put one inside other)

Note
Rotation of envelope is not allowed, that is, height and width can’t be exchanged
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 50
1 <= n <= 10^4
1 <= height[i] <= 10^9
1 <= width[i] <= 10^9

Time Limit: 2 sec
Sample Input 1:
2
4
5 6 6 2
4 4 7 3
2
2 1 
2 1
Sample Output 1:
3 
2
Explanation For Sample Output 1:
Test Case 1:
The number envelopes, ‘N’ = 4 
‘height’ = {5, 6, 6, 2}
‘width’= {4, 4, 7, 3}
Let denote dimensions of the envelope in (Height, Width) manner then, one way of Russian Doll envelopes in outermost to the innermost manner is as follow:

Select the third envelope, i.e., envelope with dimensions (6, 7) as the outermost envelope.

Place the first envelope i.e envelope with dimensions (5, 4) inside the outermost envelope. You can do this because both the height and width of this envelope is strictly less than the outermost envelope.

Place the fourth envelope i.e envelope with dimensions (2, 3) inside the previous envelope.

In this way, we can Russian Doll 3 envelopes. 

No other way can Russian Doll more than 3 envelopes.

Test Case 2:
You can put the second envelope inside the first envelope because both the height and width of the second envelope are strictly less than the first envelope.
Sample Input 2:
 2
 1
 2
 3
 3
 1 1 1
 1 1 1
Sample Output 2:
 1
 1
*********************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int findMaxEnvelopes(vector<int> &height, vector<int> &width, int n) {
    vector<pair<int, int>> envelopes(n);
    for (int i = 0; i < n; i++) {
        envelopes[i] = {height[i], width[i]};
    }

    sort(envelopes.begin(), envelopes.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    });

    vector<int> widths(n);
    for (int i = 0; i < n; i++) {
        widths[i] = envelopes[i].second;
    }

    vector<int> lis;
    for (int w : widths) {
        auto it = lower_bound(lis.begin(), lis.end(), w);
        if (it == lis.end()) {
            lis.push_back(w);
        } else {
            *it = w;
        }
    }

    return lis.size();
}
