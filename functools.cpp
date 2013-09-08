#include "functools.h"

#include <stdio.h>

namespace ft {

    void map_f( map_f_func map_fn, float *array, const int len ) {
        for ( int i = 0; i < len; i++ ) {
            //printf( ": %f\n", array[ i ] );
            array[ i ] = map_fn( &array[ i ] );
        }
    }

    void map_i( map_i_func map_fn, int *array, const int len ) {
        for ( int i = 0; i < len; i++ ) {
            array[ i ] = map_fn( (void*)( &array[ i ] ) );
        }
    }

    void map_scalar_f( float value, float *array, const int len ) {
        for ( int i = 0; i < len; i++ ) {
            array[ i ] = value;
        }
    }

    void map_scalar_i( int value, int *array, const int len ) {
        for ( int i = 0; i < len; i++ ) {
            array[ i ] = value;
        }
    }

    inline float zero_f()
    {
        return 0.0f;
    }

    inline int zero_i()
    {
        return 0;
    }

}
