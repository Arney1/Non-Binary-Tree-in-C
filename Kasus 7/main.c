#include "nbtree.h"
#include <stdio.h>

int main() {
  int Jml_Node;
  printf("jumlah node: ");
  scanf("%d", &Jml_Node);
  Isi_Tree P[jml_maks];
  printf("Depth now: %d\n", Depth(*P));
  Create_tree(*P, Jml_Node);
  PrintTree(*P);

  PreOrder(*P);
  PostOrder(*P);
  InOrder(*P);
  Level_order(*P, Jml_Node);
  printf("\n%d\n", Search(*P, 'D'));
  printf("%d\n", Level(*P, 'D'));
  printf("%d\n", nbDaun(*P));
  printf("%d\n", nbElmt(*P));
  printf("Depth now: %d\n", Depth(*P));

  return 0;
}
