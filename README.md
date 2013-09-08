c_functools
===========

Very simple functions operating on C arrays to mimic functional style of programming.

Example Usage
-------------

```cpp
#include <stdio.h>

#include "functools.h"

#define N 10


int main( int argc, char **argv )
{
    int *array_int = new int[ N ];
    REAL *array_real = new REAL[ N ];
    REAL sum = REALV( 0.0 );
    REAL array_max = REALV( 0.0 );

    // Set int array elements to 0.
    ft::map_scalar( 0, array_int, N );

    // Alternatively called with function that returns zero.
    // This is slower.
    ft::map_scalar( ft::zero<int>(), array_int, N );

    // Fastest way to set array elements to 0 without templates.
    ft::map_scalar_i( 0, array_int, N );


    // Set array elements to 1.0
    ft::map_scalar_f( REALV( 1.0 ), array_real, N );

    // Get the sum of the array.
    for ( int i = 0; i < N; i++ )
    {
        array_real[ i ] = REALV( i + 1 );
    }

    printf( "Array: " );

    for ( int i = 0; i < N; i++ )
    {
        printf( "%4.2f ", array_real[ i ] );
    }

    printf( "\n" );

    sum = ft::reduce( ft::sum, array_real, N );

    printf( "Sum of the array: %4.2f\n", sum );

    // Get the maximum element value from array.
    array_max = ft::reduce( ft::max, array_real, N );

    printf( "Max of the array: %4.2f\n", array_max );

    delete[] array_int;
    delete[] array_real;

    return 0;
}
```

