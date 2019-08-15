#include <stdio.h>
//#include <time.h>
#define MAX 231

int cnt;
int key[MAX];
long long int value[MAX];

long long int change(int n) {
	long long int tot;
	int flag = 1;
	if(n <= 11) {
		tot = n;
	}
	else {
		for(int i = 0; i < cnt; ++i) {
			if(key[i] == n) {
				tot = value[i];
				flag = 0;
//				printf("hit %d %d\n", n, tot);
				break;
			}
		}
		if(flag) {
			tot = change(n/2) + change(n/3) + change(n/4);
//			printf("%d %d %lld\n",cnt, n, tot  );
			key[cnt] = n;
			value[cnt++] = tot;
		}
	}

	return tot;
}

int main(void) {
	int n;
	scanf("%d", &n);
	printf("%lld",change(n));
//	clock_t time = clock();
//	printf("\n%.4f", time/1000000.0);
//	printf("\n%d", cnt);
	return 0;
}
