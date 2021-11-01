#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <pthread.h>

int totalPoints = 0;
int wanted = 0;

void* count(void* param){
	int i, upper =atoi(param);
	for(i = 0;i < upper; i++){
		double x = (double)rand() / RAND_MAX;
		double y = (double)rand() / RAND_MAX;
		if( ((x*x)+(y*y)) <= 1) totalPoints++;
	}
	return NULL;
	pthread_exit(0);
}

int main(int argc,char *argv[]){
	wanted = atoi(argv[1]);
	//threading
	pthread_t thread;
	pthread_create(&thread, NULL, &count, argv[1]);
	pthread_join(thread,NULL);
	//calculating pi
	double points = 4.0 * totalPoints;
	double pi = points/ wanted;
	//pi
	printf("pi_multi-thread value = %f\n",pi);
	return 0;	

}
