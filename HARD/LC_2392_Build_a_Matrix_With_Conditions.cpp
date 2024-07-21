class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        std::vector<int> orderRows    = topoSort(rowConditions, k);
        std::vector<int> orderColumns = topoSort(colConditions, k);

        // If no topological sort exists, return empty array.
        if (orderRows.empty() or orderColumns.empty()) {
            return {};
        }
        std::vector<vector<int>> matrix(k, vector<int>(k, 0));

        for (int i = 0; i < k; i++) 
        {
            for (int j = 0; j < k; j++) 
            {
                if (orderRows[i] == orderColumns[j]) {
                    matrix[i][j] = orderRows[i];
                }
            }
        }
        return matrix;
    }


    // Topological sort: Kahn's algorithm
    std::vector<int> topoSort(const std::vector<vector<int>>& edges, int n)
    {
        std::vector<vector<int>> adj(n + 1);
        std::vector<int>         deg(n + 1);
        std::vector<int>         order;

        for (auto x : edges) 
        {
            adj[x[0]].push_back(x[1]);
            deg[x[1]]++;
        }
        std::queue<int> q;

        // Push all integers with in-degree 0 in the queue.
        for (int i = 1; i <= n; i++) 
        {
            if (deg[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) 
        {
            int f = q.front();
            q.pop();

            order.push_back(f);
            n--;

            for (auto v : adj[f])
            {
                if (--deg[v] == 0) {
                    q.push(v);
                }
            }
        }
        // If we have not visited all integers, return empty array.
        if (n != 0) {
            return {};
        }
        return order;
    }
};


/*
topologial sort:

Kahn's Algorithm
Intuition
Kahn’s algorithm works by keeping track of the number of incoming edges into each node (in-degree). It works by repeatedly visiting the nodes with an in-degree of zero and deleting all the edges associated with it leading to a decrement of in-degree for the nodes whose incoming edges are deleted. This process continues until no elements with zero in-degree can be found.

If you are not familiar with Kahn's algorithm, we suggest you read our LeetCode Explore Card.

After constructing the graph, we can push all the nodes with in-degree 0 to a queue. These nodes represent integers that are not constrained by the position of other integers. In a queue, push these integers first, since they can be completed without any prerequisites.

Now, iterate over all the queue elements, push them in the topologically sorted array, and reduce the in-degree by 1 of each direct neighbor of the current node. If the in-degree of the direct neighbor becomes 0, push it in the queue. Repeat the process till you have visited all the nodes.

For example, let's say the given graph has three edges: 1 -> 2, 2 -> 3, and 1 -> 3. In this graph, the in-degree of each node represents the number of prerequisites that must be completed before reaching that node:

Node 1 has an in-degree of 0
Node 2 has an in-degree of 1
Node 3 has an in-degree of 2
We start with node 1, as it has no prerequisites. We add it to our queue and process it first. Node 1 is a direct prerequisite for both nodes 2 and 3, so we decrement their in-degrees:

Node 2's in-degree becomes 0
Node 3's in-degree becomes 1
Now we can add node 2 to our queue, as its in-degree is 0. Processing node 2, we decrement the in-degree of its neighbor, node 3:

Node 3's in-degree becomes 0
Finally, we add node 3 to our queue and process it.

The resulting topologically sorted order is 1 -> 2 -> 3.

Algorithm
Main function - buildMatrix(k, rowConditions, colConditions)

Create two arrays given by orderRows and orderColumns to store the topological sorted sequence.
Store the values of topoSort(rowConditions,k) and topoSort(colConditions,k) in them.
If either of the arrays is empty, return {}.
Create matrix of size k x k and initialize all values with 0.
Iterate i through all values from 0 to k:
Iterate j through all values from 0 to k:
If orderRows[i] = orderColumns[j], store orderRows[i] in matrix[i][j].
Return the matrix.
topoSort(edges,n)

Initialize an adjacency matrix adj with n+1 rows, an array deg with size n+1 and an empty array order.
Store all the edges in adj by pushing b in adj[a] denoting an edge from a to b. Also, increment the in-degree of the nodes in the deg array.
Initialize a queue q and push all nodes with in-degree values 0 to the queue.
While q is not empty:
Store the front element of q in f and pop it.
Push the front element in order.
Decrement n by 1.
Iterate through all neighbors of f:
Decrement the in-degree of current node. If in-degree is 0, push it in q.
If n is not equal to 0, return empty array.
Return order.

Complexity Analysis
Let n be the size of the rowConditions and colConditions array.

Time complexity: O(max(k⋅k,n))

Since the total edges in the graph are n and all the nodes are visited exactly once, the time complexity of the breadth-first search operation is O(n).

The time complexity of creating and filling the values of a k⋅k sized matrix is O(k⋅k). Both these operations are performed independently.

Therefore, the time complexity is given by O(max(k⋅k,n)).

Space complexity: O(max(k⋅k,n))

Since the total edges in the graph are n, the space complexity of the breadth-first search operation is O(n).

The space complexity of creating a k⋅k sized matrix is O(k⋅k). Both these operations are performed independently.

Therefore, the space complexity is given by O(max(k⋅k,n)).
*/
