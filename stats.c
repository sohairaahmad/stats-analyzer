/**
 * @file stats.c
 * @brief Implementation file for statistical analysis operations on char arrays.
 *
 * @author Dr. Sohaira Ahmad (sohaira.ahmad@hitecuni.edu.pk)
 * @date Today's Date
 */

#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,  92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  printf("--- Initial Unsorted Array ---\n");
  print_array(test, SIZE);

  printf("\n--- Array Statistics ---\n");
  print_statistics(test, SIZE);

  printf("\n--- Sorted Array (Largest to Smallest) ---\n");
  sort_array(test, SIZE);
  print_array(test, SIZE);
}

void print_statistics(unsigned char *ptr, unsigned int length) {
  printf("Minimum: %d\n", find_minimum(ptr, length));
  printf("Maximum: %d\n", find_maximum(ptr, length));
  printf("Mean   : %d\n", find_mean(ptr, length));
  printf("Median : %d\n", find_median(ptr, length));
}

void print_array(unsigned char *ptr, unsigned int length) {
  for (unsigned int i = 0; i < length; i++) {
    printf("%3d ", ptr[i]);
    if ((i + 1) % 10 == 0) {
      printf("\n");
    }
  }
}

unsigned char find_median(unsigned char *ptr, unsigned int length) {
  unsigned char temp[length];
  for (unsigned int i = 0; i < length; i++) {
    temp[i] = ptr[i];
  }
  
  sort_array(temp, length);

  if (length % 2 == 0) {
    return (temp[length / 2 - 1] + temp[length / 2]) / 2;
  } else {
    return temp[length / 2];
  }
}

unsigned char find_mean(unsigned char *ptr, unsigned int length) {
  if (length == 0) return 0;
  
  unsigned int sum = 0;
  for (unsigned int i = 0; i < length; i++) {
    sum += ptr[i];
  }
  return (unsigned char)(sum / length);
}

unsigned char find_maximum(unsigned char *ptr, unsigned int length) {
  if (length == 0) return 0;
  
  unsigned char max = ptr[0];
  for (unsigned int i = 1; i < length; i++) {
    if (ptr[i] > max) {
      max = ptr[i];
    }
  }
  return max;
}

unsigned char find_minimum(unsigned char *ptr, unsigned int length) {
  if (length == 0) return 0;
  
  unsigned char min = ptr[0];
  for (unsigned int i = 1; i < length; i++) {
    if (ptr[i] < min) {
      min = ptr[i];
    }
  }
  return min;
}

void sort_array(unsigned char *ptr, unsigned int length) {
  for (unsigned int i = 0; i < length - 1; i++) {
    for (unsigned int j = 0; j < length - i - 1; j++) {
      if (ptr[j] < ptr[j + 1]) {
        unsigned char temp = ptr[j];
        ptr[j] = ptr[j + 1];
        ptr[j + 1] = temp;
      }
    }
  }
}
