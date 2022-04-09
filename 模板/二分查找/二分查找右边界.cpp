int BSr( int n , int end ) {
    if ( end < 0 ) return -1;
    int left = 0;
    int right = end;
    while ( left < right ) {
        int mid = ( left + right ) / 2;
        if ( arr[mid] == n ) {
            left = mid + 1;
        }
        else if ( arr[mid] > n ) {
            right = mid;
        }
        else if ( arr[mid] < n ) {
            left = mid + 1;
        }
    }
    return ( arr[right-1] == n ) ? right - 1: -1; 
}