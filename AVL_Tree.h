template <class Key, class Value>
class AVLTree{

public:
    AVLTree(): root(nullptr){};

    AVLTree(const AVLTree& tree) = delete;

    AVLTree& operator=(const AVLTree& tree) = delete;

    ~AVLTree(){
        deleteNodes(root);
    }

    Value* find(const Key& key){
        Node *result = findNode(root, key);
        if(result == nullptr){
            return nullptr;
        }
        return &(result->value);
    }

    bool insert(const Key& key, const Value& value){
        if(find(key) != nullptr){
            return false;
        }
        root = insertNode(root, key, value);
        return true;
    }

    bool remove(const Key& key){
        if(find(key) == nullptr){
            return false;
        }
        root = removeNode(root, key);
        return true;
    }

private:
    struct Node {
        Key key;
        Value value;
        Node *left, *right;
        int height;
    };

    Node *root;

    int getHeight(Node *node) const {
        if(node == nullptr){
            return -1;
        }
        return node->height;
    }

    void updateHeight(Node *node){
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        node->height = ((leftHeight > rightHeight) ? leftHeight : rightHeight) + 1;
    }

    int calcBF(Node *node) const {
        if(node == nullptr){
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    Node* LLRotation(Node *root){
        Node *a = root->left;
        root->left = a->right;
        a->right = root;
        updateHeight(root);
        updateHeight(a);
        return a;
    }

    Node* RRRotation(Node *root){
        Node *a = root->right;
        root->right = a->left;
        a->left = root;
        updateHeight(root);
        updateHeight(a);
        return a;
    }

    Node* LRRotation(Node *root){
        Node *a = root->left;
        root->left = RRRotation(a);
        return LLRotation(root);
    }

    Node* RLRotation(Node *root){
        Node *a = root->right;
        root->right = LLRotation(a);
        return RRRotation(root);
    }

    Node* rebalanceTree(Node *root){
        int rootBF = calcBF(root);
        if(rootBF == 2){
            if(calcBF(root->left) > -1){
                return LLRotation(root);
            }else{
                return LRRotation(root);
            }
        }else if(rootBF == -2){
            if(calcBF(root->right) < 1){
                return RRRotation(root);
            }else{
                return RLRotation(root);
            }
        }
        return root;
    }

    void swapNodes(Node *root, Node *pivot, Node *pivotParent){
        Node *pivotRight = pivot->right;
        if(pivotParent == root){
            pivot->right = root;
        }else{
            pivotParent->left = root;
            pivot->right = root->right;
        }
        pivot->left = root->left;
        root->left = nullptr;
        root->right = pivotRight;
        int pivotHeight = pivot->height;
        pivot->height = root->height;
        root->height = pivotHeight;
    }

    Node* findNode(Node *node, const Key& key){
        if(node == nullptr || node->key == key){
            return node;
        }
        if(key < node->key){
            return findNode(node->left, key);
        }else{
            return findNode(node->right, key);
        }
    }

    Node* insertNode(Node *node, const Key& key, const Value& value){
        if(node == nullptr){
            return new Node{key, value, nullptr, nullptr, 0};
        }
        if(key < node->key){
            node->left = insertNode(node->left, key, value);
        }else if(key > node->key){
            node->right = insertNode(node->right, key, value);
        }
        updateHeight(node);
        return rebalanceTree(node);
    }

    Node* removeNode(Node *node, const Key& key){
        if(node == nullptr){
            return nullptr;
        }
        if(key < node->key){
            node->left = removeNode(node->left, key);
        }
        else if(key > node->key){
            node->right = removeNode(node->right, key);
        }
        else{
            if(node->left == nullptr){
                Node *child = node->right;
                delete node;
                return child;
            }
            if(node->right == nullptr){
                Node *child = node->left;
                delete node;
                return child;
            }
            Node *pivot = node->right, *pivotParent = node;
            while(pivot->left != nullptr){
                pivotParent = pivot;
                pivot = pivot->left;
            }
            swapNodes(node, pivot, pivotParent);
            node = pivot;
            node->right = removeNode(node->right, key);
        }
        updateHeight(node);
        return rebalanceTree(node);
    }

    void deleteNodes(Node *node){
        if(node != nullptr){
            deleteNodes(node->right);
            deleteNodes(node->left);
            delete node;
        }
    }
};