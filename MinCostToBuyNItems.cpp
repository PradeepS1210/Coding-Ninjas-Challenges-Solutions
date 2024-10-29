// Companies asking this question: OYO, Flipkart, Squadstack, BYJUS

/*****************************************************************************
Problem statement
Ninja Yuki is in the mood of shopping ninja blades today, and why should he not be, its finally the time for the Spring Fair in his Village. Initially, he has 0 number of blades and aims to buy ‘N’ of them from the fair. But the blade shopkeeper being a cunning man himself, presents a weird way of pricing the number of ninja blades Yuki can buy.

Suppose at any instance Yuki has ‘K’ number of blades, then:

1) Yuki can buy 1 more blade with cost 'A.’ He now has ‘K+1’ Ninja blades.
2) Yuki could buy a ‘K’ number of blades with cost 'B.’ He now has ‘2*K’ blades.
where 'A' and 'B' are predefined and constant.
Yuki does not want to get robbed in the fair. Being his nerd friend can you tell him the minimum price he needs to pay to buy exactly ‘N’ ninja blades, considering he has 0 blades initially?

Note:

There can be two or more ways with the exact cost. You can consider any one of them, but the overall cost to reach from 0 to 'N' must be minimized.
For example:

Consider Yuki need to buy 5 blades, the cost of adding 1 blade is 2, and the cost of doubling the blades is 1 then you have to perform the following operations:
1) Doubling 0 will result in 0 only, so add 1 blade to 0 blades with cost 2. Total cost becomes 2.

2) Next, you can either double 1 to reach 2 or add 1 blade. But since the cost of doubling is less than that of adding, so double 1 with cost 1. Total cost becomes 3.

3) Doubling 2 will result in 4 with a cost of 1. Total becomes 4.

4) Adding 1 in 4 will result in 5 (which is the desired number) with a cost of 2. The total cost to reach 5 becomes 6.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= ‘T’ <= 100
1 <= 'N' <= 10^4
0 <= 'A','B' <= 10^3

Time limit: 1 second
Sample Input 1:
3
13 5 8
1 5 8
2 5 3    
Sample Output 1:
36
5
8
Explanation of Input 1:
(i)For the first test case:
 Possible series of operations we need to perform: (+1) -> (+1) -> (+1) -> (*2) -> (*2) -> (+1)
 So minimum cost: 5+5+5+8+8+5 = 36

(ii)For the second test case:
Possible series of operations we need to perform: (+1)
So minimum cost: 5 

(iii)For the second test case:
Possible series of operations we need to perform: (+1) -> (*2) 
So minimum cost: 5+3 = 8
Sample Input 2:
5
1 2 2
2 17 2
3 3 4
4 2 1
5 5 8
Sample Output 2
2
19
9
4
23
Explanation of Input 1:
(i)For the first test case:
 Possible series of operations we need to perform: (+1)
So minimum cost: 2
Operations: (+1) Cost: 2

(ii)For the second test case:
 Possible series of operations we need to perform: (+1) -> (*2) 
 So minimum cost: 17 + 2 = 19

(iii)For the third test case:
 Possible series of operations we need to perform: (+1) -> (+1) -> (+1)
 So minimum cost: 3+3+3 = 9

(iv) For the first test case:
 Possible series of operations we need to perform: (+1) -> (*2) -> (*2)
 So minimum cost: 2 + 1 + 1 = 4

(v) For the first test case:
 Possible series of operations we need to perform: (+1) -> (+1) -> (*2) -> (+1)
 So minimum cost: 5+5+8+5 = 23
******************************************************************************/

#include <bits/stdc++.h> 
int minCostToBuyN(int n, int a, int b) {
    vector<int> dp(n + 1, INT_MAX);
    
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1] + a;

        if (i % 2 == 0) {
            dp[i] = min(dp[i], dp[i / 2] + b);
        }
    }

    return dp[n];
}
