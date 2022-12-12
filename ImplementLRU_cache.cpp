#include<bits/stdc++.h>
using namespace std;

class LRU{
    public:
        class Node{
            public:
                int key;
                int val;
                Node* next;
                Node* prev;
                Node(int key, int val){
                    this->key = key;
                    this->val = val;
                }
        };

        unordered_map<int, Node*> mp;
        int capacity;
        Node* head = new Node(0, 0);

        LRU(int size){

        }

        int get(int key){

        }

        void push(int key, int val){

        }
};