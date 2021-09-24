//
// Created by cb on 2021/9/24.
//

#include "algorithm"
#include "vector"
#include "string"
#include "map"
#include "unordered_map"
using namespace std;

struct DLinkNode{
    DLinkNode *prev, *next;
    int key, value;

    DLinkNode() : key(0), value(0), prev(nullptr), next(nullptr) {}

    DLinkNode(int key, int value) : key(key), value(value), prev(nullptr), next(nullptr){}

};

class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity), size(0){
        head = new DLinkNode();
        tail = new DLinkNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if(ma.count(key)){
            moveH(ma[key]);
            return ma[key]->value;
        }else {
            return -1;
        }
    }

    void put(int key, int value) {
        if(ma.count(key)){
            ma[key]->value = value;
            moveH(ma[key]);
        }else {
            DLinkNode *t = new DLinkNode(key, value);
            addH(t);
            ma[key] = t;
            size++;
            if(size > capacity){
                size--;
                auto *tt = tail->prev;
                ma.erase(tail->prev->key);
                deleteH(tail->prev);
                delete tt;
            }
        }
    }

    void moveH(DLinkNode *cur){
        deleteH(cur);
        addH(cur);
    }


    void addH(DLinkNode *cur){
        cur->next = head->next;
        head->next->prev = cur;
        cur->prev = head;
        head->next = cur;
    }

    void deleteH(DLinkNode *cur){
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
    }

private:
    DLinkNode *head, *tail;
    int capacity, size;
    unordered_map<int, DLinkNode*> ma;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */