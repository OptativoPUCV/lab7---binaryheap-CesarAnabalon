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
    heapElem nuevo;
    nuevo.data = data;
    nuevo.priority = priority;
  
    int posicion = pq->size;
    pq->heapArray[posicion] = nuevo;
    pq->size++;
  
    int newPos = (posicion - 1) / 2;
  
    while (posicion > 0 && (pq->heapArray[posicion].priority > pq->heapArray[newPos].priority)) 
    {
        heapElem temp = pq->heapArray[posicion];
        pq->heapArray[posicion] = pq->heapArray[newPos];
        pq->heapArray[newPos] = temp;

        posicion = newPos;
        newPos = (posicion - 1) / 2;
    }
}


void heap_pop(Heap* pq)
{
if (pq->size == 0) {
        return; 
    }
    
    
    pq->heapArray[0] = pq->heapArray[pq->size - 1];
    pq->size--;
    
    
    int currentIndex = 0;
    while (1) {
        int leftChildIndex = 2 * currentIndex + 1;
        int rightChildIndex = 2 * currentIndex + 2;
        int largestIndex = currentIndex;
        
        
        if (leftChildIndex < pq->size && pq->heapArray[leftChildIndex].priority > pq->heapArray[largestIndex].priority) {
            largestIndex = leftChildIndex;
        }
        
        
        if (rightChildIndex < pq->size && pq->heapArray[rightChildIndex].priority > pq->heapArray[largestIndex].priority) {
            largestIndex = rightChildIndex;
        }
        
        
        if (largestIndex == currentIndex) {
            break;
        }
        
        heapElem temp = pq->heapArray[currentIndex];
        pq->heapArray[currentIndex] = pq->heapArray[largestIndex];
        pq->heapArray[largestIndex] = temp;
        
        currentIndex = largestIndex;
    }
}
