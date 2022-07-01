/*
 *@File Name          :alternate_printing.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/6/16 10:14
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "condition_variable"
#include "iostream"
#include "mutex"
#include "thread"

class AlternatePrinting {
 public:
  AlternatePrinting() : num_(0) {}

  void print_odd() {
    while (1) {
      std::unique_lock<std::mutex> lock(mtx_);
      cond_.wait(lock, [&] { return this->num_ % 2 == 0; });
      std::cout << "thread: " << std::this_thread::get_id() << "   printf: " << num_ << std::endl;
      ++num_;
      cond_.notify_one();
      if (this->num_ > 100) break;
    }
  }

  void print_even() {
    while (1) {
      std::unique_lock<std::mutex> lock(mtx_);
      cond_.wait(lock, [&] { return this->num_ % 2 == 1; });
      std::cout << "thread: " << std::this_thread::get_id() << "   printf: " << num_ << std::endl;
      ++num_;
      cond_.notify_one();
      if (this->num_ > 100) break;
    }
  }

  void start() {
    std::thread o(&AlternatePrinting::print_odd, this);
    std::thread e(&AlternatePrinting::print_even, this);
    o.join();
    e.join();
  }

 private:
  std::mutex              mtx_;
  std::condition_variable cond_;
  int                     num_;
};

int main() {
  AlternatePrinting a;
  a.start();
  return 0;
}