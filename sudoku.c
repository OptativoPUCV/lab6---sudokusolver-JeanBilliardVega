#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){
   int i,j;
   for(i = 0; i < 9; i++)
   {
      int* arregloBinarioCol = calloc(9, sizeof(int));
      int* arregloBinarioFil = calloc(9, sizeof(int));
      int* arregloBinarioSub = calloc(9, sizeof(int));
      for(j = 0; j < 9; j++)
      {
         int numeroFil = n->sudo[i][j];
         int numeroCol = n->sudo[j][i];
         if(numeroFil != 0)
         {
            if(arregloBinarioFil[numeroFil] == 0)
            {
               arregloBinarioFil[numeroFil] = 1;
            }
            else
            {
               return 0;
            }
         }
         if(numeroCol != 0)
         {
            if(arregloBinarioCol[numeroCol] == 0)
            {
               arregloBinarioCol[numeroCol] = 1;
            }
            else
            {
               return 0;
            }
         }
      }
      for(int k = 0; k < 9; k++)
      {
         int l=3*(i/3) + (k/3);
         int r=3*(i%3) + (k%3);
         int num = n->sudo[l][r];
         if(num != 0)
         {
            if(arregloBinarioSub[num] == 0)
            {
               arregloBinarioSub[num] = 1;
            }
            else
            {
               return 0;
            }
         }
      }
   }
   
   
   return 1;
}


List* get_adj_nodes(Node* n)
{
   List* list=createList();
   int primeraCasilla = 0; 
   int i,j;
   for(i=0;i<9;i++)
   {
      for(j= 0;j<9;j++)
      {
         if(n->sudo[i][j]==0 && primeraCasilla==0)
         {
            primeraCasilla = 1;
            for(int k = 1; k < 10; k++)
            {
               Node* aux=copy(n);
               aux->sudo[i][j] = k;
               if(is_valid(aux) && primeraCasilla == 1)
               {
                  pushBack(list,aux);
               }
            }
         }
      }
      if(j < 9)
      {
         break;
      }
   }
   return list;
}


int is_final(Node* n)
{

   return 0;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/