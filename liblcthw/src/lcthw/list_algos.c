#include <lcthw/list_algos.h>
#include "dbg.h"


void List_swap( ListNode *node1, ListNode *node2)
{
    void *temp = node1->value;
    node1->value = node2->value;
    node2->value = temp;
}

int List_bubble_sort(List *list, List_compare cmp)
{
    int swapped = 0;

    do {
        swapped = 0;

        LIST_FOREACH(list, first, next, cur){
            if(!cur->next) break;

            if(cmp(cur->value, cur->next->value) > 0) {
                List_swap(cur, cur->next);
                swapped = 1;
            }
        }
    } while(swapped);

    return 0;
}

List *List_merge_sort(List *list, List_compare cmp)
{
    return list;
}

