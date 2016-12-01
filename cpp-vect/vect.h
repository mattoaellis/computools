#ifndef _VECT_HPP
#define _VECT_HPP

#include <vector>
#include <cmath>
#include <fstream>
#include <cassert>
#include <iostream>
#include <cstdlib>

template <typename T, int N>
class vect
{
    public:
        T   data_[N];


        // Default constructor
        vect()
        { for( int i = 0; i < N; i++) data_[i] = T(0);
        };

        vect( const T a)
        { for( int i = 0; i < N; i++) data_[i] = a;
        };

        // Copy constructor
        vect( const vect &a)
        { for( int i = 0; i < N; i++) data_[i] = a[i];
        };

        vect( T* ptr)
        { for( int i = 0; i < N; i++) data_[i] = ptr[i];
        };

        // Destructor
        ~vect()
        {};

        // Member functions
        int     size            ()  const { return N;}      // returns the size
        T&      operator[]      (int i) ;              //
        const T&      operator[]      (int i) const;              //
        vect&  operator=       ( const vect &);              // overloaded =
        vect&  operator=       ( const T );              // overloaded =
        vect&  operator+=      ( const vect &);              //
        vect&  operator-=      ( const vect &);              //
        vect&  operator/=      ( const T);
        T       norm            ();
        T       norm2           ();
        void    renormalise     ();


        // Friend functions

        template <typename S, int M>
        friend  vect<S,M>   operator+   ( const vect<S,M> &);      // unary +

        template <typename S, int M>
        friend  vect<S,M>   operator-   ( const vect<S,M> &);      // unary -

        template <typename S, int M>
        friend  vect<S,M>   operator+   ( const vect<S,M> &,       //
                                          const vect<S,M> &);      // binary +
        template <typename S, int M>
        friend  vect<S,M>   operator-   ( const vect<S,M> &,
                                          const vect<S,M> &);      // binary -
        template <typename S, int M>
        friend  vect<S,M>   operator*   ( const S,
                                          const vect<S,M> &);      // scalar multiply
        template <typename S, int M>
        friend  vect<S,M>   operator*   ( const vect<S,M> &,
                                          const S);                // scalar multiply
        template <typename S, int M>
        friend  vect<S,M>   operator/   ( const vect<S,M> &,
                                          const S);                // scalar divide
        template <typename S, int M>
        friend  vect<S,M>   operator*   ( const vect<S,M> &,
                                          const vect<S,M> &);      // vector multiply
        template <typename S, int M>
        friend  S    dot         ( const vect<S,M> &,
                                   const vect<S,M> &);      // dot product

        template <typename S, int M>
        friend std::ostream& operator<<  ( std::ostream&,
                                           const vect<S,M>&);  // stream output



};

template <typename T, int M>
T&  vect<T,M>::operator[]      ( int i )
{
    assert( (i < M) && ( i >= 0) );
    return data_[i];
}

template <typename T, int N>
const T&  vect<T,N>::operator[]      ( int i ) const
{
    assert( (i < N) && ( i >= 0) );
    return data_[i];
}

template <typename T, int M>
vect<T,M>& vect<T,M>::operator= (const vect<T,M>& a)
{
    if( this != &a)
    {
        for( int i = 0; i < M; i++) data_[i] = a[i];
    }
    return *this;
}

template <typename T, int M>
vect<T,M>& vect<T,M>::operator= (const T a)
{
    for( int i = 0; i < M; i++) data_[i] = a;
    return *this;
}

template <typename T, int N>
vect<T,N>& vect<T,N>::operator+= (const vect<T,N>& a)
{
    for( int i = 0; i < N; i++) data_[i] += a[i];
    return *this;
}

template <typename T, int N>
vect<T,N>& vect<T,N>::operator-= (const vect<T,N>& a)
{
    for( int i = 0; i < N; i++) data_[i] -= a[i];
    return *this;
}

template <typename T, int N>
vect<T,N>& vect<T,N>::operator/= ( const T a)
{
    for( int i = 0; i < N; i++) data_[i] /= a;
    return *this;
}

template <typename T, int N>
T vect<T,N>::norm()
{
    T sum = 0.;
    for( int i = 0; i < N; i++) sum += data_[i] * data_[i];
    return sqrt(sum);
}

template <typename T, int N>
T vect<T,N>::norm2()
{
    T sum = 0.;
    for( int i = 0; i < N; i++) sum += data_[i] * data_[i];
    return sum;
}

template <typename T, int N>
void vect<T,N>::renormalise()
{
    T sum = 0.;
    for( int i = 0; i < N; i++) sum += data_[i] * data_[i];
    sum = 1.0 / sqrt(sum);
    for( int i = 0; i < N; i++) data_[i] *= sum;
}




template <typename T, int N>
inline vect<T,N> operator+ (const vect<T,N> &a)
{
    return a;
}

template <typename T, int N>
inline vect<T,N> operator- ( const vect<T,N> &a)
{
    return vect<T,N>() - a;
}



template <typename T, int N>
vect<T,N> operator+ ( const vect<T,N> &a, const vect<T,N> &b)
{
    vect<T,N> sum = a;
    sum += b;
    return sum;
}

template <typename T, int N>
vect<T,N> operator- ( const vect<T,N>& a, const vect<T,N> &b)
{
    vect<T,N> sum = a;
    sum -= b;
    return sum;
}

template <typename T, int N>
vect<T,N> operator* ( T scalar, const vect<T,N> &a)
{
    vect<T,N> tm;
    for( int i = 0; i < N; i ++) tm[i] = a[i] * scalar;
    return tm;
}

template <typename T, int N>
inline vect<T,N> operator* (const vect<T,N> &a, T scalar)
{
    return scalar*a;
}

template <typename T, int N>
vect<T,N> operator* ( const vect<T,N> &a, const vect<T,N> &b)
{
    vect<T,N> tm;
    for( int i = 0; i < N; i ++) tm[i] = a[i] * b[i];
    return tm;
}

template <typename T, int N>
inline T dot ( const vect<T,N> &a, const vect<T,N> &b)
{
    T tm;
    for( int i = 0; i < N; i ++) tm += a[i] * b[i];
    return tm;
}

template <typename T, int N>
std::ostream& operator<< ( std::ostream &s, const vect<T,N> &a)
{

    for( int i = 0; i < N; i ++) s << a[i] << "\t";
    return s;
}


#endif
