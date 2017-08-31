#include <stdio.h>

int main(int argc, char *args[])
{
    rename(args[1], args[2]);
}