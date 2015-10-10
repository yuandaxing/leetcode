class Stack {
public:
    // Push element x onto stack.
  void push(int x) 
  {
    top_ = x;
    Q1.push_back(x);
  }

  // Removes the element on top of the stack.
  void pop() 
  {
    while (Q1.size() != 1)
    {
      top_ = Q1.front();
      Q2.push_back(Q1.front());
      Q1.pop_front(); 
    }
    Q1.pop_front();
    Q1.swap(Q2);
  }

  // Get the top element.
  int top() 
  {
	return top_;
  }

  // Return whether the stack is empty.
  bool empty() 
  {
    return Q1.empty();
  }
private:
  int top_;
  list<int> Q1;
  list<int> Q2;
};
