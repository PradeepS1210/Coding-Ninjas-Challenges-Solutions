// Companies asking this question: American Express, Bank Of America, HSBC, Amazon

/*******************************************************************
Problem statement
You are given an array 'ARR' of 'N' distinct integers.

Your task is to find the product 'P' with the highest count('C') of quadruples which follow p * q = r * s where p, q, r, and s are elements of the array with different indexes.

Note:
1. Quadruple p*q = r*s is the same as r*s = p*q.

2. If 2 or more products have the same count of quadruples, print the lowest value of the product i.e if (P1, P2) are the 2 products with the same count of such quadruples(C1 = C2) then 'P' = min(P1, P2).

3. If no such quadruple exists('C' = 0), return 0.
Example:

If the given array is [3, 4, 6, 2, 1], then the answer would be 6 1. Because there are two products 'P' i.e 6 and 12 which have the highest and same count 'C' of quadruples, i.e 'C' = 1. Therefore the lowest value of the product 'P' is the answer i.e 6.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 100
4 <= N <= 10^2  
1 <= ARR[i] <= 10^9

Where 'ARR[i]' denotes the element at index 'i' in the array 'ARR'.

Time Limit: 1 sec
Sample Input 1:
2
6
2 6 3 4 1 12 
6
4 1 7 2 6 5
Sample Output 1:
12 3
0
Explanation for Sample 1:
In test case 1, there are a total of 3 quadruples for product 12 in the given array as given below:

2 6 and 3 4, (p = 2, q = 6, r = 3 and s = 4).
2 6 and 1 12, (p = 2, q = 6, r = 1 and s = 12).
3 4 and 1 12, (p = 3, q = 4, r = 1 and s = 12).

Thus, product('P') = 12, Count('C') = 3. No other value has 3 or more Quadruples.

In test case 2, every pair of elements forms a different value on multiplying, and thus no Quadruple is formed by the given set of elements of the array. Hence 0 Quadruples formed.
Sample Input 2:
1
8
7 2 10 1 8 3 9 4
5
4 2 1 8 2
Sample Output 2:
8 1
8 3
Explanation for Sample Output 2:
In test case 1, there is only one quadruple in the given array i.e (p = 2, q = 4, r = 8 and s = 1). Thus, Product('P') = 8 and Count('C') = 1. No other Quadruple is possible.

In test case 2, there are a total of 3 quadruples for product 8 in the given array as given below:

1 8 and 2i 4, (p = 1, q = 8, r = 2i and s = 4).
1 8 and 2ii 4, (p = 1, q = 8, r = 2ii and s = 4).
2i 4 and 2ii 4, (p = 2i, q = 4, r = 2ii and s = 4).

Here, 2i and 2ii denote the two different occurrences of 2 in the array.

Thus, Product('P') = 8, Count('C') = 3. No other value has 3 or more Quadruples.
*******************************************************************/

#include <bits/stdc++.h> 
using namespace std;

vector<long long> maxProductCount(vector<int> &arr, int n) {
    
    unordered_map<long long, int> map;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long a = arr[i];
            long long b = arr[j];
            long long pairProduct = a * b;
            map[pairProduct]++;
        }
    }

    long long maxProd = 0;

    int freq = 0;

    for (auto prods : map) {
        if (prods.second >= freq) {
            if (prods.second == freq) {
                maxProd = min(maxProd, prods.first);
            } 
            else {
                maxProd = prods.first;
            }
            freq = prods.second;
        }
    }

    vector<long long> result;

    if (map.find(maxProd) == map.end() || map[maxProd] == 1) {
        result.push_back(0);
        result.push_back(0);
        return result;
    }
    else {
        long long allCombinations = ((freq * (freq - 1))) / 2;
        result.push_back(maxProd);
        result.push_back(allCombinations);
        return result;
    }
}