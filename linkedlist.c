#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {int x; struct node *next;};

void print_list(struct node *linkedlist) {
    if (linkedlist) {
        printf("%d ", linkedlist->x);
        print_list(linkedlist->next);
    }
    else {
        printf("\n");
    }
    //Recursively calling print_list until next node doesn't exist.
    //Printing \n because it will hit linkedlist = false
    //even if something was printed. Just simpler than doing
    //a counter to show something else if there was nothing at all.
}

struct node * insert_front(struct node *linkedlist, int new) {
    struct node *first = (struct node *) malloc(sizeof(*first));
    first->x = new;
    first->next = linkedlist;
    return first;
}

struct node * free_list(struct node *linkedlist) {
    if (linkedlist) {
        free_list(linkedlist->next);
        free(linkedlist);
    }
    return linkedlist;
    //Recursively callinf free_list in order to get to the back of the
    //linked-list, all items are removed back to front essentially, with
    //the final pointer being at the beginning. Hence the final return.
}

int main() {
    printf("Creating node A...\n");
    struct node *a = (struct node *) malloc(sizeof(*a));
    a->x = 5;
    a->next = 0;
    printf("Printing List\n");
    print_list(a);
    printf("Inserting node b at front...\n");
    struct node *b = insert_front(a, 10);
    printf("Printing List. Order should be --10, 5--\n");
    print_list(b);
    printf("Inserting node c at front...\n");
    struct node *c = insert_front(b, 15);
    printf("Printing List. Order should be --15, 10, 5--\n");
    print_list(c);
    printf("Freeing list.\n");
    free_list(c);
    return 0;
}
