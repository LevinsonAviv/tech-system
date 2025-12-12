template <class Key, class Value>
class AVLTree{

public:
    AVLTree(): root(nullptr){};

    AVLTree(const AVLTree& tree) = delete;

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

    void insert(const Key& key, const Value& value){
        root = insertNode(root, key, value);
    }

    void remove(const Key& key){
        deleteNode(root, key);
    }

private:
    struct Node {
        Key key;
        Value value;
        Node *left, *right;
    };
    
    Node *root;

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
            return new Node{key, value, nullptr, nullptr};
        }
        if(key < node->key){
            node->left = insertNode(node->left, key, value);
        }else if(key > node->key){
            node->right = insertNode(node->right, key, value);
        }
        return node;
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
                pivot = pivot->left;
                if(pivotParent == node){
                    pivotParent = pivotParent->right;
                }else{
                    pivotParent = pivotParent->left;
                }
            }
            if(pivotParent != node){
                pivotParent->left = pivot->right;
                pivot->right = node->right;
            }
            pivot->left = node->left;
            delete node;
            return pivot;
        }
        return node;
    }

    void deleteNodes(Node *node){
        if(node != nullptr){
            deleteNodes(node->right);
            deleteNodes(node->left);
            delete node;
        }
    }
};