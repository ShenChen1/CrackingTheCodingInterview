//A和B是两个有序数组(假设为递增序列)，而且A的长度足以放下A和B中所有的元素， 
//写一个函数将数组B融入数组A，并使其有序。

#include <stdio.h>

void show(int a[], int n)
{
	int i;
	for(i = 0; i < n; i++) 
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int merge(int a[], int an, int b[], int bn, int amax)
{
	int idx;
	int i, j;
	
	
	if(amax < an + bn)
		return -1;

	idx = an + bn - 1;
	i = an -1;
	j = bn -1;

	while(idx)
	{
		if(a[i] < b[j])
		{
			a[idx] = b[j];
			j--;
		}
		else
		{
			a[idx] = a[i];
			i--;
		}
		idx--;
	}
	return 0;
}

int main()
{
	int a[10] = {1,3,4,5,7,21};
	int b[4] ={1,3,6,8};

	show(a, 10);	
	show(b, 4);

 	merge(a, 6, b, 4, 10);
	
	show(a, 10);
}


