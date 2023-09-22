#include <iostream>
//#include "linked_list.h"
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

void LinkedList::push(int data){
    Node *node;
    node = new Node;
    node->data = data;
    node->next = root;
    this->root = node;
};
int LinkedList::pop(){

    Node *node =this-> root;
    this->root = node->next;
    int d = node->data;
    delete node;
    return d;
};
void LinkedListOfChar::pushc(std::string data){
    NodeChar *node;
    node = new NodeChar;
    node->data = data;
    node->next = root;
    this->root = node;
};
std::string LinkedListOfChar::popc(){

    NodeChar *node =this-> root;
    this->root = node->next;
    std::string d = node->data;
    delete node;
    return d;
};
bool LinkedListOfChar::isempty(){
    NodeChar *root;
    if (root==NULL){
        return true;
    }
    else{return false;}
};


int main()
{
   // LinkedList * ll = new LinkedList;
   // ll->push(5);
    //ll->push(10);
    //std::cout << ll->pop() << std::endl;
    //std::cout << ll->pop() << std::endl;
    //return 0;
    std::string c;
    LinkedListOfChar *llsum = new LinkedListOfChar;
    LinkedListOfChar *llc = new LinkedListOfChar;
    while (c != "="){
        std::cin>>c;
        if (c == "("){
            llc->pushc(c);   
        }else if (c == ")"){
            std::string el;
            while(el != "("){
                el =llc-> popc();
                llsum ->pushc(el);
            }

        }else if (c == "+"){
            std::string el = llc->popc();
            if ((llc->isempty() == true) or (el == "(") ){
                llc->pushc(el);
                llc->pushc(c);
            }
            else if ((el == "-") or (el == "+") or (el == "*") or (el == "/")){
                while ((llc->isempty() == true) or (el == "-") or (el == "+") or (el == "*") or (el == "/") ){
                    llsum ->pushc(el);
                    if (llc->isempty() == false){
                    el = llc->popc();}
                }
            std::cout<<"push +"<<std::endl;
        }else if (c == "-"){
            std::string el = llc->popc();
            if ((llc->isempty() == true) or (el == "(") ){
                llc->pushc(el);
                llc->pushc(c);}
            else if ((el == "-") or (el == "+") or (el == "*") or (el == "/")){
                while ((llc->isempty() == true) or (el == "-") or (el == "+") or (el == "*") or (el == "/") ){
                    llsum ->pushc(el);
                    if (llc->isempty() == false){
                    el = llc->popc();}
                }
            }    
            //std::cout<<"push -"<<std::endl;
        }else if (c == "*"){
            std::string el = llc->popc();
            if ((llc->isempty() == true) or (el == "(") or (el == "+") or (el == "-") ){
                llc->pushc(el);
                llc->pushc(c);}


           // std::cout<<"push *"<<std::endl;
        }else if (c == "/"){
            std::string el = llc->popc();
            if ((llc->isempty() == true) or (el == "(") or (el == "+") or (el == "-") ){
                llc->pushc(el);
                llc->pushc(c);}
          // std::cout<<"push /"<<std::endl;
        }else{
            llsum ->pushc(c);
        }
    

    }
}
while (llc->isempty() == false) {
    std::cout<<llsum->popc()<<" ";

}
}   


