#include "nbtree.h"
#include <stdio.h>
void PreOrderRec(Isi_Tree P, address node) {
  if (node == nil || P[node].info == '\0')
    return;
  printf("%c ", P[node].info);
  address child = P[node].ps_fs;
  while (child != nil) {
    PreOrderRec(P, child);
    child = P[child].ps_nb;
  }
}

void InOrderRec(Isi_Tree P, address node) {
  if (node == nil || P[node].info == '\0')
    return;
  address child = P[node].ps_fs;
  if (child != nil) {
    InOrderRec(P, child);
  }

  printf("%c ", P[node].info);

  if (child != nil) {
    child = P[child].ps_nb;
  }

  while (child != nil) {
    InOrderRec(P, child);
    child = P[child].ps_nb;
  }
}

void PostOrderRec(Isi_Tree P, address node) {
  if (node == nil || P[node].info == '\0')
    return;
  address child = P[node].ps_fs;
  while (child != nil) {
    PostOrderRec(P, child);
    child = P[child].ps_nb;
  }
  printf("%c ", P[node].info);
}

void Create_tree(Isi_Tree X, int Jml_Node) {
  for (int i = 0; i <= Jml_Node; i++) {
    X[i].info = '\0';
    X[i].ps_fs = nil;
    X[i].ps_nb = nil;
    X[i].ps_pr = nil;
  }
  for (int i = 1; i <= Jml_Node; i++) {
    printf("Enter info for node %d: ", i);
    scanf(" %c", &X[i].info);
    printf("Enter parent index/node number for node %d (0 for root): ", i);
    scanf("%d", &X[i].ps_pr);
    X[i].ps_fs = nil;
    X[i].ps_nb = nil;

    int parent = X[i].ps_pr;
    if (parent != nil) {
      if (X[parent].ps_fs == nil) {
        X[parent].ps_fs = i;
      } else {
        int last = X[parent].ps_fs;
        while (X[last].ps_nb != nil) {
          last = X[last].ps_nb;
        }
        X[last].ps_nb = i;
      }
    }
  }
}
// Create Non Binary Tree sebanyak Jml_Node
// Tujuan mengentrykan Non Binary Tree ke array Isi_Tree dengan polaLevel Order
// Jml Node adalah banyaknya elemen dalam Tree yang menjadi parameter input

bool IsEmpty(Isi_Tree P) { return P[1].info == '\0'; }
/* Mengirimkan true jika Isi_Tree KOSONG */

/***** Traversal *****/
void PreOrder(Isi_Tree P) {
  if (!IsEmpty(P)) {
    PreOrderRec(P, 1);
  }
  printf("\n");
}
/* Traversal PreOrder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara PreOrder : Parent,
fs, nb */
void InOrder(Isi_Tree P) {
  if (!IsEmpty(P)) {
    InOrderRec(P, 1);
  }
  printf("\n");
}
/* Traversal InOrder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara InOrder : fs, Parent,
Sisa anak lain */
void PostOrder(Isi_Tree P) {
  if (!IsEmpty(P)) {
    PostOrderRec(P, 1);
  }
  printf("\n");
}
/* Traversal PostOrder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara PostOrder : fs, nb,
Parent */
void Level_order(Isi_Tree X, int Maks_node) {
  int queue[Maks_node];
  int front = 0, rear = 0;
  queue[rear++] = 1;
  while (front != rear) {
    int node = queue[front++];
    printf("%c ", X[node].info);
    address child = X[node].ps_fs;
    while (child != nil) {
      queue[rear++] = child;
      child = X[child].ps_nb;
    }
  }
}
/* Traversal LevelOrder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara Level Order */

