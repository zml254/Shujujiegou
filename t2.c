#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INIT_SIZE 50

typedef struct{
    char *elem;
    int length;
    char *same;
    char *elemc;
}List;

int list_init(List *l){
    (*l).elem = (char *)malloc(INIT_SIZE*sizeof(char));
    (*l).same = (char *)malloc(INIT_SIZE*sizeof(char));
    (*l).elemc = (char *)malloc(INIT_SIZE*sizeof(char));
    if(!(*l).elem)
        return 0;
    (*l).length = 0;
    return 1;
}

int list_compare(List *l1,List *l2){
    int b,d,e,f;
    int c,c2;
    c = (*l1).length;
    c2 = (*l2).length;
    f = c<c2?c:c2;
    for(b = 0 ;b < f; b++){
        if((*l1).elem[b] == (*l2).elem[b]){
            (*l1).same[b] = (*l1).elem[b];
            (*l2).same[b] = (*l1).elem[b];
        }else {
            break;
        }
    }
    (*l1).same[b] = '\0';
    (*l2).same[b] = '\0';
    if(b==c&&b==c2){
        (*l1).elemc = '\0';
        (*l2).elemc = '\0';
        return 0;
    }
    e = b;
    if((*l1).elem[b] > (*l2).elem[b]){
        for(d = 0;b < (*l1).length;b++,d++){
            (*l1).elemc[d] = (*l1).elem[b];
        }
        (*l1).elemc[d] = '\0';
        for(d = 0;e < (*l2).length;e++,d++){
            (*l2).elemc[d] = (*l2).elem[e];
        }
        (*l2).elemc[d] = '\0';
        return -1;
    }else if((*l1).elem[b] < (*l2).elem[b]){
        for(d = 0;b < (*l1).length;b++,d++){
            (*l1).elemc[d] = (*l1).elem[b];
        }
        (*l1).elemc[d] = '\0';
        for(d = 0;e < (*l2).length;e++,d++){
            (*l2).elemc[d] = (*l2).elem[e];
        }
        (*l2).elemc[d] = '\0';
        return 1;
    }
    return 2;
}

int main()
{
    int a = 2;
    List l1,l2;
    list_init(&l1);
    list_init(&l2);
    l1.elem = "holle";
    l1.length = strlen(l1.elem);
    l2.elem = "holl";
    l2.length = strlen(l2.elem);
    a = list_compare(&l1,&l2);
    if(a == -1){
        printf("A<B\n");
    }else if(a == 1){
        printf("A>B\n");
    }else if(a == 0){
        printf("A=B\n");
    }
    printf("A=%s\n",l1.elem);
    printf("A\'=%s\n",l1.elemc);
    printf("B=%s\n",l2.elem);
    printf("B\'=%s\n",l2.elemc);
    printf("A*B=%s\n",l1.same);
    return 0;
}
