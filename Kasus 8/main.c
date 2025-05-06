#include "nbtree.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void clearTerminal();
void waitForInput();
int printMenu();
void PrintInfoTree(Isi_Tree P, int jml_node);
void inputInfoType(infotype *X);

// MENUS
void ExitMenu(Isi_Tree P, int jml_node);
void PreOrderMenu(Isi_Tree P, int jml_node);
void PostOrderMenu(Isi_Tree P, int jml_node);
void InOrderMenu(Isi_Tree P, int jml_node);
void LevelOrderMenu(Isi_Tree P, int jml_node);
void PrintTreeMenu(Isi_Tree P, int jml_node);
void LeafCountMenu(Isi_Tree P, int jml_node);
void NodeLevelMenu(Isi_Tree P, int jml_node);
void TreeDepthMenu(Isi_Tree P, int jml_node);
void CompareNodesMenu(Isi_Tree P, int jml_node);
void SearchMenu(Isi_Tree P, int jml_node);

int main() {
  int Jml_Node;
  printf("Inisialisasi\n");
  printf("jumlah node: ");
  scanf("%d", &Jml_Node);
  Isi_Tree P[jml_maks];
  printf("Depth now: %d\n", Depth(*P));
  Create_tree(*P, Jml_Node);
  bool isRunning = true;
  while (isRunning) {
    int i = printMenu();
    // PrintInfoTree(*P, Jml_Node);
    void (*menus[])(Isi_Tree, int) = {
        PreOrderMenu,  PostOrderMenu,    InOrderMenu,   LevelOrderMenu,
        PrintTreeMenu, SearchMenu,       LeafCountMenu, NodeLevelMenu,
        TreeDepthMenu, CompareNodesMenu, ExitMenu};
    int choice;
    printf("Pilih menu: ");
    scanf(" %d", &choice);
    if (choice >= 1 && choice <= i) {
      (*menus[choice - 1])(*P, Jml_Node);
    }
  }
  return 0;
}

void ExitMenu(Isi_Tree P, int jml_node) {
  clearTerminal();
  printf("Exiting...\n");
  exit(0);
}

void clearTerminal() { system("clear"); }

void waitForInput() {
  printf("\nPress Enter to continue...");
  getchar();
  getchar();
}

void PreOrderMenu(Isi_Tree P, int jml_node) {
  clearTerminal();
  printf("Traversal PreOrder:\n");
  PreOrder(P);
  waitForInput();
}

void PostOrderMenu(Isi_Tree P, int jml_node) {
  clearTerminal();
  printf("Traversal PostOrder:\n");
  PostOrder(P);
  waitForInput();
}

void InOrderMenu(Isi_Tree P, int jml_node) {
  clearTerminal();
  printf("Traversal InOrder:\n");
  InOrder(P);
  waitForInput();
}

void LevelOrderMenu(Isi_Tree P, int jml_node) {
  clearTerminal();
  printf("Traversal Level Order:\n");
  Level_order(P, jml_node);
  waitForInput();
}

void PrintTreeMenu(Isi_Tree P, int jml_node) {
  clearTerminal();
  printf("Print Tree:\n");
  PrintTree(P);
  waitForInput();
}

void LeafCountMenu(Isi_Tree P, int jml_node) {
  clearTerminal();
  printf("Jumlah Daun/Leaf: %d\n", nbDaun(P));
  waitForInput();
}

void inputInfoType(infotype *X) { scanf(" %c", X); }

void NodeLevelMenu(Isi_Tree P, int jml_node) {
  clearTerminal();
  printf("Mencari Level Node Tree:\n");
  PrintTree(P);
  infotype X;
  printf("Masukkan node yang ingin dicari levelnya: ");
  inputInfoType(&X);
  int level = Level(P, X);
  if (level == -1)
    printf("Node dengan info %c tidak ditemukan\n", X);
  else
    printf("%c berada di level ke %d\n", X, level);
  waitForInput();
}

void TreeDepthMenu(Isi_Tree P, int jml_node) {
  clearTerminal();
  printf("Kedalaman Tree: %d\n", Depth(P));
  waitForInput();
}

void CompareNodesMenu(Isi_Tree P, int jml_node) {
  clearTerminal();
  printf("Membandingkan 2 node tree:\n");
  infotype X1, X2;
  PrintTree(P);
  printf("Masukkan node pertama: ");
  inputInfoType(&X1);
  printf("Masukkan node kedua: ");
  inputInfoType(&X2);
  printf("Nilai terbesarnya adalah: %c\n", Max(X1, X2));
  printf("%c berada di level ke %d\n", X1, Level(P, X1));
  printf("%c berada di level ke %d\n", X2, Level(P, X2));
  waitForInput();
}

int printMenu() {
  int i = 1;
  clearTerminal();
  printf("%d. Traversal PreOrder\n", i++);
  printf("%d. Traversal PostOrder\n", i++);
  printf("%d. Traversal InOrder\n", i++);
  printf("%d. Traversal Level Order\n", i++);
  printf("%d. Print Tree\n", i++);
  printf("%d. Search Node Tree\n", i++);
  printf("%d. Jumlah Daun/Leaf\n", i++);
  printf("%d. Mencari Level Node Tree\n", i++);
  printf("%d. Kedalaman Tree\n", i++);
  printf("%d. Membandingkan 2 node tree\n", i++);
  printf("%d. Exit\n", i++);
  return i;
}

void PrintInfoTree(Isi_Tree P, int jml_node) {
  clearTerminal();
  printf("Seluruh Node pada Non Binary Tree:\n");
  for (int i = 1; i <= jml_node; i++) {
    if (P[i].info != '\0') {
      printf("--> Indeks ke-%d\n", i);
      printf("------------------------------------\n");
      printf("Info node ke-%d: %c\n", i, P[i].info);
      printf("First son node ke-%d: %d\n", i, P[i].ps_fs);
      printf("Next brother node ke-%d: %d\n", i, P[i].ps_nb);
      printf("Parent node ke-%d: %d\n", i, P[i].ps_pr);
      printf("------------------------------------\n");
      printf("\n");
    }
  }
}

void SearchMenu(Isi_Tree P, int jml_node) {
  clearTerminal();
  printf("Masukkan nilai yang ingin dicari: ");
  infotype X;
  inputInfoType(&X);
  if (Search(P, X)) {
    printf("Node dengan nilai %c ditemukan\n", X);
  } else {
    printf("Node dengan nilai %c tidak ditemukan\n", X);
  }
  waitForInput();
}
