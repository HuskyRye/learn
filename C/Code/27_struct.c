#include <stdio.h>
#include <string.h>

struct Student
{
	int age;
	char name[50];
	int score;
};

int main()
{
	struct Student stu1 = {18, "mike", 59};
	struct Student stu2;
	stu2.age = 16;
	strcpy(stu2.name, "mike");
	stu2.score = 59;

	struct Student *p;
	p = &stu2;

	(*p).age = 18;
	strcpy(p->name, "mike");
	p[0].score = 59;

	/*
	//structArray
	struct Student a[5];
	a[0].age = 18;
	strcpy(a[0].name, "mike");
	a[0].score =  59;
	
	(a+1)->age = 19;
	strcpy((a+1)->name, "mike");
	(a+1)->score = 59;

	(*(a+2)).age = 20;
	strcpy((*(a+2)).name, "mike");
	(*(a+2)).score = 59;

	struct Student *q = a;
	q[3].age = 21;
	strcpy(q[3].name, "mike");
	q[3].score =  59;

	(q+4)->age = 22;
	strcpy((q+4)->name, "mike");
	(q+4)->score = 59;
	*/

	//structArray
	struct Student a[5] =
		{
			{18, "mike", 60},
			{19, "mike", 71},
			{20, "mike", 82},
			{21, "mike", 99},
			{22, "mike", 100},
		};

	int i;
	int n = sizeof(a) / sizeof(a[0]);
	for (i = 0; i < n; ++i)
	{
		printf("%d, %s, %d\n", a[i].age, a[i].name, a[i].score);
	}

	int sum = 0;
	for (i = 0; i < n; ++i)
	{
		sum += a[i].score;
	}
	printf("average = %3.1lf\n", (double)sum / n);

	return 0;
}
