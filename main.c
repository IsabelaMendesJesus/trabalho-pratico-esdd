//Isabela Mendes de Jesus e Nicole Pinheiro Jardim

#include <stdio.h>
#include "order_list.h"

int main(){
    t_ordered_list *list;
    list = create_list(5);

    insert(list, 3);
    insert(list, 2);
    insert(list, 5);
    insert(list, 1);
    insert(list, 1);
    print_list(list);
    remove_by_index(list,3);
    print_list(list);
    remove_by_element(list,3);
    print_list(list);
    int x = search(list,1);
    insert(list,1);
    insert(list,1);
    insert(list, 10);
    print_list(list);
    int n = count(list,1);
    printf("O elemento 3 aparece %d vezes\n", n);

    t_ordered_list *list2;
    list2 = create_list(3);
    insert(list2,4);
    insert(list2,5);
    insert(list2,2);
    print_list(list2);
    printf("A lista1 eh igual a lista2? %s\n", equals(list, list2) ? "sim" : "nao");
    printf("Lista 3(merge):\n");
    print_list(merge(list,list2));
}