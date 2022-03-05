#include "algorithm"
#include "iostream"

using namespace std;

template<typename T>
class shared_p {
private:
    unsigned int *count;
    T *ptr;
public:
    shared_p(T *p) : ptr(p), count(new unsigned int(1)) {}

    shared_p(const shared_p<T> &p) : ptr(p.ptr), count(p.count) {
        (*count)++;
    }

    shared_p(const T *p) : ptr(p), count(new unsigned int(1)) {}

    ~shared_p() {
        if (count != nullptr && --(*count) == 0) {
            delete count;
            delete ptr;
        }
    }

    unsigned int getCount() {
        return *(this->count);
    }

    shared_p<T> &operator=(const shared_p &p) {
        if (this == &p)
            return *this;
        if (count != nullptr && --(*count) == 0) {
            delete count;
            delete ptr;
        }
        (*p.count)++;

        ptr = p.ptr;
        count = p.count;
        return *this;
    }

    T &operator*() {
        return *(this->ptr);
    }

    T *operator->() {
        return this->ptr;
    }
};

int main() {
    shared_p<string> p1(new string("hellow shared_ptr"));
    cout << p1.getCount() << endl;
    shared_p<string> p2(p1);
    cout << p1.getCount() << " " << p2.getCount() << endl;
    return 0;
}