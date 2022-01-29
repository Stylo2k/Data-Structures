/**
 * @file demo.c
 * @author Mohammad Al Shakoush (mo.alshakoush@gmail.com)
 * @brief demo for tree
 * @version 0.1
 * @date 2022-01-29
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "tree.h"

int main(int argc, char *argv[])
{

  int size;
  printf("Wanted size: ");
  if (!scanf("%d", &size))
  {
    printf("input not scanned correctly");
  }
  printf("\n");
  int *arr = malloc((size + 1) * sizeof(int));

  printf("Insert %d elements\n", size);

  for (int idx = 1; idx < size + 1; ++idx)
  {
    if (!scanf("%d", &arr[idx]))
    {
      printf("input not scanned correctly");
    }
  }

  printf("\nPre Order\n");
  preOrderArray(arr, size, 1);
  printf("\n\nPost Order\n");
  postOrderArray(arr, size, 1);
  printf("\n\nIn nOrder\n");
  inOrderArray(arr, size, 1);
  printf("\n");

  free(arr);
}
