#include <list>
using std::list;
class Queue
{
private:
  list<int> queue_;
public:
  // Push element x to the back of queue.
  void push(int x)
  {
    queue_.push_back(x);
  }

  // Removes the element from in front of queue.
  void pop(void)
  {
    queue_.pop_front();
  }

  // Get the front element.
  int peek(void)
  {
    return queue_.front();
  }

  // Return whether the queue is empty.
  bool empty(void)
  {
    return queue_.empty();
  }
};
