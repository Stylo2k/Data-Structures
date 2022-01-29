#include "libList.h"

int main()
{
    List list = newList();

    list = addItem(3, list);
    list = addItem(5, list);
    list = addItem(6, list);
    list = addItem(7, list);
    list = addItem(2, list);
    list = addItem(1, list);

    visitList(list);
    freeList(list);
    return 0;
}