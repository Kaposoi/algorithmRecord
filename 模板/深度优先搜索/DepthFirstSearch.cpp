int array[1000][1000];                       // 数组的容量可任取。
void DepthFirstSerach( int x , int y )             // 在数组中搜索，因此变量是数组的下标。
{
    int PointerlocationX,PointerlocationY;
    for( int i = -1 ; i <= 1 ; i++ )
    {
        for( int j = -1 ; j <= 1 ; j++ )     // 指定搜索方向。
        {
            if( PointerlocationX > 0 && PointerlocationY > 0 /* && * / /* 条件：若不越界 */ ) // 如果数组不越界，且未碰见墙。则继续此方向搜索.
            {
                DepthFirstSerach( PointerlocationX , PointerlocationY );
            }
        }
    }
    return;
}