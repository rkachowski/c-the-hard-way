#include <lcthw/list_algos.h>
#include "dbg.h"


void List_swap( ListNode *node1, ListNode *node2)
{
    void *temp = node1->value;
    node1->value = node2->value;
    node2->value = temp;
}

List *List_merge(List *a, List *b, List_compare cmp)
{
    List *result = List_create();

    while(List_count(a) > 0 || List_count(b) > 0) {
        if(List_count(a) > 0 && List_count(b) > 0){
            if(cmp(a->first->value, b->first->value) <= 0) {
                List_push(result, List_shift(a));
            } else {
                List_push(result, List_shift(b));
            }
        } else if (List_count(a) > 0) {
            List_push(result, List_shift(a));
        } else if (List_count(b) > 0) {
            List_push(result, List_shift(b));
        }
    }

    return result;
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
    if(List_count(list) <= 1) return list;

    List *left = List_create();
    List *right = List_create();

    ListNode *cur = list->first;
    int midpoint = List_count(list) / 2;
    debug("midpoint is %i", midpoint);

    for(int i = 0;i < List_count(list);i++) {
        debug("loop iteration %i", i);
        if(i < midpoint) {
            List_push(left, cur->value);
        } else {
            List_push(right, cur->value);
        }

        debug("pushed to list");
        if(cur->next){
            cur = cur->next;
        } else {
            break;
        }
    }

    left = List_merge_sort(left, cmp);
    right = List_merge_sort(right, cmp);

    return List_merge(left, right, cmp);
}

