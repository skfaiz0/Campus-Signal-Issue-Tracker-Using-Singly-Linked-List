#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Edge {
    int u, v, cost;
};

bool compare(Edge a, Edge b) {
    return a.cost < b.cost;
}

class DSU {
    vector<int> parent, rankValue;

public:
    DSU(int n) {
        parent.resize(n);
        rankValue.resize(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return false;

        if (rankValue[a] < rankValue[b])
            swap(a, b);

        parent[b] = a;

        if (rankValue[a] == rankValue[b])
            rankValue[a]++;

        return true;
    }
};

int main() {
    int n, m;

    cout << "Enter number of stations: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid number of stations.\n";
        return 0;
    }

    vector<string> station(n);

    cout << "Enter station names:\n";
    for (int i = 0; i < n; i++)
        cin >> station[i];

    cout << "\nStation Numbers:\n";
    for (int i = 0; i < n; i++)
        cout << i + 1 << ". " << station[i] << endl;

    cout << "\nEnter number of proposed tracks: ";
    cin >> m;

    if (m < 0) {
        cout << "Invalid number of tracks.\n";
        return 0;
    }

    vector<Edge> edges;

    cout << "Enter each track as: station1 station2 cost\n";
    cout << "Use station numbers from the list above.\n";

    for (int i = 0; i < m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;

        if (u < 1 || u > n || v < 1 || v > n ||
            u == v || cost < 0) {
            cout << "Invalid track details.\n";
            return 0;
        }

        edges.push_back({u - 1, v - 1, cost});
    }

    sort(edges.begin(), edges.end(), compare);

    DSU dsu(n);
    long long totalCost = 0;
    int selected = 0;

    cout << "\nMinimum-Cost Railway Network:\n";
    cout << "Track\t\tConstruction Cost\n";

    for (const auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            cout << station[e.u] << " - "
                 << station[e.v] << "\t\t"
                 << e.cost << endl;

            totalCost += e.cost;
            selected++;
        }
    }

    if (selected != n - 1) {
        cout << "\nA complete railway network is not possible "
             << "with the given tracks.\n";
    } else {
        cout << "\nMinimum Total Construction Cost: "
             << totalCost << endl;
    }

    return 0;
}
