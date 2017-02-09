#ifndef FIBONACCI_NUMBERS_HPP_
#define FIBONACCI_NUMBERS_HPP_

#include <new>
#include <exception>
#include <iostream>

/** 
* Compute fibonnaci numbers using dynamic programming and using recursion
*/
class Fibonacci{
  private:
    unsigned int n;
    unsigned int * array;
 
 
    /**
    * Build a array of size n
    */   
    void build_array(unsigned int * & array, const unsigned int n);

    /**
    * Initialize the array to store the fibonacci series
    */
    void initialize_array();

    /**
    * Update the array containing the fibonnaci series up to n
    */
    unsigned int compute_fibonacci_numbers(const unsigned int n);

    /**
    * Update the table every time that a fibonacci number greater
    * than n is requested
    */
    void update_table(const unsigned int n);

  public:
    /**
    * Constructor
    * param n: number to be computed
    */
    Fibonacci(const unsigned int n = 10);

    ~Fibonacci();

    void print_fibonacci_series(const unsigned int n=10);
};

#endif

