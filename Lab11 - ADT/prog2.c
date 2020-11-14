#define _CRT_SECURE_NO_WARNINGS
#define N 5
#include <stdio.h>

void intSum(void *sum, void *num);
void intSub(void *sum, void *num);
void init(void *p);
int intComp(void *a, void *b);
int doIt(void *sum, void** array, void (*pInt)(void *), void(*pSum)(void*,void*), void(*pSub)(void*,void*), int(*pComp)(void*, void*));

int main()
{
 int num[] = {5,2,7,4,6,12,8}, itt = 0, ans;
 void *pNum[N];

 for (; itt < N; itt++)
 {
	 pNum[itt] = &num[itt];
 }
 ans = doIt(&ans, pNum, init, intSum, intSub, intComp);
 ans == 1 ? printf("The ans is 'Yes'") : printf("The ans is 'No'");
return 0;
}

void intSum(void *sum, void *num)
{
 *(int*)sum += *(int*)num;
}

void intSub(void *sum, void *num)
{
 *(int*)sum -= *(int*)num;
}

void init(void *p)
{
 *(int*)p = 0;
}

int intComp(void *a, void *b)
{
 return (*(int*)a == *(int*)b) ? 1 : 0;
}

int doIt(void *sum, void** array, void (*pInt)(void *), void(*pSum)(void*,void*), void(*pSub)(void*,void*), int(*pComp)(void*, void*))
{
	int itt = 0;
	pInt(sum);
	for (; itt < N; itt++)
	{
		if (pComp(sum, array[itt]))
    {
      return 1;
    }
		if (itt%2)
		{
			pSub(sum, array[itt]);
		}
		else
    {
      pSum(sum, array[itt]);
    }
	}
	return 0;
}
