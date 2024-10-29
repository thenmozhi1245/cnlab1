#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 5
void printDistanceVector(int nodes, int distance[MAX_NODES][MAX_NODES]) {
  printf("\t");
  for (int j = 0; j < nodes; j++) {
    printf("  Node%d\t", j);
  }
  printf("\n");
  for (int i = 0; i < nodes; i++) {
    printf("Node%d\t", i);
    for (int j = 0; j < nodes; j++) {
      if (distance[i][j] == INT_MAX)
        printf("INF   \t"); 
      else
        printf("%d\t\t", distance[i][j]);
    }
    printf("\n");
  }
  printf("------------------------------------------------\n");
}
int main() {
  int nodes = MAX_NODES;
  int costMatrix[MAX_NODES][MAX_NODES] = {
     {0, 1, -1, 2, -1}, 
     {1, 0, 3, -1, -1},
     {-1, 3, 0, 1, 2},  
     {2, -1, 1, 0, 3},  
     {-1, -1, 2, 3, 0}  
  };
  int distance[MAX_NODES][MAX_NODES];
  for (int i = 0; i < nodes; i++) {
    for (int j = 0; j < nodes; j++) {
      if (costMatrix[i][j] == -1) 
        distance[i][j] = INT_MAX;
      else
        distance[i][j] = costMatrix[i][j];
    }
  }
  int updated;
  do {
    updated = 0;
    for (int i = 0; i < nodes; i++) {
      for (int j = 0; j < nodes; j++) {
        if (costMatrix[i][j] != -1) { 
          for (int k = 0; k < nodes; k++) {
            if (distance[i][j] != INT_MAX && distance[j][k] != INT_MAX &&
                distance[i][k] > distance[i][j] + distance[j][k]) {
              distance[i][k] =
                  distance[i][j] + distance[j][k]; 
              updated = 1; 
            }
          }
        }
      }
    }
    printf("Distance Vectors after update:\n");
    printDistanceVector(nodes, distance);
  } while (updated); 
  printf("Final Distance Vectors:\n");
  printDistanceVector(nodes, distance);
  return 0;
}
