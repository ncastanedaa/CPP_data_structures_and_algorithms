//Code made by Nicolas Castaneda 
#include<iostream>
#include<cstdlib>
#include<vector>
#include<random>
#include<thread>
#include<ctime>
#include<conio.h>
using namespace std;

class graph{

// graph reperesented by a matrix with its elements[i][j] the weight of the path from node i to node j;

public:

int nodes;
double density;

graph(int nd,double dns):nodes(nd),density(dns){
    
}

vector<vector<int>> make_unweighted_graph(int num_nodes, double probability){
    num_nodes = nodes;
    probability = density;

    vector<vector<int>> matrix(nodes,vector<int>(nodes,0));

    for(int row = 0; row<nodes; row++){
        for(int column = 0; column < nodes; column++){
            if(row == column){
                matrix[row][column] = 0;
            }else{
                 matrix[row][column] = matrix[column][row] = generateRandomOnes(probability);
               
            };
        }
    }
    return matrix;
};

vector<vector<int>> fill_weights(vector<vector<int>>& matrix,int max_weight){
    for(int row = 0; row < matrix.size(); row++){
        for(int column = 0; column < matrix.size(); column++){
            matrix[row][column] *= randomInt(max_weight);
        }
    }
    return matrix;
}


void print_graph(vector<vector<int>>& matrix){
    for(const auto& row: matrix){
        for(const auto& element: row){
            cout <<element<< " ";
        }
        cout << endl;
    }
    
}

private:


int generateRandomOnes(double probability){
    double percentile = probability*100;
    int random = rand()%100+1;
    if(random <= percentile){
        return 1;   
    }else{
        return 0;
    }
}  

int randomInt(int max){
    int random = rand()%max+1;
    return random;
}

};

int main(){
    srand(time(NULL));
    vector<vector<int>> graph_1, graph_2;
    graph my_graph(50,0.2);
    graph_1 = my_graph.make_unweighted_graph(my_graph.nodes,my_graph.density);
    my_graph.print_graph(graph_1);
    graph_2 = my_graph.fill_weights(graph_1,9);
    cout << endl;
    my_graph.print_graph(graph_2);

    cout << endl;
    cout << "Press any key to exit..." << endl;

    // Wait for a key press
    _getch();

    return 0;
}