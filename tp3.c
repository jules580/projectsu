/*
 * tp3.c
 *
 *  Created on: 2 oct. 2014
 *      Author: Vincent
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<pthread.h>
#include<stdio.h>
void *hello(void *arg){
	int *id=(int*)arg;
    printf("%d:hello world\n",*id);
    printf("mon pid est %d\n",getpid());
    printf("%p\n", (void *) pthread_self());
pthread_exit(NULL);
}
int main( int argc,char *argv[]){
	pthread_t thread[3];
    
	int j=atoi(argv[1]);
    int i;
    int id[j];
    
    for(i=1;i<j+1;i++){
        id[i]=i;
    }
    for(i=1;i<j+1;i++){
		printf("Cree thread %d\n",i);
		pthread_create (&thread[i],NULL,hello,(void *)&id[i]);
        pthread_join(thread[i],NULL);
	}
	pthread_exit(NULL);
}
