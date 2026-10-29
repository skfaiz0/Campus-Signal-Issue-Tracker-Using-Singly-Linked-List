# Railway Network Using Kruskal's Algorithm

## 1. Problem Statement
Develop a railway network consisting of stations and proposed track connections, where each track has a construction cost. Apply Kruskal's algorithm to identify the minimum-cost track network that connects all stations without forming cycles.

## 2. Objective
- Represent railway stations and track connections as a weighted graph.
- Implement Kruskal's Minimum Spanning Tree (MST) algorithm.
- Minimize the total construction cost.
- Connect all stations without creating cycles.

## 3. Data Structures Used
- **Edge structure:** Stores two station numbers and the construction cost.
- **Vector:** Stores station names and proposed tracks.
- **Disjoint Set Union (DSU):** Detects cycles and combines connected components.
- **Sorting:** Arranges tracks in increasing order of construction cost.

## 4. Algorithm
1. Read the number and names of stations.
2. Read the proposed tracks and their construction costs.
3. Sort all tracks in ascending order of cost.
4. Examine each track from cheapest to most expensive.
5. Use DSU to check whether the track would create a cycle.
6. Select the track if it connects two different components.
7. Stop when `V - 1` tracks have been selected or all tracks have been examined.
8. Display the selected tracks and the total cost. If not all stations can be connected, display a message.

## 5. Working
Kruskal's algorithm selects tracks in increasing order of construction cost. The DSU structure checks whether adding a track would create a cycle. A track is selected only if it connects two previously separate components.

For the sample input, the selected costs are 1, 2, 2, 3 and 5.

**Minimum total construction cost = 1 + 2 + 2 + 3 + 5 = 13 cost units.**

## 6. Sample Input
```text
6
A B C D E F
9
1 2 4
1 3 2
2 3 1
2 4 5
3 4 8
3 5 10
4 5 2
4 6 6
5 6 3
```

## 7. Sample Output
```text
Enter number of stations: 6
Enter station names:
A B C D E F

Station Numbers:
1. A
2. B
3. C
4. D
5. E
6. F

Enter number of proposed tracks: 9
Enter each track as: station1 station2 cost
Use station numbers from the list above.

Minimum-Cost Railway Network:
Track           Construction Cost
B - C           1
A - C           2
D - E           2
E - F           3
B - D           5

Minimum Total Construction Cost: 13
```

## 8. Time Complexity
- Sorting the edges: `O(E log E)`
- DSU operations: Nearly linear overall.
- Overall time complexity: **O(E log E)**

Here, `V` is the number of stations and `E` is the number of proposed tracks.

## 9. Conclusion
Kruskal's algorithm finds a Minimum Spanning Tree for the railway network. It selects the lowest-cost tracks required to connect all stations without cycles, minimizing the total construction cost.

## 10. How to Compile and Run
Using g++:
```bash
g++ main.cpp -o railway
./railway
```
On Windows, run `railway.exe` after compiling.
