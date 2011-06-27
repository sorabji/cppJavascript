#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;

/**
 * Node class: represents one Node in a linked list
 * @data members:
 *      data: data of the node
 *      *next: pointer to the next node, or NULL if last node in the list
 */
template<class T> class Node{
    public:
        T data;
        Node<T> *next;

        ~Node(){
            std::cout << "\t\tin node's destructor" << std::endl;
            delete data;
            std::cout << "\t\tdeleted a node" << std::endl;
        }
};

/**
 * LinkedList class: a linked list
 * @data members:
 *      *head: pointer to the first node, or NULL in an empty list
 */
template<class T> class LinkedList{
    private:

        void printData(Node<T>* n){
            cout << n->data << endl;
        }

    public:
        Node<T> *head;

        /**
         * default constructor
         */
        LinkedList(){
            head = NULL;
        }

        /**
         * standard destructor
         */
        //~LinkedList(){
            //Node<T> *temp = head,*current = head;
            //std::cout << "in linkedList's destructor" << std::endl;
//
            //while(current!=NULL){
                //current = current->next;
                //delete temp;
                //temp = current;
            //}
            //std::cout << "deleted linkedList" << std::endl;
        //}

        /**
         * more awesome destructor, recursion ftw
         */
        ~LinkedList(){
            int i = 1;
            std::cout << "in linkedList's destructor" << std::endl;
            deleteNode(head,i);
            std::cout << "deleted linkedList" << std::endl;
        }

        /**
         * function to delete a node...called recursively until a NULL pointer is found
         * int i is just there to see the pretty recursion in detail
         */
        void deleteNode(Node<T> *cur, int i){
            std::cout << "\tcall number: " << i << " to deleteNode()" << std::endl;
            if (!cur){
                std::cout << "\t\tNULL pointer found...popping off the stack" << std::endl;
                return;
            }
            i++;
            deleteNode(cur->next,i);
            i--;
            std::cout << "\tcall number: " << i << " came back" << std::endl;
            delete cur;
        }

        /**
         * adds a node to the beginning of the list
         * @param: 
         *      Node<T> *newNode: the node to be added
         */
        void addAtBeginning(Node<T> *newNode){
            newNode->next = head;
            head = newNode;
        }

        /**
         * adds a node to the end of the list
         * @param:
         *      Node<T> *newNode: the node to be added
         */
        void addAtEnd(Node<T> *newNode){
            if (head!=NULL){
                Node<T> *lastNode = findLastNode();
                newNode->next = lastNode->next;
                lastNode->next = newNode;
            }
            else{
                head = newNode;
                newNode->next = NULL;
            }
        }

        /**
         * finds and returns the last node in the list
         */
        Node<T> *findLastNode(){
            Node<T> *n = head, *lastNode;
            while(n){
                lastNode = n;
                n = n->next;
            }
            return lastNode;
        }

        /**
         * prints the contents of the linkedList
         */
        void print(Node<T>* np){
            if (!np) return;
            printData(np);
            print(np->next);

        }

};
#endif
