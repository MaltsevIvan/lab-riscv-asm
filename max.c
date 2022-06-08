#include <stdio.h>
#include <stdlib.h>
const int N = 4;
const int M = 3;
#define STACK_SIZE 12

typedef struct stack {
  int data [STACK_SIZE];
  int size;
} stack;

void push (stack *stack, int val) {
  if (stack -> size >= STACK_SIZE) {
    exit(-100);
  }
  stack -> data [stack -> size] = val;
  stack -> size ++;
}

int pop (stack *stack) {
  if (stack -> size == 0) {
    exit(-101);
  }
  stack -> size --;
  return stack -> data[stack -> size];
}

void findMax (stack stack, int *max_x, int *max_y) {
  int count = stack.size;
  int max, temp; 
  max = pop(&stack);
  *max_x = count - 1;
  while (stack.size) {
    count --;
    temp = pop(&stack);
    if (temp > max) {
      max = temp;
      *max_x = count - 1;
    }
  }
  *max_y = *max_x % N;
  *max_x = *max_x / N;
}

int main () {
  int max_x, max_y;
	int mass[] = 
  {
    1, 8, 3, 2,
	  4, 2, 55, 6,
	  6, 4, 2, 7
  };
  stack stack;
  stack.size = 0;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      push(&stack, mass[i * N + j]);
    }
  }
  findMax(stack, &max_x, &max_y);

  printf("Index of max element: (%d, %d)", max_x, max_y);

  return 0;
  
}