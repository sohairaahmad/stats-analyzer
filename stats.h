


/**
 * @file stats.h 
 * @brief Header file containing function declarations and documentation for statistical operations.
 *
 * Provides function declarations for calculating maximum, minimum, mean, and median
 * values of an array of unsigned char data items, alongside array printing and sorting functions.
 *
 * @author Dr. Sohaira Ahmad (sohaira.ahmad@hitecuni.edu.pk)
 * @date Today's Date
 *
 */

#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief Prints the statistics of an array (minimum, maximum, mean, median).
 *
 * @param ptr Pointer to an n-element data array
 * @param length Size of the data array
 */
void print_statistics(unsigned char *ptr, unsigned int length);

/**
 * @brief Prints an array to the screen nicely formatted.
 *
 * @param ptr Pointer to an n-element data array
 * @param length Size of the data array
 */
void print_array(unsigned char *ptr, unsigned int length);

/**
 * @brief Given an array of data and a length, returns the median value.
 *
 * Rounds down to the nearest integer.
 *
 * @param ptr Pointer to an n-element data array
 * @param length Size of the data array
 * @return Median value as unsigned char
 */
unsigned char find_median(unsigned char *ptr, unsigned int length);

/**
 * @brief Given an array of data and a length, returns the mean value.
 *
 * Rounds down to the nearest integer.
 *
 * @param ptr Pointer to an n-element data array
 * @param length Size of the data array
 * @return Mean value as unsigned char
 */
unsigned char find_mean(unsigned char *ptr, unsigned int length);

/**
 * @brief Given an array of data and a length, returns the maximum value.
 *
 * @param ptr Pointer to an n-element data array
 * @param length Size of the data array
 * @return Maximum value as unsigned char
 */
unsigned char find_maximum(unsigned char *ptr, unsigned int length);

/**
 * @brief Given an array of data and a length, returns the minimum value.
 *
 * @param ptr Pointer to an n-element data array
 * @param length Size of the data array
 * @return Minimum value as unsigned char
 */
unsigned char find_minimum(unsigned char *ptr, unsigned int length);

/**
 * @brief Sorts the array from largest to smallest.
 *
 * Element 0 becomes the largest, element n-1 becomes the smallest.
 *
 * @param ptr Pointer to an n-element data array
 * @param length Size of the data array
 */
void sort_array(unsigned char *ptr, unsigned int length);

#endif /* __STATS_H__ */
