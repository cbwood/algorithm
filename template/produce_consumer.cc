/*
 *@File Name          :produce_consumer.cc
 *@Author             :cc
 *@Version            :1.0.0
 *@Date               :2022/6/16 9:26
 *@Description        :
 *@Function List      :
 *@History            :
 */

#include "condition_variable"
#include "iostream"
#include "mutex"
#include "queue"
#include "thread"

class ProducerAndConsumer {
 public:
  explicit ProducerAndConsumer(int num = 10) : num_(num), cnt_(0), consumer_finish_(false) {}

  void producer() {
    for (int i = 0; i < num_; i++) {
      std::unique_lock<std::mutex> lock(mtx_);
      while (que_.size() == 3) {
        std::cout << "Producer is waiting for an empty slot..." << std::endl;
        que_not_full_.wait(lock);
      }
      que_.push(i);
      std::cout << "produce: " << i << std::endl;
      que_not_empty_.notify_all();
    }
  }

  void consumer() {
    while (true) {
      std::unique_lock<std::mutex> lock(mtx_);
      if (consumer_finish_) break;
      while (que_.empty()) {
        std::cout << "Consumer is waiting for items..." << std::endl;
        que_not_empty_.wait(lock);
        if (consumer_finish_) break;
      }
      int x = que_.front();
      cnt_++;
      que_.pop();
      std::cout << "consumer: " << x << std::endl;
      que_not_full_.notify_all();
      if (cnt_ == num_ * 3) consumer_finish_ = true;
    }
  }

  void start() {
    std::thread p1(&ProducerAndConsumer::producer, this);
    std::thread p2(&ProducerAndConsumer::producer, this);
    std::thread p3(&ProducerAndConsumer::producer, this);
    std::thread c1(&ProducerAndConsumer::consumer, this);
    std::thread c2(&ProducerAndConsumer::consumer, this);
    std::thread c3(&ProducerAndConsumer::consumer, this);
    p1.join();
    p2.join();
    p3.join();
    c1.join();
    c2.join();
    c3.join();
  }

 private:
  std::queue<int>         que_;
  std::mutex              mtx_;
  std::condition_variable que_not_full_;
  std::condition_variable que_not_empty_;
  int                     num_;
  int                     cnt_;
  bool                    producer_finish_;
  bool                    consumer_finish_;
};

int main() {
  ProducerAndConsumer pc(10);
  pc.start();
  return 0;
}