void PrintTreeRec(Isi_Tree P, int *level, address node) {
  if (node == nil || P[node].info == '\0')
    return;
  if (*level >= 2) {
    int ancestor = P[node].ps_pr;
    bool hasSibling[*level - 1];
    int ancestorCount = 0;
    while (P[ancestor].ps_pr != nil) {
      hasSibling[ancestorCount++] = (P[ancestor].ps_nb != nil);
      ancestor = P[ancestor].ps_pr;
    }
    for (int i = ancestorCount - 1; i >= 0; i--) {
      if (hasSibling[i]) {
        printf("%s", "│  ");
      } else {
        printf("%s", "   ");
      }
    }
  }
  if (*level > 0) {
    if (P[node].ps_nb != nil) {
      printf("├─ ");
    } else {
      printf("└─ ");
    }
  }
  printf("%c\n", P[node].info);
  address child = P[node].ps_fs;
  while (child != nil) {
    int nextLevel = *level + 1;
    PrintTreeRec(P, &nextLevel, child);
    child = P[child].ps_nb;
  }
}

void PrintTree(Isi_Tree P) {
  int level = 0;
  PrintTreeRec(P, &level, 1);
}
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditulis ke layar */
/***** Search *****/
bool SearchRec(Isi_Tree P, address node, infotype X) {
  if (node == nil || P[node].info == '\0')
    return false;
  if (P[node].info == X)
    return true;
  address child = P[node].ps_fs;
  while (child != nil) {
    if (SearchRec(P, child, X))
      return true;
    child = P[child].ps_nb;
  }
  return false;
}

bool Search(Isi_Tree P, infotype X) {
  if (IsEmpty(P))
    return false;
  return SearchRec(P, 1, X);
}
/* Mengirimkan true jika ada node dari P yang bernilai X */
// Other Functions

int nbElmt(Isi_Tree P) {
  int count = 0;
  for (int i = 1; i <= jml_maks; i++) {
    if (P[i].info != '\0') {
      count++;
    }
  }
  return count;
}
/* Mengirimkan banyak elemen (node) di pohon non biner P */
int nbDaunRec(Isi_Tree P, address node) {
  if (node == nil || P[node].info == '\0')
    return 0;
  if (P[node].ps_fs == nil)
    return 1;
  int count = 0;
  address child = P[node].ps_fs;
  while (child != nil) {
    count += nbDaunRec(P, child);
    child = P[child].ps_nb;
  }
  return count;
}

int nbDaun(Isi_Tree P) {
  if (IsEmpty(P))
    return 0;
  return nbDaunRec(P, 1);
}

int LevelRec(Isi_Tree P, address node, infotype X, int currentLevel) {
  if (node == nil || P[node].info == '\0')
    return -1;
  if (P[node].info == X)
    return currentLevel;
  address child = P[node].ps_fs;
  while (child != nil) {
    int depth = LevelRec(P, child, X, currentLevel + 1);
    if (depth != -1)
      return depth;
    child = P[child].ps_nb;
  }
  return -1;
}
/* Mengirimkan banyak daun (node) pohon non biner P */
int Level(Isi_Tree P, infotype X) { return LevelRec(P, 1, X, 0); }
/* Mengirimkan level dari node X yang merupakan salah satu simpul */
/* dr pohon P. Akar (P) levelnya adalah 0. Pohon tidak kosong */
int DepthRec(Isi_Tree P, address node) {
  if (node == nil || P[node].info == '\0')
    return 0;
  int maxDepth = 0;
  address child = P[node].ps_fs;
  while (child != nil) {
    int depth = DepthRec(P, child);
    maxDepth = Max(maxDepth, depth);
    child = P[child].ps_nb;
  }
  return maxDepth + 1;
}

int Depth(Isi_Tree P) {
  if (IsEmpty(P)) {
    return 0;
  }
  return DepthRec(P, 1) - 1 < 0 ? 0 : DepthRec(P, 1) - 1;
}
/* Pohon Biner mungkin Kosong, mengirimkan 'depth' yaitu tinggi dari
Pohon */
/* Basis : Pohon Kosong, tingginya Nol */
int Max(infotype Data1, infotype Data2) {
  return Data1 > Data2 ? Data1 : Data2;
}
/* Mengirimkan Nilai terbesar dari dua data */
