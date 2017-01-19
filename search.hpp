#ifndef SEARCH_HPP_
#define SEARCH_HPP_

class Search{
  public:
    static int linear_search(const int * const array,
      const int length,
      const int q);

    static int binary_search(const int * const array,
      const int length,
      const int q);
};

#endif
