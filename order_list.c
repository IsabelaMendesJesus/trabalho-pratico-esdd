//Isabela Mendes de Jesus e Nicole Pinheiro Jardim

#include <stdio.h>
#include <stdlib.h>
#include "order_list.h"


t_ordered_list* create_list(int max){
    t_ordered_list *list = malloc(sizeof(t_ordered_list));
    list -> max = max;
    list -> n = 0;
    list -> items = malloc(sizeof(int) * max);
    return list;
}

int insert(t_ordered_list *list, int elem){
    if (is_full(list)) {
        int newMax = list->max * 2;
        int *newItems = realloc(list->items, sizeof(int) * newMax);
        list->items = newItems;
        list->max = newMax;//perguntar se precisa fazer if == null pra ver se alocou corretamente e na perder o ponteiro
    }

    int inserir = list->n; 
    for(int i = 0; i < size(list); i++){
        if(list->items[i] > elem){
            inserir = i;
            break;
        }

    }
    for (int j = list->n - 1; j >= inserir; j--) {
        list->items[j + 1] = list->items[j];
    }
    list->items[inserir] = elem;
    list->n++;
    return 0;
}

int get_index (t_ordered_list *list, int index){
    for(int i = 0; i < list->n; i++){
        if (list -> items[i] == index){
        return i;
        }
    }
    return -1;
}

int is_empty(t_ordered_list *list) {
    return list->n == 0;
}

int is_full(t_ordered_list *list){
    return list->n == list->max;
}

int index_of(t_ordered_list *list, int element) {
    for(int i = 0; i < list->n; i++){
        if(list->items[i] == element){
            return i;
        }
    }
    return -1;
}

int remove_by_index(t_ordered_list *list, int index){
   if(is_empty(list)){
        return 0;
    }

    for(int i = index; i < size(list) - 1; i++){
        list->items[i] = list->items[i + 1];
    }

    list->n--;
    return 1;
}

int remove_by_element(t_ordered_list *list, int element){
    if(is_empty(list)){
        return 0;
    }

    int position = index_of(list, element);
    if(position == -1){
        return 0;
    }

    for(int i = position; i < size(list) - 1; i++){
        list->items[i] = list->items[i + 1];
    }

    list->n--;
    return 1;
}

int search(t_ordered_list *list, int element){
    if(is_empty(list)){
        return 0;
    }

    for(int i = 0; i < size(list); i++){
        if(list->items[i] == element){
            return 1;
        }
    }
    return 0; 
}

int count(t_ordered_list *list, int element){
    int count = 0;

    for(int i = 0; i < size(list); i++){
        if(list->items[i] == element){
            count++;
        }
    }
    return count;
}

int size(t_ordered_list *list){
    return list->n;
}

int equals(t_ordered_list *list, t_ordered_list *list2){
    if(size(list) != size(list2)){
        return 0;
    }
    for(int i = 0; i < list->n; i++){
        if(list->items[i] != list2->items[i]){
            return 0;
        }
    }
    return 1;
}

void print_list(t_ordered_list *list) {
    printf("[");
    for (int i = 0; i < list->n; i++) {
        printf("%d ", list->items[i]);
    }
    printf("]\n");

}

t_ordered_list* merge(t_ordered_list *list, t_ordered_list *list2){
    t_ordered_list *list3 = create_list(size(list) + size(list2));
    for(int i = 0; i < size(list); i++){
        insert(list3, list->items[i]);
    }
    for(int i = 0; i < size(list2); i++){
        insert(list3,list2->items[i]);
    }
    return list3;
}

void clear(t_ordered_list *list){
    list->n = 0;
}

void destroy(t_ordered_list *list){
    free(list->items);
    free(list);
}
