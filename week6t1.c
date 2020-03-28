#include <stdio.h>
#include <stdlib.h>

typedef struct LNode{
    int elem;
    struct LNode *next;
    int length;
}LNode,*LinkedList;

LinkedList initList(LinkedList l1){
    LinkedList l2 = (LinkedList) malloc(sizeof(LNode));
    l1 = l2;
    return l1;
}

LinkedList mergeList(LinkedList l1, LinkedList l2) {
    int i;
    LinkedList l3 = NULL;
    int length = l1->length + l2->length;
    if (l1->length > l2->length) {
        l3 = l2;
        for (i = 0; i < l2->length; i++) {
            l3 = l3->next;
        }
        l3->next = l1->next;
        l2->length = length;
        return l2;
    } else {
        l3 = l1;
        for (i = 0; i < l1->length; i++) {
            l3 = l3->next;
        }
        l3->next = l2->next;
        l1->length = length;
        return l1;
    }
}

int main() {
    int lengthHA = 20;
    int lengthHB = 24;
    int a[lengthHA], b[lengthHB];
    int i;
    int length = 0;
    for (i = 0; i < lengthHA; i++) {
        a[i] = i;
    }
    for (i = 0; i < lengthHB; i++) {
        b[i] = i + lengthHA;
    }
    LinkedList ha, hb, hc;
    ha = initList(ha);
    hb = initList(hb);
    LinkedList l = ha;
    for (i = 0; i < lengthHA; i++) {
        LinkedList t;
        l->next = initList(t);
        l = l->next;
        l->elem = a[i];
        length++;
    }
    ha->length = length;
    l = hb;
    length = 0;
    for (i = 0; i < lengthHB; i++) {
        LinkedList t;
        l->next = initList(t);
        l = l->next;
        l->elem = b[i];
        length++;
    }
    hb->length = length;
    hc = mergeList(ha, hb);
    l = hc;
    for (i = 0; i < hc->length; i++) {
        l = l->next;
        printf("%d  ", l->elem);
    }
}

