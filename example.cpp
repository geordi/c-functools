#include <stdio.h>

#include "functools.h"

#define N 10


int main( int argc, char **argv )
{
    int *array_int = new int[ N ];
    float *array_real = new float[ N ];
    float sum = 0.0f;
    float array_max = 0.0f;

    // Set int array elements to 0.
    ft::map_scalar( 0, array_int, N );

    // Alternatively called with function that returns zero.
    // This is slower.
    ft::map_scalar( ft::zero<int>(), array_int, N );

    // Fastest way to set array elements to 0 without templates.
    ft::map_scalar_i( 0, array_int, N );


    // Set array elements to 1.0
    ft::map_scalar_f( 1.0f, array_real, N );

    // Get the sum of the array.
    for ( int i = 0; i < N; i++ )
    {
        array_real[ i ] = static_cast<float>( i + 1.0f );
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

