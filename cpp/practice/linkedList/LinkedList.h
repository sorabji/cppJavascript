#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;

        Node(int d){
            data = d;
            next = NULL;
        }
};

class LinkedList{
    public:
        Node *head;


        LinkedList(){
            head = NULL;
        }

        void addAtBeginning(Node *newNode){
            newNode->next = head;
            head = newNode;
        }

        void addAtEnd(Node *newNode){
            if (head!=NULL){
                Node *lastNode = findLastNode();
                newNode->next = lastNode->next;
                lastNode->next = newNode;
            }
            else{
                head = newNode;
                newNode->next = NULL;
            }
        }

        Node *findLastNode(){
            Node *n = head, *lastNode;
            while(n){
                lastNode = n;
                n = n->next;
            }
            return lastNode;
        }

        void print(Node* np){
            if (!np) return;
            printData(np);
            print(np->next);

        }

        void printData(Node* n){
            cout << n->data << endl;
        }
};
#endif
