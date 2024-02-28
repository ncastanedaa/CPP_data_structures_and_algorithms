//Code made by Nicolas Castaneda 
#include<iostream>
#include<vector>
#include<random>
#include<chrono>
#include<thread>
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
                 matrix[row][column] = matrix[column][row] = generateRandom(probability);
                 this_thread::sleep_for(chrono::milliseconds(1));
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


int generateRandom(double probability) {
    random_device rd;
    mt19937_64 gen(static_cast<unsigned>(chrono::system_clock::now().time_since_epoch().count()));
    uniform_real_distribution<> dis(0, 1.0);

    double random =dis(gen);
    if (random < probability){
        return 1;
    }else{
        return 0;
    }
}

   

int randomInt(int max){
    random_device rd;
    mt19937_64 gen(rd());
    uniform_int_distribution<> dis(0,max);
    return dis(gen);
}

};

int main(){

    vector<vector<int>> graph_1;
    graph my_graph(20,0.3);
    graph_1 = my_graph.make_unweighted_graph(my_graph.nodes,my_graph.density);
    my_graph.print_graph(graph_1);

    cout << endl;
    cout << "Press any key to exit..." << endl;

    // Wait for a key press
    _getch();

    return 0;
}