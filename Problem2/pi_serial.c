#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int totalPoints = 0;
int wanted = 0;
void* count(void * param){
	int i, upper = atoi(param);
	for(i = 0;i < upper; i++){
		double x = (double)rand() / RAND_MAX;
		double y = (double)rand() / RAND_MAX;
		if( ((x*x)+(y*y)) <= 1) totalPoints++;
	}
	return NULL;

}

int main(int argc, char* argv[]){

	count(argv[1]);
	wanted = atoi(argv[1]);

	double points = 4.0 * totalPoints;
	double pi = points/wanted;

	printf("serial_pi value: %f\n", pi);
}
