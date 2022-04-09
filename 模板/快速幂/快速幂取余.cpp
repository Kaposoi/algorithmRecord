#include <stdio.h>
long long int quickpow( long long int a , long long int n , long long mod ){
    if ( !n ){
        return 1;
    }
    else if ( !( n % 2 ) ){
        long long int temp = quickpow( a , n / 2 , mod );
        return temp * temp % mod;
    }
    else if( n % 2 ){
        return quickpow( a , n - 1 , mod ) * a % mod;
    }
}
int main(){
    long long int a , n , mod;
    scanf( "%lld%lld%lld" , &a , &n , &mod );
    printf( "%lld^%lld mod %lld=%lld" , a , n , mod , quickpow( a , n , mod ) );
    return 0;
}