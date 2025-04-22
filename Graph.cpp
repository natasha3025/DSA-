using namespace std; 
 
class Queue { 
public: 
    int front, rear; 
    int q[20]; 
 
    Queue() { 
        front = 0; 
        rear = 0; 
    } 
 
    void insert(int key) { 
        if (rear < 20) { 
            q[rear++] = key; 
        } else { 
            cout << "Queue is full!\n"; 
        } 
    } 
 
    int Delete() { 
        if (front != rear) { 
            return q[front++]; 
        } else { 
            cout << "Queue is empty!\n"; 
            return -1; 
        } 
    } 
 
    bool isEmpty() { 
        return front == rear; 
    } 
}; 
 
class Stack { 
public: 
    int top; 
    int s[20]; 
 
    Stack() { 
46 
 
        top = -1; 
    } 
 
    void push(int key) { 
        if (top < 19) { 
            s[++top] = key; 
        } else { 
            cout << "Stack is full!\n"; 
        } 
    } 
 
    int pop() { 
        if (top >= 0) { 
            return s[top--]; 
        } else { 
            cout << "Stack is empty!\n"; 
            return -1; 
        } 
    } 
 
    bool isEmpty() { 
        return top == -1; 
    } 
}; 
 
class Graph { 
public: 
    int vcnt; 
    int a[20][20]; 
    int visited[20]; 
 
    Graph() { 
        vcnt = 0; 
        for (int i = 0; i < 20; i++) visited[i] = 0; 
    } 
 
    void adjmatrix(); 
    void disadjmatrix(); 
    void BFS(); 
    void DFS(); 
}; 
 
void Graph::adjmatrix() { 
    cout << "Enter the number of vertices: "; 
    cin >> vcnt; 
    cout << "Enter the adjacency matrix:\n"; 
    for (int i = 0; i < vcnt; i++) { 
        for (int j = 0; j < vcnt; j++) { 
            cin >> a[i][j]; 
        } 
    } 
47 
 
} 
 
void Graph::disadjmatrix() { 
    cout << "The adjacency matrix is:\n"; 
    for (int i = 0; i < vcnt; i++) { 
        for (int j = 0; j < vcnt; j++) { 
            cout << a[i][j] << " "; 
        } 
        cout << "\n"; 
    } 
} 
 
void Graph::BFS() { 
    int sv; 
    cout << "Enter start vertex (0 to " << vcnt - 1 << "): "; 
    cin >> sv; 
 
    for (int i = 0; i < vcnt; i++) visited[i] = 0; 
 
    Queue Q; 
    Q.insert(sv); 
    visited[sv] = 1; 
 
    cout << "BFS: "; 
    while (!Q.isEmpty()) { 
        int curr = Q.Delete(); 
        if (curr == -1) break; 
        cout << curr << " "; 
 
        for (int i = 0; i < vcnt; i++) { 
            if (a[curr][i] == 1 && !visited[i]) { 
                Q.insert(i); 
                visited[i] = 1; 
            } 
        } 
    } 
    cout << endl; 
} 
 
void Graph::DFS() { 
    int sv; 
    cout << "Enter start vertex (0 to " << vcnt - 1 << "): "; 
    cin >> sv; 
 
    for (int i = 0; i < vcnt; i++) visited[i] = 0; 
 
    Stack S; 
    S.push(sv); 
    visited[sv] = 1; 
 
    cout << "DFS: "; 
48 
 
    while (!S.isEmpty()) { 
        int curr = S.pop(); 
        if (curr == -1) break; 
        cout << curr << " "; 
 
        for (int i = vcnt - 1; i >= 0; i--) { 
            if (a[curr][i] == 1 && !visited[i]) { 
                S.push(i); 
                visited[i] = 1; 
            } 
        } 
    } 
    cout << endl; 
} 
 
int main() { 
    Graph g; 
    int choice; 
 
    do { 
        cout << "\n---------- MENU ----------\n"; 
        cout << "1. Enter the adjacency matrix\n"; 
        cout << "2. Display the adjacency matrix\n"; 
        cout << "3. BFS\n"; 
        cout << "4. DFS\n"; 
        cout << "5. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 
 
        switch (choice) { 
            case 1: g.adjmatrix(); break; 
            case 2: g.disadjmatrix(); break; 
            case 3: g.BFS(); break; 
            case 4: g.DFS(); break; 
            case 5: cout << "Thank you!\n"; break; 
            default: cout << "Invalid input!\n"; break; 
        } 
    } while (choice != 5); 
 
    return 0; 
}
