#include <stdio.h>
#include <stdlib.h>
#define INIT_SIZE 80
#define INCREMENT 10

typedef struct{
    int * elem;
    int listLength;
    int listSize;
}list;

int list_init(list *l){
    (*l).elem = (int *)malloc(INIT_SIZE * sizeof(int));
    if(!(*l).elem)
        return 0;
    (*l).listLength = 0;
    (*l).listSize = INIT_SIZE;
    return 1;
}

int listInsert(list *l,int e){
    int *q = &((*l).elem[(*l).listLength-1]);
    while(1){
        if(e < *q){
            *(q+1) = *q;
        }else if(q == (*l).elem){
            *((*l).elem) = e;
        }else{
            *(q+1) = e;
            (*l).listLength++;
            break;
        }
        q--;
    }

}

int main(){
    list l;
    list_init(&l);
    int e = 20,b;
    int a[80] = {1,5,12,15,19,21,23,26,45,55,65,76};
    l.elem = a;
    l.listLength = 12;
    for(b = 0;b<=l.listLength-1;b++){
        printf("%d  ",l.elem[b]);
    }
    listInsert(&l,e);
    printf("\n");
    for(b = 0;b<=l.listLength-1;b++){
        printf("%d  ",l.elem[b]);
    }
    return 0;
}
