# Railway Network Planner – Kruskal's Algorithm

**CCE III Programming Assignment – Unit 5 (C++)**

## Problem Statement

Develop a railway network with stations and proposed track connections that
carry construction costs, and apply **Kruskal's algorithm** to identify the
**minimum-cost track network** that connects all the stations.

## Modelling

| Real world                    | Graph concept            |
|-------------------------------|--------------------------|
| Station                       | Vertex                   |
| Proposed track connection     | Undirected edge          |
| Construction cost of a track  | Edge weight              |
| Cheapest network linking all  | Minimum Spanning Tree    |

A network connecting `N` stations with no wasted track needs exactly `N - 1`
tracks and no cycles. Of all such networks, we want the one with the smallest
total cost.

## Algorithm (Kruskal's)

1. Read the stations and the list of proposed tracks (`station1 station2 cost`).
2. **Sort** all tracks in increasing order of cost.
3. Start with every station in its own set (Disjoint Set Union / Union-Find).
4. Go through the sorted tracks one by one:
   - If the two stations are in **different** sets, **accept** the track and
     merge the sets.
   - If they are already in the **same** set, **reject** it (it would form a cycle).
5. Stop when `N - 1` tracks are accepted (or tracks run out).
6. Print the accepted tracks and the total cost.

### Pseudocode

```
KRUSKAL(stations, tracks):
    sort tracks by cost ascending
    make-set(s) for every station s
    result = empty list; total = 0
    for each track (u, v, cost) in tracks:
        if find(u) != find(v):
            union(u, v)
            add track to result; total += cost
            if |result| == N - 1: break
    return result, total
```

## Explanation

- **Why greedy works:** the cheapest track that does not form a cycle is always
  part of some minimum spanning tree (the *cut property*), so picking tracks
  cheapest-first never rules out an optimal answer.
- **Cycle detection:** Union-Find with *path compression* and *union by rank*
  answers "are these two stations already connected?" in near-constant time.
- **Disconnected input:** if the proposed tracks cannot link every station, the
  program warns the user and prints the cheapest network for each connected
  group (a minimum spanning forest).
- **Input validation:** duplicate station names, unknown stations,
  self-loops, negative costs and non-numeric costs are rejected with a
  message, and the question is asked again.

### Complexity

Let `V` = stations and `E` = proposed tracks.

- Time: **O(E log E)** (dominated by sorting)
- Space: **O(V + E)**

## How to Compile and Run

```bash
g++ -std=c++17 -O2 -Wall -o main main.cpp
./main                       # type the answers one by one
./main < sample_input.txt    # or read the answers from a file
```

### How to enter the data (step by step)

The program asks one simple question at a time. Example run
(the text after each colon is what the user types):

```
=== RAILWAY NETWORK PLANNER ===

How many stations are there? 3
  Name of station 1: Pune
  Name of station 2: Mumbai
  Name of station 3: Nashik

Your stations: Pune, Mumbai, Nashik

Now enter the possible tracks. For each track you will be asked
for its two stations and its building cost.

How many possible tracks are there? 3

Track 1 of 3:
  From station : Pune
  To station   : Mumbai
  Cost         : 120

Track 2 of 3:
  From station : Mumbai
  To station   : Nashik
  Cost         : 100

Track 3 of 3:
  From station : Pune
  To station   : Nashik
  Cost         : 150

===== Minimum-Cost Railway Network =====
No.   From            To              Cost
----------------------------------------------
1     Mumbai          Nashik          100
2     Pune            Mumbai          120
----------------------------------------------
Tracks selected : 2
Total cost      : 220
```

Wrong answers (a misspelt station, a negative cost, a repeated name) show a
message and the question is asked again.

### Input file format (for `sample_input.txt`)

The same answers, written in the same order:

```
<number of stations>
<station names, separated by spaces>
<number of possible tracks>
<station1> <station2> <cost>      (one line per track)
```

## Sample Input (`sample_input.txt`)

```
7
Pune Mumbai Nashik Aurangabad Nagpur Kolhapur Solapur
11
Pune Mumbai 120
Pune Nashik 150
Pune Kolhapur 200
Pune Solapur 180
Mumbai Nashik 100
Nashik Aurangabad 140
Aurangabad Nagpur 350
Nashik Nagpur 420
Solapur Kolhapur 160
Solapur Aurangabad 250
Mumbai Kolhapur 270
```

## Sample Output (`sample_output.txt`)

```
===== Minimum-Cost Railway Network =====
No.   From            To              Cost
----------------------------------------------
1     Mumbai          Nashik          100
2     Pune            Mumbai          120
3     Nashik          Aurangabad      140
4     Solapur         Kolhapur        160
5     Pune            Solapur         180
6     Aurangabad      Nagpur          350
----------------------------------------------
Tracks selected : 6
Total cost      : 1050
```

(This is what `./main < sample_input.txt` prints. The questions are shown on the screen only while typing answers by hand.)

### Walkthrough of the sample

Sorted tracks: 100, 120, 140, 150, 160, 180, 200, 250, 270, 350, 420.

| Track                | Cost | Decision | Reason                                  |
|----------------------|------|----------|-----------------------------------------|
| Mumbai – Nashik      | 100  | Accept   | Joins two separate components           |
| Pune – Mumbai        | 120  | Accept   | Joins Pune to {Mumbai, Nashik}          |
| Nashik – Aurangabad  | 140  | Accept   | Joins Aurangabad                        |
| Pune – Nashik        | 150  | Reject   | Both already connected (cycle)          |
| Solapur – Kolhapur   | 160  | Accept   | Joins two separate components           |
| Pune – Solapur       | 180  | Accept   | Merges the two groups                   |
| Pune – Kolhapur      | 200  | Reject   | Cycle                                   |
| Solapur – Aurangabad | 250  | Reject   | Cycle                                   |
| Mumbai – Kolhapur    | 270  | Reject   | Cycle                                   |
| Aurangabad – Nagpur  | 350  | Accept   | Joins Nagpur – network complete (6 = 7−1) |

**Minimum total construction cost = 1050** (costs in crore ₹, for example).
