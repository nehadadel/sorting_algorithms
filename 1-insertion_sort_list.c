#include "sort.h"
/**
 *insertion_sort_list - sorts a doubly linked list of integers in
 *ascending order using the Insertion sort algorithm
 *
 *@list: list to sorted
*/
void insertion_sort_list(listint_t **list)
{
listint_t *current;
listint_t *Node, *tmp_next, *tmp_prev;

if (list == NULL || *list == NULL)
return;

current = (*list)->next;

while (current)
{
Node = current;
while ((Node->prev != NULL) && (Node->prev->n > Node->n))
{

tmp_prev = Node->prev;
tmp_next = Node->next;

if (tmp_prev->prev != NULL)
tmp_prev->prev->next = Node;

Node->prev = tmp_prev->prev;
Node->next = tmp_prev;

tmp_prev->prev = Node;
tmp_prev->next = tmp_next;

if (tmp_next != NULL)
tmp_next->prev = tmp_prev;

if (Node->prev == NULL)
*list = Node;
print_list(*list);

}
current = current->next;
}
}
