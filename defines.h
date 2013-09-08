#ifndef DEFINES_H__
#define DEFINES_H__

#define REAL float
#define REALV( x ) static_cast<REAL>( ( x ) )

#define CONST_FN __attribute__ ((const))
#define PURE_FN __attribute__ ((pure))

#endif // DEFINES_H__
