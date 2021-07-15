


namespace graph {

class myGraph {
    private:
    int num_verts;
    myVector<int> * adjacent;

    void DFSRec(int curr_vert, mySet<int> &visited) {
        visited.add(curr_vert);
        printf("%d ", curr_vert);
        for(int i = 0; i < adjacent[curr_vert].size(); ++i) {
            if(!visited.contains(adjacent[curr_vert].at(i))) {
                DFSRec(adjacent[curr_vert].at(i), visited);
            }
        }
    }

    public:
    myGraph(int verts) : num_verts(verts), adjacent(new myVector<int>[verts]) {
    }
    ~myGraph() {
        delete[] adjacent;
    }

    void addEdge(int v1, int v2) {
        adjacent[v1].push(v2);
        adjacent[v2].push(v1);
    }

    void print() {
        for(int i = 0; i < num_verts; ++i) {
            printf("Index %d = ", i);
            for(int j = 0; j < adjacent[i].size(); ++j) {
                printf("%d ", adjacent[i].at(j));
            }
            printf("\n");
        }
    }

    void BFS(int start_vert) {
        mySet<int> visit(num_verts);
        visit.add(start_vert);
        myQueue<int> q;
        q.push(start_vert);
        printf("BFS: ");

        while(q.size() != 0) {
            int curr_vert = q.pop();
            printf("%d ", curr_vert);
            for(int i = 0; i < adjacent[curr_vert].size(); i++) {
                if(!visit.contains(adjacent[curr_vert].at(i))) {
                    q.push(adjacent[curr_vert].at(i));
                    visit.add(adjacent[curr_vert].at(i));
                }
            }
        }
        printf("\n");
    }

    void DFS(int start_vert) {
        mySet<int> visit(num_verts);
        printf("DFS: ");
        DFSRec(start_vert, visit);
        printf("\n");
    }
};

};
