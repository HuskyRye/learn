#include <stdio.h>
#include <string.h>

void write_file();
void read_file();
int calc(int a, char c, int b);

int main()
{
    write_file();
    read_file();

    //system("pause");
    return 0;
}

void write_file()
{
    FILE *fp = fopen("test.txt", "w");

    fputs("10+10=\n", fp);
    fputs("10-10=\n", fp);
    fputs("10*10=\n", fp);
    fputs("10/10=\n", fp);

    fputs("10+5=\n", fp);
    fputs("10-5=\n", fp);
    fputs("10*3=\n", fp);
    fputs("10/2=\n", fp);

    fclose(fp);
    fp = NULL;
    return;
}

void read_file()
{
    FILE *fp = fopen("test.txt", "r");
    char buf[100];
    char tmp[1024 * 4] = {0};
    while (fgets(buf, sizeof(buf), fp) && !feof(fp))
    {
        int a, b;
        char c;
        sscanf(buf, "%d%c%d=\n", &a, &c, &b);
        //printf("%s", buf);

        sprintf(buf, "%d%c%d=%d\n", a, c, b, calc(a, c, b));
        //strcat(tmp, buf);
        strncat(tmp, buf, sizeof(buf));
    }

    fclose(fp);

    fp = fopen("test.txt", "w");
    fputs(tmp, fp);
    fclose(fp);
    fp = NULL;

    return;
}

int calc(int a, char c, int b)
{
    switch (c)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
}