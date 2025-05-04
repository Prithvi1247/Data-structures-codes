#include <iostream>
using namespace std;
// Program to implement Graph ADT using Adjacency List 

const int MAX_VERTICES = 100;

// Structure to represent adjacency list node
struct Node {
    int dest;
    Node* next;
};

// Function prototypes
void insertEdge(Node* adjList[], int n, int src, int dest);
void deleteEdge(Node* adjList[], int n, int src, int dest);
bool searchEdge(Node* adjList[], int n, int src, int dest);
void displayGraph(Node* adjList[], int n);
void freeGraph(Node* adjList[], int n);

// Main program
int main() {
    int n;
    Node* adjList[MAX_VERTICES] = {NULL}; 

    cout << "Enter number of vertices in graph (max " << MAX_VERTICES << "): ";
    cin >> n;

    if (n <= 0 || n > MAX_VERTICES) {
        cout << "Invalid number of vertices. Exiting.\n";
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
                cout << "Enter source and destination vertices (0 to " << n - 1 << "): ";
                cin >> src >> dest;
                insertEdge(adjList, n, src, dest);
                break;
            case 2:
                cout << "Enter source and destination vertices (0 to " << n - 1 << "): ";
                cin >> src >> dest;
                deleteEdge(adjList, n, src, dest);
                break;
            case 3:
                cout << "Enter source and destination vertices (0 to " << n - 1 << "): ";
                cin >> src >> dest;
                if (searchEdge(adjList, n, src, dest)) {
                    cout << "Edge exists.\n";
                } else {
                    cout << "Edge does not exist.\n";
                }
                break;
            case 4:
                displayGraph(adjList, n);
                break;
            case 5:
                cout << "Exiting program.\n";
                freeGraph(adjList, n);
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}

// Function to insert edge into adjacency list (undirected graph)
void insertEdge(Node* adjList[], int n, int src, int dest) {
    if (src < 0 || src >= n || dest < 0 || dest >= n) {
        cout << "Invalid vertices.\n";
        return;
    }

    // Add edge src -> dest
    Node* newNode = new Node;
    newNode->dest = dest;
    newNode->next = adjList[src];
    adjList[src] = newNode;

    // Add edge dest -> src (undirected)
    Node* newNode2 = new Node;
    newNode2->dest = src;
    newNode2->next = adjList[dest];
    adjList[dest] = newNode2;

    cout << "Edge inserted.\n";
}

// Function to delete edge from adjacency list (undirected graph)
void deleteEdge(Node* adjList[], int n, int src, int dest) {
    if (src < 0 || src >= n || dest < 0 || dest >= n) {
        cout << "Invalid vertices.\n";
        return;
    }

    // Delete src -> dest
    Node* curr = adjList[src];
    Node* prev = NULL;
    while (curr != NULL) {
        if (curr->dest == dest) {
            if (prev == NULL)
                adjList[src] = curr->next;
            else
                prev->next = curr->next;
            delete curr;
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    // Delete dest -> src
    curr = adjList[dest];
    prev = NULL;
    while (curr != NULL) {
        if (curr->dest == src) {
            if (prev == NULL)
                adjList[dest] = curr->next;
            else
                prev->next = curr->next;
            delete curr;
            break;
        }
        prev = curr;
        curr = curr->next;
    }

    cout << "Edge deleted (if existed).\n";
}

// Function to search for edge
bool searchEdge(Node* adjList[], int n, int src, int dest) {
    if (src < 0 || src >= n || dest < 0 || dest >= n) {
        cout << "Invalid vertices.\n";
        return false;
    }

    Node* curr = adjList[src];
    while (curr != NULL) {
        if (curr->dest == dest)
            return true;
        curr = curr->next;
    }
    return false;
}

// Function to display graph
void displayGraph(Node* adjList[], int n) {
    cout << "Adjacency List of Graph:\n";
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        Node* curr = adjList[i];
        while (curr != NULL) {
            cout << curr->dest << " ";
            curr = curr->next;
        }
        cout << endl;
    }
}

// Function to free all allocated memory
void freeGraph(Node* adjList[], int n) {
    for (int i = 0; i < n; i++) {
        Node* curr = adjList[i];
        while (curr != NULL) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        adjList[i] = NULL;
    }
}
