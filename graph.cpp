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
            if(element > 100000){
                cout << "-" << " ";
            }else{
                cout << element << " ";
            }
        }
        cout << endl;
    }
    
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
        return 1000000;
    }
}  

inline int randomInt(int max){
    int random = rand()%max+1;
    return random;
}

};


int main(){
    srand(time(NULL));
    Graph my_graph_1(6,0.35);
    my_graph_1.printg(my_graph_1.matrix);
    cout << endl;
    my_graph_1.fill_weights(my_graph_1.matrix,9);
    my_graph_1.printg(my_graph_1.matrix);

    cout << endl;
    cout << "Press any key to exit..." << endl;

    // Wait for a key press

    _getch();

    return 0;
}