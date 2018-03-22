/*
	Date: 2018.3.19
	Author: 刘臣轩
*/

#include <assert.h>
#include <stdio.h>

int copy_int(int val, int maxbytes);

int main()
{
    int val = 0;
    assert(copy_int(val, -2) == 0);
    assert(copy_int(val, 0) == 0);
    assert(copy_int(val, 2) == 0);
    assert(copy_int(val, 4) == 1);
    assert(copy_int(val, 5) == 1);
    return 0;
}

int copy_int(int val, int maxbytes)
{
    return maxbytes > 0 && maxbytes >= sizeof(val);
}
