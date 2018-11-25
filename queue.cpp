#include <iostream>
using namespace std;
struct TreeNode{
	int value;
	TreeNode *left;
	TreeNode *right;
};
class queue
{
private:
  struct QueueNode
  {
    TreeNode* value;
    QueueNode *next;
  };
  QueueNode *front;
  QueueNode *rear;
  int numItems;
public:
  queue( );
  ~queue( );
  void enqueue(TreeNode * num);
  TreeNode *dequeue( );
  bool isEmpty( );
  void clear( );
  void printQ();
};
queue::queue()
{
  front = NULL;
  rear = NULL;
  numItems = 0;
}
queue::~queue()
{
  clear();
}
void queue::enqueue(TreeNode* num)
{
  QueueNode * newNode;
  newNode = new QueueNode;
  newNode->value = num;
  TreeNode * x = newNode->value;
  newNode->next = NULL;
  if (isEmpty()) {
    front = newNode;
    rear = newNode;
  }
  else
  {
    rear->next = newNode;
    rear = newNode;
  }
  numItems++;
}
TreeNode *queue::dequeue()
{
  QueueNode * temp;
  TreeNode* num;
  if (isEmpty()) {
    std::cout << "the queue is empty" << '\n';
  }
  else
  {
    num = front->value;
    temp = front->next;
    if (front == rear) {
      rear = temp;
    }
    delete front;
    front = temp;
    numItems--;
  }
  return num;
}
bool queue::isEmpty()
{
  if (numItems == 0) {
    return true;
  }
  return false;
}
void queue::clear()
{
  while (!isEmpty()) {
    dequeue();
  }
}

// int main()
// {
//   queue Q1;
// for (size_t i = 0; i < 5; i++) {
//   Q1.enqueue(i);
//   std::cout << "enqueed "<< i << '\n';
// }
// std::cout << "print the elements in queue" << '\n';
// while (!Q1.isEmpty()) {
//   int num = Q1.dequeue();
//   std::cout << "num is "<<num << '\n';
// }
//   return 1;
// }
