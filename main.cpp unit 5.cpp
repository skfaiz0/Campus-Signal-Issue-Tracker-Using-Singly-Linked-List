#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

// A proposed track between two stations with its construction cost.
struct Track {
    int from;
    int to;
    long long cost;
};

// ---------------------------------------------------------------------
// Disjoint Set Union (Union-Find) - tells us if two stations are already
// connected, so we never build a track that forms a loop.
// ---------------------------------------------------------------------
class DisjointSet {
    vector<int> parent, rnk;

public:
    explicit DisjointSet(int n) : parent(n), rnk(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);  // path compression
        return parent[x];
    }

    // Returns true if a and b were in different groups (and are now merged).
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;  // already connected -> would form a cycle
        if (rnk[a] < rnk[b]) swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b]) rnk[a]++;
        return true;
    }
};

// ---------------------------------------------------------------------
// Kruskal's algorithm
// ---------------------------------------------------------------------
vector<Track> kruskal(int stationCount, vector<Track> tracks, long long &totalCost) {
    // Step 1: sort all proposed tracks by cost (cheapest first).
    sort(tracks.begin(), tracks.end(),
         [](const Track &a, const Track &b) { return a.cost < b.cost; });

    DisjointSet dsu(stationCount);
    vector<Track> chosen;
    totalCost = 0;

    // Step 2: keep a track only if it joins two stations that are not
    // already connected.
    for (const Track &t : tracks) {
        if (dsu.unite(t.from, t.to)) {
            chosen.push_back(t);
            totalCost += t.cost;
            if ((int)chosen.size() == stationCount - 1) break;  // network complete
        }
    }
    return chosen;
}

// ---------------------------------------------------------------------
// Simple input helpers: each one keeps asking until the answer is valid.
// ---------------------------------------------------------------------
void stopIfInputEnded() {
    if (cin.eof()) {
        cerr << "\nInput ended before all answers were given.\n";
        exit(1);
    }
}

// Ask for a whole number that is at least minValue.
long long askNumber(const string &question, long long minValue) {
    while (true) {
        cerr << question;
        long long x;
        if (cin >> x) {
            if (x >= minValue) return x;
            cerr << "  Please enter a number that is " << minValue << " or more.\n";
        } else {
            stopIfInputEnded();
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "  That is not a number. Please try again.\n";
        }
    }
}

// Ask for a new station name (no duplicates).
string askNewStationName(const string &question, const map<string, int> &idOf) {
    while (true) {
        cerr << question;
        string name;
        cin >> name;
        stopIfInputEnded();
        if (!idOf.count(name)) return name;
        cerr << "  You already entered '" << name << "'. Please use a different name.\n";
    }
}

// Ask for the name of a station that was already entered.
string askExistingStation(const string &question, const map<string, int> &idOf) {
    while (true) {
        cerr << question;
        string name;
        cin >> name;
        stopIfInputEnded();
        if (idOf.count(name)) return name;
        cerr << "  Station '" << name << "' was not entered. Check the spelling.\n";
    }
}

int main() {
    // ---------- Step 1: stations ----------
    cerr << "=== RAILWAY NETWORK PLANNER ===\n\n";
    int n = (int)askNumber("How many stations are there? ", 1);

    vector<string> names;
    map<string, int> idOf;
    for (int i = 0; i < n; i++) {
        string name = askNewStationName("  Name of station " + to_string(i + 1) + ": ", idOf);
        idOf[name] = i;
        names.push_back(name);
    }

    cerr << "\nYour stations: ";
    for (int i = 0; i < n; i++) cerr << names[i] << (i + 1 < n ? ", " : "\n");

    // ---------- Step 2: possible tracks ----------
    cerr << "\nNow enter the possible tracks. For each track you will be asked\n"
            "for its two stations and its building cost.\n\n";
    int m = (int)askNumber("How many possible tracks are there? ", 0);

    vector<Track> tracks;
    for (int i = 0; i < m; i++) {
        cerr << "\nTrack " << i + 1 << " of " << m << ":\n";
        string a = askExistingStation("  From station : ", idOf);
        string b;
        while (true) {
            b = askExistingStation("  To station   : ", idOf);
            if (b != a) break;
            cerr << "  A track must join two different stations.\n";
        }
        long long cost = askNumber("  Cost         : ", 0);
        tracks.push_back({idOf[a], idOf[b], cost});
    }

    // ---------- Step 3: run Kruskal and print the result ----------
    long long totalCost = 0;
    vector<Track> chosen = kruskal(n, tracks, totalCost);

    cerr << "\n";  // blank line on screen between the questions and the result
    cout << "===== Minimum-Cost Railway Network =====\n";
    cout << left << setw(6) << "No." << setw(16) << "From" << setw(16) << "To"
         << "Cost\n";
    cout << string(46, '-') << "\n";
    for (size_t i = 0; i < chosen.size(); i++) {
        cout << left << setw(6) << i + 1 << setw(16) << names[chosen[i].from]
             << setw(16) << names[chosen[i].to] << chosen[i].cost << "\n";
    }
    cout << string(46, '-') << "\n";

    if ((int)chosen.size() != n - 1) {
        cout << "Warning: the proposed tracks do not connect all stations.\n"
             << "Showing the cheapest network for each connected group.\n";
    }
    cout << "Tracks selected : " << chosen.size() << "\n";
    cout << "Total cost      : " << totalCost << "\n";
    return 0;
}
