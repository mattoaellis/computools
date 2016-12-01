#ifndef __VECT3N_H__
#define __VECT3N_H__

#include <vector>

template < typename T >
class vect3N {
    public:
        size_t          N_;
        std::vector<T>  x_;
        std::vector<T>  y_;
        std::vector<T>  z_;

        //Default constructor
        vect3N() {};

        vect3N( const size_t size)
            : N_(size),
            x_(size, T(0)),
            y_(size, T(0)),
            z_(size, T(0)) {};

        vect3N( const size_t size, const T a)
            : N_(size),
            x_(size, a),
            y_(size, a),
            z_(size, a) {};

        vect3N( const size_t size, const T a, const T b, const T c)
            : N_(size),
            x_(size, a),
            y_(size, b),
            z_(size, c) {};

        // Copy constructor
        vect3N( const vect3N &a)
            : N_(a.N_), x_( a.x_), y_( a.y_), z_( a.z_)
        {};

        // Destructor
        ~vect3N()
        {};

};



#endif
