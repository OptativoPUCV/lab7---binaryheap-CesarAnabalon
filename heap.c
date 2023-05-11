#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq)
{
  if(pq->size == 0) return NULL;

  return pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority)
{
  if(pq->size == pq->capac)
  {
    int reajuste = (pq->capac*2)+1;
    pq->heapArray = (heapElem *)realloc(pq->heapArray, reajuste*sizeof(heapElem));
    pq->capac = reajuste;
  }
    heapElem* nuevo;
    nuevo->data = data;
    nuevo->priority = priority;

    // Inserta el nuevo elemento en el montículo
    int currentIndex = pq->size;
    pq->heapArray[currentIndex] = nuevo;
    pq->size++;

    // Reajusta el montículo hacia arriba
    int parentIndex = (currentIndex - 1) / 2;
  
    while (currentIndex > 0 && pq->heapArray[currentIndex].priority > pq->heapArray[parentIndex].priority) 
    {
        heapElem temp = pq->heapArray[currentIndex];
        pq->heapArray[currentIndex] = pq->heapArray[parentIndex];
        pq->heapArray[parentIndex] = temp;

        currentIndex = parentIndex;
        parentIndex = (currentIndex - 1) / 2;
    }
}
  



void heap_pop(Heap* pq)
{
  
}

Heap* createHeap(){
  Heap* heap = (Heap*)malloc(sizeof(Heap));
  heap->heapArray = (heapElem*)malloc(3 * sizeof(heapElem));
  heap->size = 0;
  heap->capac = 3;
  return heap;
}
