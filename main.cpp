#include <iostream>
#include <boost/concept_check.hpp>
#include "rai_concept.h"
#include <vector>
#include <unordered_map>

using namespace std;

template <typename T>
class DemoIteratorWithDeletedMethods: public std::vector<T>::iterator
{
public:
    // запрет конструкторов, десруктором и операторов
//    template <typename U> bool operator==(U rhs) = delete;
//    DemoIteratorWithDeletedMethods() = delete;
//    T operator*() = delete;
//    DemoIteratorWithDeletedMethods operator--() = delete;
//    template <typename U> DemoIteratorWithDeletedMethods operator-=(U rhs) = delete;
//    template <typename U> DemoIteratorWithDeletedMethods operator+=(U rhs) = delete;

};

int main()
{
    BOOST_CONCEPT_ASSERT((rai_concept::RandomAccessIteratorCheck<std::vector<int>::iterator>));

    BOOST_CONCEPT_ASSERT((rai_concept::RandomAccessIteratorCheck<DemoIteratorWithDeletedMethods<int>>));
    return 0;
}
