class LRUCache {
public:
    class Node {
    public:
        int key, val;
        Node *next, *prev;

        Node(int _key, int _val) {
            key = _key;
            val = _val;
            next = nullptr;
            prev = nullptr;
        }
    };

    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    int cap;
    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node *newNode) {
        Node *temp = head->next;

        newNode->next = temp;
        newNode->prev = head;

        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(Node *delNode) {
        Node *delPrev = delNode->prev;
        Node *delNext = delNode->next;

        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        Node *resNode = mp[key];
        int ans = resNode->val;

        deleteNode(resNode);
        addNode(resNode);

        mp[key] = head->next;

        return ans;
    }

    void put(int key, int value) {

        if (mp.find(key) != mp.end()) {
            Node *existingNode = mp[key];
            deleteNode(existingNode);
            mp.erase(key);
        }

        if (mp.size() == cap) {
            Node *lru = tail->prev;
            mp.erase(lru->key);
            deleteNode(lru);
        }

        Node *newNode = new Node(key, value);
        addNode(newNode);
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */