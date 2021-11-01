#include "ex1.h"
void * aligned_malloc(unsigned int size, unsigned int align){
	void*p1,*p2;
	p1=(void*)malloc(size+align+sizeof(size_t));
	if(p1 == NULL) return NULL;
	size_t addr = (size_t)p1 + align +sizeof(size_t);	
	p2 = (void*)(addr - (addr%align));
	*((size_t*)p2-1) =(size_t)p1;
	return p2;

}

void* aligned_free(void *ptr){
	free((void *)(*((size_t *) ptr-1)));
}

