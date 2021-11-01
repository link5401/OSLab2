#include "ex1.h"

int main(int argc, char *argv[]){
	void* p1 = aligned_malloc(16,64);
	printf("%p\n",p1);
	aligned_free(p1);
}
