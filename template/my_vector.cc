/*
 *@File Name          :my_vector.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/4/23 9:23
 *@Description        :
 *@Function List      :
 *@History            :
 */
#include "iostream"
#include "algorithm"

using namespace std;

template<typename T>
class MyVector {
private:
    T *nums;
    const int MIN_CAP = 16;
    const double INCREASE = 1.5;
    int cap;
    int size;
public:
    MyVector(int new_cap = 0) {
        nums = new T[MIN_CAP + new_cap];
        cap = MIN_CAP + new_cap;
        size = 0;
    }

    MyVector(int newCap, T *data) {
        cap = newCap + MIN_CAP;
        nums = new T[cap];
        size = newCap;
        for (int i = 0; i < size; i++) {
            nums[i] = data[i];
        }
    }

    MyVector(const MyVector &vec) {
        delete[] nums;
        cap = vec.cap;
        size = vec.size;
        nums = new T[cap];
        for (int i = 0; i < size; i++)
            nums[i] = vec.nums[i];
    }

    ~MyVector() {
        delete[] nums;
    }

    void push_back(T val) {
        if (size == cap) {
            T *tmp = nums;
            nums = new T[int(cap * INCREASE)];
            for (int i = 0; i < cap; i++) {
                nums[i] = tmp[i];
            }
            cap = int(cap * INCREASE);
            delete[]tmp;
        }
        nums[size++] = val;
    }

    T &operator[](const int &idx) {
        if (idx >= size) {
            try {
                throw "error";
            }
            catch (const char *c) {
                cout << c << endl;
            }
        }
        return nums[idx];
    }
};

int main() {
    MyVector<int> vec(5);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec[3] = 4;
    for (int i = 0; i < 4; i++)
        cout << vec[i] << endl;
    return 0;
}