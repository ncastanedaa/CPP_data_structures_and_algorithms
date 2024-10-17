/*
Code made by Nicolas Castaneda

This code makes a random undirected graph wth parameters #nodes and density (probability) free to the user.
It also has the function fill_weights(...) to put random POSITIVE weigths iN the edges of the nodes.
*/

#include<iostream>
#include<cstdlib>
#include<vector>
#include<random>
#include<ctime>
#include<limits>
#include <queue>
#include<conio.h>

using namespace std;


class Node{
// this class represents the Node element with an int index and a list of adjacent nodes to it.
public:

private:

};

class Graph{

// graph reperesented by a matrix with its elements[i][j] the weight of the path from node i to node j;

public:

int number_of_nodes;
double density;
vector<vector<int>> matrix;

Graph(int nd,double dns):number_of_nodes(nd),density(dns), matrix(make_unweighted_graph(nd,dns)){
    
}

vector<vector<int>> fill_weights(vector<vector<int>>& matrix,int max_weight){
    for(int row = 0; row < matrix.size(); row++){
        for(int column = 0; column < row; column++){
            matrix[row][column] = matrix[column][row] *= randomInt(max_weight);
        }
    }
    return matrix;
}


void printg(vector<vector<int>>& matrix){
    for(const auto& row: matrix){
        for(const auto& element: row){
            if(element < 0){
                cout << "-" << " ";
            }else{
                cout << element << " ";
            }
        }
        cout << endl;
    }
    
}

const int INF = numeric_limits<int>::max(); // Infinity

// Dijkstra's algorithm function to find the shortest paths from the startNode to all other nodes.
// Input: graph (adjacency matrix), startNode (index of the starting node).
// Output: A vector containing the shortest distances from startNode to every other node.
vector<int> dijkstra(const vector<vector<int>>& graph, int startNode) {
    int n = graph.size(); // Number of nodes in the graph.
    vector<int> dist(n, INF); // Initialize distances to all nodes as infinity.
    vector<bool> visited(n, false); // Track whether a node has been visited.
    dist[startNode] = 0; // Distance to the starting node is always 0.

    // Min-heap priority queue to store (distance, node) pairs.
    // The priority queue helps efficiently fetch the node with the minimum distance.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, startNode}); // Push the starting node with distance 0 into the queue.

    // Loop until there are no more nodes to process in the priority queue.
    while (!pq.empty()) {
        // Extract the node with the minimum distance from the priority queue.
        int node = pq.top().second; // Get the node index.
        pq.pop();

        // If this node has already been visited, skip it.
        if (visited[node]) continue;

        // Mark the current node as visited.
        visited[node] = true;

        // Iterate through all neighbors of the current node.
        for (int neighbor = 0; neighbor < n; ++neighbor) {
            // Check if there is an edge between 'node' and 'neighbor'.
            if (graph[node][neighbor] != 0 && !visited[neighbor]) {
                // Calculate the new distance to the neighbor.
                int newDist = dist[node] + graph[node][neighbor];

                // If the new distance is shorter than the currently known distance, update it.
                if (newDist < dist[neighbor]) {
                    dist[neighbor] = newDist; // Update the distance to the neighbor.
                    pq.push({newDist, neighbor}); // Push the updated distance and node into the queue.
                }
            }
        }
    }

    return dist; // Return the vector of shortest distances from startNode to each node.
}

private:

vector<vector<int>> make_unweighted_graph(int num_nodes, double probability){
    num_nodes = number_of_nodes;
    probability = density;

    vector<vector<int>> matrix(number_of_nodes,vector<int>(number_of_nodes,0));

    for(int row = 0; row<number_of_nodes; row++){
        for(int column = 0; column < number_of_nodes; column++){
            if(row == column){
                matrix[row][column] = 0;
            }else{
                 matrix[row][column] = matrix[column][row] = generateRandomOnes(probability);
               
            };
        }
    }
    
    return matrix;
};


inline int generateRandomOnes(double probability){
    double percentile = probability*100;
    int random = rand()%100+1;
    if(random <= percentile){
        return 1;   
    }else{
        return 0;
    }
}  

inline int randomInt(int max){
    int random = rand()%max+1;
    return random;
}

};


int main(){


    srand(time(NULL));
    Graph my_graph_1(20,0.2);
    my_graph_1.printg(my_graph_1.matrix);
    cout << endl;
    my_graph_1.fill_weights(my_graph_1.matrix,9);
    my_graph_1.printg(my_graph_1.matrix);

    int startNode  = 0;
    int endNode = 5;

    vector<int> distances = my_graph_1.dijkstra(my_graph_1.matrix,startNode);

     // Print the shortest distances from startNode to all other nodes.
    cout << "Shortest distances from node " << startNode << ":\n";
    for (int i = 0; i < distances.size(); ++i) {
        // If a node is unreachable, it will still have a distance of INF.
        if (distances[i] == my_graph_1.INF) {
            cout << "Node " << i << ": Unreachable\n";
        } else {
            cout << "Node " << i << ": " << distances[i] << "\n";
        }
    }

   
    cout << endl;
    cout << "Press any key to exit..." << endl;

    // Wait for a key press

    _getch();

    return 0;
}