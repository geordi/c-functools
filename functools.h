#ifndef FUNCTOOLS_H__
#define FUNCTOOLS_H__

#include <algorithm>
#include <vector>

#include "defines.h"

namespace ft
{

    typedef float (*map_f_func)( float *arg );
    typedef int (*map_i_func)( void *arg );

    typedef REAL (*reduce_f_func)( REAL a, REAL b );

    void map_f( map_f_func map_fn, float *array, const int len );
    void map_i( map_i_func map_fn, int *array, const int len );
    void map_scalar_f( float value, float *array, const int len );
    void map_scalar_i( int value, int *array, const int len );

    template <typename T>
    bool is_in( const T val, const std::vector<T>& vec ) PURE_FN;

    template <typename T>
    bool is_in( const T val, const T *arr, const int len ) PURE_FN;

    template <typename T>
    T sum( T x, T y ) CONST_FN;

    template <typename T>
    T min_f( T x, T y ) CONST_FN;

    template <typename T>
    T max_f( T x, T y ) CONST_FN;

    // implementation

    template <typename T>
    void map_scalar( T value, T *array, const int len )
    {
        for ( int i = 0; i < len; i++ ) {
            array[ i ] = value;
        }
    }

    template <typename T>
    T reduce( reduce_f_func reduce_fn, const T *array, const int len )
    {
        T tmp = static_cast<T>( 0.0 );
        for ( int i = 0; i < len; i++ ) {
            tmp = reduce_fn( tmp, array[ i ] );
        }

        return tmp;
    }

    inline float zero_f();
    inline int zero_i();
    template <typename T>
    inline T zero()
    {
        return static_cast<T>( 0 );
    }

    template <typename T>
    T sum( T x, T y )
    {
        return x + y;
    }

    template <typename T>
    T min( T x, T y )
    {
        return std::min( x, y );
    }

    template <typename T>
    T max( T x, T y )
    {
        return std::max( x, y );
    }

    template <typename T>
    bool is_in( const T val, const std::vector<T>& vec )
    {
        for ( typename std::vector<T>::const_iterator it = vec.begin(); it != vec.end(); ++it )
        {
            if ( val == *it )
            {
                return true;
            }
        }

        return false;
    }

    template <typename T>
    bool is_in( const T val, const T *arr, const int len )
    {
        for ( int i = 0; i < len; i++ )
        {
            if ( val == arr[ i ] )
            {
                return true;
            }
        }

        return false;
    }

    //bool is_in( const int val, const int arr[], const int len );

}

#endif //FUNCTOOLS_H_
