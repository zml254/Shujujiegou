#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
    int elem;
    struct LNode *next;
    int length;
} LNode, *LinkedList;

LinkedList initList(LinkedList l1) {
    LinkedList l2 = (LinkedList) malloc(sizeof(LNode));
    l1 = l2;
    return l1;
}

LinkedList invertList(LinkedList *l) {
    LinkedList first, rest, list, last;
    int i;
    if ((*l)->length > 2) {
        first = *l;
        rest = first->next;
        first->next = NULL;
        rest->length = (*l)->length - 1;
        list = invertList(&rest);
        last = list;
        for (i = 1; i < list->length ; i++) {
            last = last->next;
        }
        last->next = first;
        list->length = list->length + 1;
        return list;
    } else {
        first = *l;
        last = first->next;
        first->next = NULL;
        last->next = first;
        last->length = first->length;
        return last;
    }
}

int main() {
    int lengthHA = 54;
    int a[lengthHA];
    int i;
    int length = 0;
    for (i = 0; i < lengthHA; i++) {
        a[i] = i;
    }
    LinkedList ha;
    ha = initList(ha);
    LinkedList l = ha;
    for (i = 0; i < lengthHA; i++) {
        LinkedList t;
        l->next = initList(t);
        l = l->next;
        l->elem = a[i];
        length++;
    }
    ha->length = length;
    ha->next->length = length;
    ha = invertList(&ha->next);
    LinkedList linkedList;
    linkedList = initList(linkedList);
    linkedList->next = ha;
    linkedList->length = ha->length;
    ha = linkedList;
    l = ha->next;
    for (i = 0; i < ha->length ; i++) {
        printf("%d  ", l->elem);
        l = l->next;
    }
}

