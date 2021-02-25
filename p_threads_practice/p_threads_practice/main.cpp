#include <iostream>
#include "int_stack.h"
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
using namespace std;

void *excercise_stack(void *);
const int kNumPushPops = 30;
const int kNumWorkers = 5;

int main()
{
   pthread_t workers[kNumWorkers];
   
   for (int i = 0; i < kNumWorkers; i++)
   {
      int id = i + 1;
      pthread_create(&workers[i], NULL, excercise_stack, (void *)& id);
      usleep(100000);
   }
   
   cout << "Multi-threaded Stack Running" << endl;
   
   for (int i = 0; i < kNumWorkers; i++)
   {
      pthread_join(workers[i], NULL);
   }
   cout << "Finished!" << endl;
   
}

void* excercise_stack(void* arg)
{
   IntStack st;
   int value;
   int id = *(int *) arg;
   
   for (int i = 0; i < kNumPushPops; i++)
   {
      value = rand();
      st.Push(value);
      usleep(id * 100000);
      st.Pop(value);
      cout << id << ": " << value << endl;
   }
   return nullptr;
}
