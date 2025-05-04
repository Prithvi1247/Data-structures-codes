#include <iostream>
using namespace std;
//Program for Graph ADT using adjacency matrix
const int MAX_VERTICES = 100;

// Function prototypes
void insertEdge(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int n, int src, int dest);
void deleteEdge(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int n, int src, int dest);
bool searchEdge(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int n, int src, int dest);
void displayGraph(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int n);

//Main program
int main() {
    int n; 
    int adjMatrix[MAX_VERTICES][MAX_VERTICES] = {0}; 

    cout << "Enter the number of vertices in the graph (max " << MAX_VERTICES << "): ";
    cin >> n;

    if (n <= 0 || n > MAX_VERTICES) {
        cout << "Invalid number of vertices. Program exiting.\n";
        return 0;
    }

    int choice, src, dest;
    do {
        cout << "\nGraph Menu:\n";
        cout << "1. Insert Edge\n";
        cout << "2. Delete Edge\n";
        cout << "3. Search Edge\n";
        cout << "4. Display Graph\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter source and destination vertices (0 to " << n-1 << "): ";
                cin >> src >> dest;
                insertEdge(adjMatrix, n, src, dest);
                break;
            case 2:
                cout << "Enter source and destination vertices (0 to " << n-1 << "): ";
                cin >> src >> dest;
                deleteEdge(adjMatrix, n, src, dest);
                break;
            case 3:
                cout << "Enter source and destination vertices (0 to " << n-1 << "): ";
                cin >> src >> dest;
                if (searchEdge(adjMatrix, n, src, dest))
                    cout << "Edge exists between " << src << " and " << dest << ".\n";
                else
                    cout << "Edge does NOT exist between " << src << " and " << dest << ".\n";
                break;
            case 4:
                displayGraph(adjMatrix, n);
                break;
            case 5:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}

// Function definitions

//Function to insert an edge
void insertEdge(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int n, int src, int dest) {
    if (src >= 0 && src < n && dest >= 0 && dest < n) {
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1; // Undirected graph
        cout << "Edge inserted between " << src << " and " << dest << ".\n";
    } else {
        cout << "Invalid vertex number(s).\n";
    }
}
//Function to delete an edge
void deleteEdge(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int n, int src, int dest) {
    if (src >= 0 && src < n && dest >= 0 && dest < n) {
        adjMatrix[src][dest] = 0;
        adjMatrix[dest][src] = 0; // Undirected graph
        cout << "Edge deleted between " << src << " and " << dest << ".\n";
    } else {
        cout << "Invalid vertex number(s).\n";
    }
}
//Funtion to search an edge
bool searchEdge(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int n, int src, int dest) {
    if (src >= 0 && src < n && dest >= 0 && dest < n) {
        return adjMatrix[src][dest] == 1;
    } else {
        cout << "Invalid vertex number(s).\n";
        return false;
    }
}
//Function to display the graph
void displayGraph(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int n) {
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}
