
#ifndef INT_STACK_H_
#define INT_STACK_H_
#include <pthread.h>

struct Node
{
   int value = 0;
   Node* next = nullptr;
};

class IntStack
{
public:
   IntStack();
   bool Pop(int &val);
   bool Push(int val);
   
private:
   Node* head_ = nullptr;
   pthread_mutex_t stack_lock_;
};
#endif
