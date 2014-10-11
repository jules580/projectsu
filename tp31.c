
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<pthread.h>
#include<stdio.h>
void *hello(void *arg){
	static pthread_mutex_t  mutex = PTHREAD_MUTEX_INITIALIZER;

int p;
	int *id=(int*)arg;
int somme[5];
	p=1000000*(*id);
	pthread_mutex_lock(& mutex);

    printf("%d:hello world et mon numero est %d\n",*id,p);
    pthread_mutex_unlock(& mutex);
    somme[*id]=p;
    int i;
    int s;
    for(i=0;i<*id+1;i++){
    	s=s+somme[*id];
    }
printf("somme en cours:%d\n",s/2);
    printf("mon pid est %d\n",getpid());
    printf("%p\n", (void *) pthread_self());


pthread_exit(NULL);
}
int main( int argc,char *argv[]){

	pthread_t thread[3];

	int j=atoi(argv[1]);
    int i;
    int id[j];

    for(i=0;i<j;i++){
        id[i]=i;
    }

    for(i=0;i<j;i++){

		printf("Cree thread %d\n",i);
		pthread_create (&thread[i],NULL,hello,(void *)&id[i]);

        pthread_join(thread[i],NULL);
	}

	pthread_exit(NULL);
}
/*
 * tp31.c
 *
 *  Created on: 2 oct. 2014
 *      Author: Vincent
 */

