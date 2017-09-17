#include <stdio.h>

/*	当fahr=0，200，…，300是，打印华氏度与摄氏度对照表；
	℃ = (5/9)(℉-32)
	浮点数版本 
*/
int main()
{
	int fahr;//华氏度 
	float celsius;//摄氏度 
	
	int lower, upper;
	
	lower = 0;
	upper = 300;
	
	fahr = lower;
	while(fahr <= upper)
	{
		celsius = (5.0/9.0) * (fahr - 32);
		printf("%3d\t%6.1f\n", fahr, celsius);
		fahr += 20;
	}
}
