struct Node{
    int data;
    Node *next;
};
struct LinkedList{
    Node *root;
    void push(int data);
    int pop();
};
struct NodeChar{
    std::string data;
    NodeChar *next;
};
struct LinkedListOfChar{
    NodeChar *root;
    void pushc(std::string data);
    std::string popc();
    bool isempty();
};

