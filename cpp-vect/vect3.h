#ifndef _VECT3_HPP
#define _VECT3_HPP

#include <vector>
#include <cmath>
#include <fstream>
#include <cassert>
#include <iostream>
#include <cstdlib>

#include "vect.h"

template <typename T>
class vect<T, 3>
{
    public:
        T   data_[3];


        // Default constructor
        vect()
        {
            data_[0] = T(0);
            data_[1] = T(0);
            data_[2] = T(0);
        };

        vect( const T a)
        {
            data_[0] = a;
            data_[1] = a;
            data_[2] = a;
        };

        vect( const T a, const T b, const T c)
        {
            data_[0] = a;
            data_[1] = b;
            data_[2] = c;
        };

        // Copy constructor
        vect( const vect &a)
        {
            data_[0] = a[0];
            data_[1] = a[1];
            data_[2] = a[2];
        };

        // Create from other type
        template <typename S>
        vect( const vect<S,3> &a)
        {
            data_[0] = T(a[0]);
            data_[1] = T(a[1]);
            data_[2] = T(a[2]);
        }

        vect( T* ptr)
        {
            data_[0] = ptr[0];
            data_[1] = ptr[1];
            data_[2] = ptr[2];
        };

        // Destructor
        ~vect()
        {};

        // Member functions
        int     size            ()  const { return 3;}      // returns the size
        T&      operator[]      (int i) ;              //
        const T&      operator[]      (int i) const;              //
        vect&  operator=       ( const vect &);              // overloaded =
        vect&  operator=       ( const T );              // overloaded =
        vect&  operator+=      ( const vect &);              //
        vect&  operator-=      ( const vect &);              //
        vect&  operator/=      ( const T);
        vect&  operator*=      ( const T);
        T       norm            ();
        T       norm2           ();
        void    renormalise     ();

        vect&   set             ( const T, const T, const T);

        // Friend functions

        template <typename S>
        friend  vect<S,3>   operator+   ( const vect<S,3> &);      // unary +

        template <typename S>
        friend  vect<S,3>   operator-   ( const vect<S,3> &);      // unary -

        template <typename S>
        friend  vect<S,3>   operator+   ( const vect<S,3> &,       //
                                          const vect<S,3> &);      // binary +

        template <typename S>
        friend  vect<S,3>   operator+   ( const vect<S,3> &,       //
                                          const S &);              // + elementwise scalar +

        template <typename S>
        friend  vect<S,3>   operator-   ( const vect<S,3> &,       //
                                          const S &);              // + elementwise scalar +

        template <typename S>
        friend  vect<S,3>   operator-   ( const vect<S,3> &,
                                          const vect<S,3> &);      // binary -
        template <typename S>
        friend  vect<S,3>   operator*   ( const S,
                                          const vect<S,3> &);      // scalar multiply
        template <typename S>
        friend  vect<S,3>   operator*   ( const vect<S,3> &,
                                          const S);                // scalar multiply
        template <typename S>
        friend  vect<S,3>   operator/   ( const vect<S,3> &,
                                          const S);                // scalar divide
        template <typename S>
        friend  vect<S,3>   operator*   ( const vect<S,3> &,
                                          const vect<S,3> &);      // vector multiply
        template <typename S>
        friend  vect<S,3>   operator/   ( const vect<S,3> &,
                                          const vect<S,3> &);      // vector elementwise divide
        template <typename S>
        friend  S           dot         ( const vect<S,3> &,
                                          const vect<S,3> &);      // dot product

        template <typename S>
        friend  vect<S,3>   cross1       ( const vect<S,3> &,
                                          const vect<S,3> &);      // dot product
        template <typename S>
        friend  void   cross2       ( const vect<S,3> &,
                                          const vect<S,3> &,
                                          vect<S,3> &);      // dot product

        template <typename S>
        friend std::ostream& operator<<  ( std::ostream&,
                                           const vect<S,3>&);  // stream output



};

template <typename T>
T&  vect<T,3>::operator[]      ( int i )
{
    assert( (i < 3) && ( i >= 0) );
    return data_[i];
}

template <typename T>
const T&  vect<T,3>::operator[]      ( int i ) const
{
    assert( (i < 3) && ( i >= 0) );
    return data_[i];
}

template <typename T>
vect<T,3>& vect<T,3>::set (const T a, const T b, const T c)
{
    data_[0] = a;
    data_[1] = b;
    data_[2] = c;
    return *this;
}

template <typename T>
vect<T,3>& vect<T,3>::operator= (const vect<T,3>& a)
{
    if( this != &a)
    {
        data_[0] = a[0];
        data_[1] = a[1];
        data_[2] = a[2];
    }
    return *this;
}

template <typename T>
vect<T,3>& vect<T,3>::operator= (const T a)
{
    data_[0] = a;
    data_[1] = a;
    data_[2] = a;
    return *this;
}

