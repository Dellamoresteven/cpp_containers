
namespace binaryTree {
    struct node {
        node(int data) : data(data), left(NULL), right(NULL) {
        }
        int data;
        node * left;
        node * right;
    };

    class myBinaryTree {
        private:
        node * root;

        void add(const int& key, node * curr_node) {
            if(key < curr_node->data) {
                if(curr_node->left != NULL) {
                    add(key, curr_node->left);
                } else {
                    curr_node->left = new node(key);
                }
            } else {
                if(curr_node->right != NULL) {
                    add(key, curr_node->right);
                } else {
                    curr_node->right = new node(key);
                }
            }
        }

        node * find(int key, node * curr_node) {
            if(curr_node != NULL) {
                if(curr_node->data == key) {
                    return curr_node;
                } else if(key >= curr_node->data) {
                    printf("right\n");
                    find(key, curr_node->right);
                } else if(key < curr_node->data) {
                    printf("left\n");
                    find(key, curr_node->left);
                } else {
                    throw "What in the world";
                }
            }
            return NULL;
        }

        void getInOrderNodes(node * curr_node, myVector<node*> &nodes) {
            if(curr_node == NULL)
                return;
            getInOrderNodes(curr_node->left, nodes);
            nodes.push(curr_node);
            getInOrderNodes(curr_node->right, nodes);
        }

        node * buildNewTree(myVector<node*> &inOrderNodes, int start, int end) {
            if(start > end)
                return NULL;
            int midPoint = (start + end)/2;
            node * curr_node = inOrderNodes.at(midPoint);
            curr_node->left = buildNewTree(inOrderNodes, start, midPoint-1);
            curr_node->right = buildNewTree(inOrderNodes, midPoint+1, end);
        }

        //inline void free_memory(int key, node * curr_node) {
        //}

        public:
        myBinaryTree() : root(NULL) {
        }

        ~myBinaryTree() {
        }

        void add(int key) {
            if(root != NULL) {
                add(key, root);
            } else {
                root = new node(key);
            }
        }

        node * find(int key) {
            return find(key, root);
        }

        void balance_tree() {
            myVector<node*> inOrderNodes;
            getInOrderNodes(root, inOrderNodes);
            root = buildNewTree(inOrderNodes, 0, inOrderNodes.size()-1);
        }

        void print() {
            myVector<node*> inOrderNodes;
            getInOrderNodes(root, inOrderNodes);
            printf("inOrder: ");
            for(int i = 0; i < inOrderNodes.size(); i++) {
                printf("%d ", inOrderNodes.at(i)->data);
            }
            printf("\n");
        }
    };
}
