//
// Created by cb on 2021/9/13.
//

#include "queue"
#include "pair"
#include "vector"
using namespace std;


class AnimalShelf {
public:
    AnimalShelf() {

    }

    void enqueue(vector<int> animal) {
//        all.push(animal);
        if(animal[1] == 0)
            cat.push(animal);
        else dog.push(animal);
    }

    vector<int> dequeueAny() {
        if(cat.empty()&&dog.empty()) return err;
        if(cat.empty()) return dequeueDog();
        if(dog.empty()) return dequeueCat();
        if(dog.front()[0] < cat.front()[0]) return dequeueDog();
        else return dequeueCat();
    }

    vector<int> dequeueDog() {
        if(dog.empty()) return err;
        vector<int> tmp =  dog.front();
        dog.pop();
        return tmp;
    }

    vector<int> dequeueCat() {
        if(cat.empty()) return err;
        vector<int> tmp = cat.front();
        cat.pop();
        return tmp;
    }

private:
    queue<vector<int>> dog,cat;
    vector<int> err{-1,-1};
};

/**
 * Your AnimalShelf object will be instantiated and called as such:
 * AnimalShelf* obj = new AnimalShelf();
 * obj->enqueue(animal);
 * vector<int> param_2 = obj->dequeueAny();
 * vector<int> param_3 = obj->dequeueDog();
 * vector<int> param_4 = obj->dequeueCat();
 */