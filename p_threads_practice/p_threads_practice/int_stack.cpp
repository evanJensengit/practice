
#include "int_stack.h"

IntStack::IntStack()
{
   pthread_mutex_init(&stack_lock_, NULL);
}

bool IntStack::Pop(int &val)
{
   pthread_mutex_lock(&stack_lock_);
   if (head_ == nullptr)
   {
      pthread_mutex_unlock(&stack_lock_);
      return false;
   }
   else
   {
      Node *temp = head_;
      val = temp->value;
      head_ = head_->next;
      pthread_mutex_unlock(&stack_lock_);
      delete temp;
      return true;
   }
}

bool IntStack::Push(int val)
{
   Node* insNode = new Node;
   insNode->value = val;
   pthread_mutex_lock(&stack_lock_);
   insNode->next = head_;
   head_ = insNode;
   pthread_mutex_unlock(&stack_lock_);
   return true;
}

