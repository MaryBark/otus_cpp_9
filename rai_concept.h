#ifndef RAI_CONCEPT_H
#define RAI_CONCEPT_H

#pragma once

#include <boost/concept_check.hpp>
#include <iterator>


namespace
{
    template<typename T>
    void suppress_warning(T value) {}
}


namespace rai_concept
{

    template<typename T>
    struct EqualityComparableCheck
    {
        BOOST_CONCEPT_USAGE(EqualityComparableCheck)
        {
            bool c = (a == b);
        }

    private:
        T a, b;
    };

    template<typename T>
    struct DefaultConstructibleCheck
    {
        BOOST_CONCEPT_USAGE(DefaultConstructibleCheck)
        {
            T u;
            T u1{};
            T();
            suppress_warning(T{});
        }
    };


    template<typename T>
    struct InputIteratorCheck : EqualityComparableCheck<T>
    {
        BOOST_CONCEPT_USAGE(InputIteratorCheck)
        {
            bool t = (i != j);
            *i;
            ++i;
            (void) i++;
            *i++;
        }

    private:
        T i, j;
    };

    template<typename T>
    struct ForwardIteratorCheck : InputIteratorCheck<T>, DefaultConstructibleCheck<T>
    {
        BOOST_CONCEPT_USAGE(ForwardIteratorCheck)
        {
            i++;
            *i++;
        }

    private:
        T i;
    };

   template<typename T>
    struct BidirectionalIteratorCheck : ForwardIteratorCheck<T>
    {
        BOOST_CONCEPT_USAGE(BidirectionalIteratorCheck)
        {
            --a;
            a--;
            *a--;
        }

    private:
        T a;
    };


    template<typename T>
    struct RandomAccessIteratorCheck : BidirectionalIteratorCheck<T>
    {
        BOOST_CONCEPT_USAGE(RandomAccessIteratorCheck)
        {
            r += n;
            a + n;
            n + a;
            r -= n;
            i - n;
            b - a;
            i[n];
            bool _ = (a < b); suppress_warning(_);
            _ = (a > b); suppress_warning(_);
            _ = (a >= b); suppress_warning(_);
            _ = (a <= b); suppress_warning(_);
        }

    private:
        T r;
        T i, a, b;
        typename std::iterator_traits<T>::difference_type n;
    };
}

#endif // RAI_CONCEPT_H
