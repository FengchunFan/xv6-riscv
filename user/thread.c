#include "thread.h"

//routine must allocate a user stack of PGSIZE bytes, and call clone() to create a child thread
int thread_create(void *(start_routine)(void*), void *arg){}

//the following functions all in reference to corresponding functions in spinlock.c
void lock_init(struct lock_t* lock){
    lock -> locked = 0; //unlock
}

void lock_acquire(struct lock_t* lock){
    while(__sync_lock_test_and_set(&lock->locked, 1) != 0)
        ;
    __sync_synchronize();
}

void lock_release(struct lock_t* lock){
    __sync_synchronize();
    __sync_lock_release(&lock->locked);
}
