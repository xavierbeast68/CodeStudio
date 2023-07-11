//* https://www.codingninjas.com/studio/contests/weekend-contest-81/8894371/problems/23842

#include <bits/stdc++.h>
using namespace std;

/*
    Time complexity: O(K * Log(K))
    Space complexity: O(K)

    Where ‘K = N + M’ and ‘N’ and ‘M’ is the lengths of arrays ‘A’ and ‘B’,
*/

// DSU datastructure class.
class DSU {
public:
    vector<int> p, rank;
    int n;

    DSU(int _n) {
        n = _n;
        p.resize(n);
        rank.assign(n, 1);
        // Initializing the parent array.
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
    }

    // Method to return the parent of passed element.
    int findSet(int i) {
        int t = i;
        while (i != p[i]) {
            i = p[i];
        }
        while (t != p[t]) {
            int c = t;
            t = p[t];
            p[c] = i;
        }
        return i;
    }

    // Method to check whether two elements belongs to the same set or not.
    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }

    // Method to unite two sets.
    void unionSet(int i, int j) {
        i = findSet(i);
        j = findSet(j);
        if (i != j) {
            if (rank[i] < rank[j]) {
                p[i] = j;
            } else {
                p[j] = i;
                if (rank[i] == rank[j]) {
                    rank[i]++;
                }
            }
        }
    }
};

long long getMinimumCost(int n, int m, vector<int> a, vector<vector<int>> b) {
    // Initializing the DSU object.
    DSU cur(n + 1);

    // Getting the minimum weight index in array 'A'.
    int u = min_element(a.begin(), a.end()) - a.begin();

    // Updating the first element as the weight.
    for (vector<int> &edge : b) {
        swap(edge[0], edge[2]);
    }

    // Adding extra edges to the array 'b'.
    for (int i = 0; i < n; i++) {
        if (i == u) {
            continue;
        }
        b.push_back({a[i] + a[u], i + 1, u + 1});
    }

    // Sorting out the array 'b'.
    sort(b.begin(), b.end());

    // Initializing 'res'.
    long long res = 0;

    // Iterating over the edges in 'b' and processing each of them.
    for (vector<int> &edge : b) {
        if (!cur.isSameSet(edge[1], edge[2])) {
            cur.unionSet(edge[1], edge[2]);
            res += edge[0];
        }
    }

    // Returning 'res'.
    return res;
}