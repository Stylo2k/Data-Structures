/**
 * @file LibList.c
 * @author Mohammad Al Shakoush (mo.alshakoush@gmail.com)
 * @brief a linked list library to be used by importing the `LibList.h` and compiling this c file
 * @version 0.1
 * @date 2022-01-29
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "libList.h"

/**
 * @return List an empty list (pointer to NULL)
 */
List newList()
{
  return NULL;
}

/**
 * @brief returns a boolen whether the list is empty
 *
 * @param li the list to check
 * @return int 1 if the list is empty
 */
int isEmptyList(List li)
{
  return (li == NULL);
}

/**
 * @brief prints an error that the list is empty
 *
 */
void listEmptyError()
{
  printf("**list is empty**\nAborting\n");
  abort();
}

/**
 * @brief adds an item to the start of a list
 *
 * @param value the integer to add to the list
 * @param li the list to add the integer to
 * @return List with the item added
 */
List addItem(int value, List li)
{
  List newList = malloc(sizeof(struct ListNode));
  assert(newList != NULL);
  newList->item = value;
  newList->next = li;
  return newList;
}

/**
 * @brief returns the first element of a list
 *
 * @param li the list to return the first elment from
 * @return int the first element
 */
int firstItem(List li)
{
  if (li == NULL)
  {
    listEmptyError();
  }
  return li->item;
}

/**
 * @brief removes teh first node/element of a list
 *
 * @param li the list to remove the first element from
 * @return List the list after with the first element removed
 */
List removeFirstNode(List li)
{
  List returnList;
  if (li == NULL)
  {
    listEmptyError();
  }
  returnList = li->next;
  free(li);
  return returnList;
}

/**
 * @brief frees a list
 *
 * @param li the list to free
 */
void freeList(List li)
{
  List li1;
  while (li != NULL)
  {
    li1 = li->next;
    free(li);
    li = li1;
  }
  return;
}

/**
 * @brief visits/prints the first element of a list
 *
 * @param li the list to print the first element from
 */
void visit(List li)
{
  printf("|%d|->", li->item);
}

/**
 * @brief visits/prints the whole list (iteratively)
 *
 * @param li the list to visit/print the items of
 */
void visitList(List li)
{
  while (li != NULL)
  {
    visit(li);
    li = li->next;
  }
  printf("NULL\n");
}

/**
 * @brief visits the list (recursively)
 *
 * @param li
 */
void visitListRec(List li)
{
  if (li == NULL)
  {
    return;
  }
  visit(li);
  visitListRec(li->next);
}

/**
 * @brief prints an error message that the list is too short
 *
 */
void listTooShort()
{
  printf("List too short\n");
  abort();
}

/**
 * @brief return an item at a given position
 *
 * @param li the list to pick from
 * @param index the position of the element
 * @return int the element at the position `index`
 */
int itemAtPos(List li, int index)
{
  if (li == NULL)
  {
    listTooShort();
  }
  if (index == 0)
  {
    return firstItem(li);
  }
  else
  {
    return itemAtPos(li->next, index - 1);
  }
}

/**
 * @brief adds a given element at a given position (recursively)
 *
 * @param li the list to add to
 * @param value the number / element to add
 * @param index the position to add the item at
 * @return List the list with the element added at the given position
 */
List addItemAtPos(List li, int value, int index)
{
  if (index == 0)
  {
    return addItem(value, li);
  }
  if (li == NULL)
  {
    listTooShort();
  }
  li->next = addItemAtPos(li->next, value, index - 1);
  return li;
}

/**
 * @brief adds a given element at a given position (iteratively)
 *
 * @param li the list to add to
 * @param value the number / element to add
 * @param index the position to add the item at
 * @return List the list with the element added at the given position
 */
List addItemAtPosIt(List li, int value, int index)
{
  List li1;
  if (index == 0)
  {
    return addItem(value, li);
  }
  li1 = li;
  while (li1 != NULL && index > 1)
  {
    li1 = li1->next;
    index--;
  }
  if (li1 == NULL)
  {
    listTooShort();
  }
  /* now li1 points to the node on position index-1 */
  li1->next = addItem(value, li1->next);
  return li;
}

/**
 * @brief removes an element from the list (recursively)
 *
 * @param li the list to remove the element from
 * @param value the item to remove
 * @return List the list without the item with value `value`
 */
List removeItem(List li, int value)
{
  if (li == NULL)
  {
    return li;
  }
  if (li->item == value)
  {
    return removeFirstNode(li);
  }
  li->next = removeItem(li->next, value);
  return li;
}

/**
 * @brief removes an element from the list (iteratively)
 *
 * @param li the list to remove the element from
 * @param value the item to remove
 * @return List the list without the item with value `value`
 */
List removeItemIt(List li, int value)
{
  List li1;
  if (li == NULL)
  {
    return li;
  }
  if (li->item == value)
  {
    return removeFirstNode(li);
  }
  li1 = li;
  while (li1->next != NULL && (li1->next)->item != value)
  {
    li1 = li1->next;
  }
  if (li1->next != NULL)
  {
    li1->next = removeFirstNode(li1->next);
  }
  return li;
}
