/*
 * tp33.c
 *
 *  Created on: 6 oct. 2014
 *      Author: Vincent
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<pthread.h>
#include<stdio.h>
typedef struct somma {
    int j;
    int tab[10];
}soma;
soma *soma_init(int ide){
	soma *p;
	p = malloc(sizeof(soma));
    p->j=ide;
    p->tab[p->j]=ide;
		     return p;
}
soma *modifier(soma*p1,soma*p2){
	p1->tab[p2->j]=p2->j;
	return p1;
}
int tabu(soma*p1,int l){
int i;
int s;
	for (i=0;i<l+1;i++){
		s=s+(p1->tab[i]);

}
	s=s-1;
	return s;
}




	void *hello(void *arg){
		static pthread_mutex_t  mutex = PTHREAD_MUTEX_INITIALIZER;

	int p;
		int *id=(int*)arg;

		pthread_mutex_lock(& mutex);

	    printf("%d:hello world et mon numero est %d\n",*id,p);
	    pthread_mutex_unlock(& mutex);

	    int i;




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
	    soma *p4=soma_init(j);
	  	   	    	soma *p5=soma_init(j-1);
	  	   	    	soma*p7=soma_init(j-2);
	  	   	    	soma*p8=soma_init(j-3);
	  	   	    	soma*p10=modifier(p4,p5);
	  	   	    	soma*p11=modifier(p10,p7);
	  	   	    	soma*p6=modifier(p11,p8);
	  	   	    	int k=tabu(p6,6);
	    for(i=0;i<j;i++){

			printf("Cree thread %d\n",i);
			pthread_create (&thread[i],NULL,hello,(void *)k);

	        pthread_join(thread[i],NULL);
		}

		pthread_exit(NULL);
	}
