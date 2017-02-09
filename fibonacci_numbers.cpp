#include "fibonacci_numbers.hpp"

Fibonacci::Fibonacci(const unsigned int n){
  this->n = n;
  build_array(array, n);
  initialize_array();
  compute_fibonacci_numbers(n);
}


Fibonacci::~Fibonacci(){
  delete[] array;
}


void Fibonacci::build_array(int unsigned * & array, const unsigned int n){
  try{
    array = new unsigned int[n+1];
  } catch(const std::bad_alloc & ba){
    std::cerr << "Error allocating memory. " << ba.what() << std::endl;
    std::exit(EXIT_FAILURE);
  }
}

void Fibonacci::initialize_array(){
  if(this->array != nullptr){
    array[0] = 1;
    array[1] = 1;
    for(unsigned int i = 2; i <= n; i++){
      array[i] = 0;
    }
  }
}

unsigned int Fibonacci::compute_fibonacci_numbers(const unsigned int n){
  if(array[n] != 0)
    return array[n];
  array[n] = compute_fibonacci_numbers(n-1) + compute_fibonacci_numbers(n-2);
  return array[n];
}

void Fibonacci::update_table(const unsigned int upn){
  if(this->n < upn){
    unsigned int * p = nullptr;
    build_array(p, upn);
    for(unsigned int i = 0; i<=this->n; i++){
      p[i] = array[i];
    }
    for(unsigned int i = n+1; i <= upn; i++){
      p[i] = 0;
    }
    delete[] array;
    array = p;
    this->n = upn;
    compute_fibonacci_numbers(upn);
  }
}


void Fibonacci::print_fibonacci_series(const unsigned int n){
  update_table(n);
  for(unsigned int i = 0; i <= n; i++){
    std::cout << array[i] << " ";
  }
  std::cout << "\n";
}


unsigned int fibonacci_recursive(const unsigned int n){
  if( n == 1 || n == 0){
    return 1;
  } 
  return fibonacci_recursive(n-1) + fibonacci_recursive(n-2);
}

int main(){
  Fibonacci fib;
  fib.print_fibonacci_series(300);

  std::cout << "Recursive version : " << fibonacci_recursive(300) << std::endl;

  return 0;
}
