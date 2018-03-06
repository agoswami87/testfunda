#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct node{
  int data;
  struct node *nextNodePtr;
};
//This class when invoked will return a head pointer 
//
class cs_stack{
private:
    int size;
    struct node* headPtr;
    struct node* createNode();
    
    struct node* appendNodeAtFront(); //Add a node at start
  
public:
    //void push(void *);
    void push(int size);
    void *pop();
    cs_stack();
};

struct node* cs_stack::createNode(){
  cout << "creating a node" <<endl;
  return (struct node*)malloc(sizeof(struct node));
}
cs_stack::cs_stack(){
 //create a stack having size number of nodes i.e. of "size"
  headPtr=NULL;
}
/*
cs_stack::cs_stack(void *size){
 //create a stack having size number of nodes i.e. of "size"
}
*/
void cs_stack::push(int value){
 //create a stack having size number of nodes i.e. of "size"
  struct node* tmpNode = createNode();
  tmpNode->data = value;
  tmpNode->nextNodePtr = headPtr;
    headPtr = tmpNode;
}
 //
int main(){
  cs_stack *tmp_stk = new cs_stack();
  cout << "Insert an element" <<endl;
  int i;
  cin >> i; 
  tmp_stk->push(i);
}
