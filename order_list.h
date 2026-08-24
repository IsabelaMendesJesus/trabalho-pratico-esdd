#ifndef ORDER_LIST_H
#define ORDER_LIST_H

typedef struct{
    int max;
    int n;
    int *items;
}t_ordered_list;


t_ordered_list* create_list(int max);
int remove_by_index(t_ordered_list *list, int index);
int remove_by_element(t_ordered_list *list, int element);
int search(t_ordered_list *list, int element);
int index_of(t_ordered_list *list, int elem);
int insert(t_ordered_list *list, int elem);
int count(t_ordered_list *list, int element);
int size(t_ordered_list *list);
int is_empty(t_ordered_list *list);
int is_full(t_ordered_list *list);
int equals(t_ordered_list *list, t_ordered_list *list2);
t_ordered_list* merge(t_ordered_list *list, t_ordered_list *list2);
void clear(t_ordered_list *list);
void destroy(t_ordered_list *list);
void print_list(t_ordered_list *list);
#endif