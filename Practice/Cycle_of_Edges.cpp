#include<bits/stdc++.h>
using namespace std;

int par[100005];
int group[100005];

int find(int n) {
    if (par[n] == -1) return n;
    return par[n] = find(par[n]);
}

void dsu_union(int n1, int n2) {
    int p1 = find(n1);
    int p2 = find(n2);
    if (p1 != p2) {
        if (group[p1] >= group[p2]) {
            par[p2] = p1;
            group[p1] += group[p2];
        } else {
            par[p1] = p2;
            group[p2] += group[p1];
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    for (int i = 1; i <= n; ++i) {
        par[i] = -1;
        group[i] = 1;
    }

    int edge = 0;

    while (e--) {
        int a, b;
        cin >> a >> b;

        int l1 = find(a);
        int l2 = find(b);

        if (l1 == l2) {
            edge++;
        } else {
            dsu_union(a, b);
        }
    }

    cout << edge << endl;

    return 0;
}