template <typename T>
vect<T,3>& vect<T,3>::operator+= (const vect<T,3>& a)
{
    data_[0] += a[0];
    data_[1] += a[1];
    data_[2] += a[2];
    return *this;
}

template <typename T>
vect<T,3>& vect<T,3>::operator-= (const vect<T,3>& a)
{
    data_[0] -= a[0];
    data_[1] -= a[1];
    data_[2] -= a[2];
    return *this;
}

template <typename T>
vect<T,3>& vect<T,3>::operator/= ( const T a)
{
    data_[0] /= a;
    data_[1] /= a;
    data_[2] /= a;
    return *this;
}

template <typename T>
vect<T,3>& vect<T,3>::operator*= ( const T a)
{
    data_[0] *= a;
    data_[1] *= a;
    data_[2] *= a;
    return *this;
}

template <typename T>
T vect<T,3>::norm()
{
    T sum;
    sum = data_[0] * data_[0];
    sum += data_[1] * data_[1];
    sum += data_[2] * data_[2];
    return sqrt(sum);
}

template <typename T>
T vect<T,3>::norm2()
{
    T sum;
    sum = data_[0] * data_[0];
    sum += data_[1] * data_[1];
    sum += data_[2] * data_[2];
    return sum;
}

template <typename T>
void vect<T,3>::renormalise()
{
    T sum;
    sum = data_[0] * data_[0];
    sum += data_[1] * data_[1];
    sum += data_[2] * data_[2];
    sum = 1.0 / sqrt(sum);
    data_[0] *= sum;
    data_[1] *= sum;
    data_[2] *= sum;
}

template <typename T>
inline vect<T,3> operator+ (const vect<T,3> &a)
{
    return a;
}

template <typename T>
inline vect<T,3> operator- ( const vect<T,3> &a)
{
    return vect<T,3>() - a;
}

template <typename T>
vect<T,3> operator+ ( const vect<T,3> &a, const vect<T,3> &b)
{
    vect<T,3> sum = a;
    sum += b;
    return sum;
}

template <typename T>
vect<T,3> operator- ( const vect<T,3>& a, const vect<T,3> &b)
{
    vect<T,3> sum = a;
    sum -= b;
    return sum;
}

template <typename T>
vect<T,3> operator+ ( const vect<T,3> &a, const T &b)
{
    vect<T,3> sum = a;
    sum += b;
    return sum;
}

template <typename T>
vect<T,3> operator- ( const vect<T,3>& a, const T &b)
{
    vect<T,3> sum = a;
    sum -= b;
    return sum;
}

template <typename T>
vect<T,3> operator* ( T scalar, const vect<T,3> &a)
{
    vect<T,3> tm;
    tm[0] = a[0] * scalar;
    tm[1] = a[1] * scalar;
    tm[2] = a[2] * scalar;
    return tm;
}

template <typename T>
inline vect<T,3> operator* (const vect<T,3> &a, T scalar)
{
    return scalar*a;
}

template <typename T>
vect<T,3> operator* ( const vect<T,3> &a, const vect<T,3> &b)
{
    vect<T,3> tm;
    tm[0] = a[0] * b[0];
    tm[1] = a[1] * b[1];
    tm[2] = a[2] * b[2];
    return tm;
}

template <typename T>
vect<T,3>   operator/   ( const vect<T,3>& a, const T scalar)
{
    vect<T,3> tm;
    tm[0] = a[0] / scalar;
    tm[1] = a[1] / scalar;
    tm[2] = a[2] / scalar;
    return tm;

}

template <typename T>
vect<T,3> operator/ ( const vect<T,3> &a, const vect<T,3> &b)
{
    vect<T,3> tm;
    tm[0] = a[0] / b[0];
    tm[1] = a[1] / b[1];
    tm[2] = a[2] / b[2];
    return tm;
}

template <typename T>
inline T dot ( const vect<T,3> &a, const vect<T,3> &b)
{
    T tm;
    tm = a[0] * b[0];
    tm += a[1] * b[1];
    tm += a[2] * b[2];
    return tm;
}

template <typename T>
inline vect<T,3> cross1 ( const vect<T,3> &a, const vect<T,3> &b)
{
    vect<T,3> tm;
    tm[0] = a[1] * b[2] - a[2] * b[1];
    tm[1] = a[2] * b[0] - a[0] * b[2];
    tm[2] = a[0] * b[1] - a[1] * b[0];
    return tm;
}

template <typename T>
inline void cross2 ( const vect<T,3> &a, const vect<T,3> &b, vect<T,3> &c)
{
    c[0] = a[1] * b[2] - a[2] * b[1];
    c[1] = a[2] * b[0] - a[0] * b[2];
    c[2] = a[0] * b[1] - a[1] * b[0];
}

template <typename T>
std::ostream& operator<< ( std::ostream &s, const vect<T,3> &a)
{

    s << a[0] << "\t" << a[1] << "\t" << a[2] << "\t";
    return s;
}


#endif
