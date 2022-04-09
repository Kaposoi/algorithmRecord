#include <stdio.h>
long long int quickpow( long long int a , long long int n ){
    if ( !n ){
        return 1;
    }
    else if ( !( n % 2 ) ){
        long long int temp = quickpow( a , n / 2 );
        return temp * temp;
    }
    else if( n % 2 ){
        return quickpow( a , n - 1 ) * a ;
    }
}
