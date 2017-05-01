#ifndef LISTENTHREADPOOL_H
#define LISTENTHREADPOOL_H

#include<iostream>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<errno.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

#include<queue>
#include<Job.h>

#define LISTEN_QUEUE 5
#define THREAD_POOL_SIZE 1
#define BUFFER_SIZE 255


using namespace std;

class ListenThreadPool
{
    public:
        ListenThreadPool();
        virtual ~ListenThreadPool();
        static void *Manage(void *);

    protected:

    private:

};

#endif // LISTENTHREADPOOL_H
