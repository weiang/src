#include <windows.h>
#include <stdio.h>

DWORD WINAPI find_prime(LPVOID param)
{
	DWORD num = *(DWORD *)param;
	DWORD i, j;
	if (num == 1) {
		printf("1 is neither a prime, nor a compesite!\n");
		return 0;
	}
	printf("The prime(<= %d): ", num);
	for (i = 2; i <= num; i ++) {
	       	DWORD flag = 0;
		for (j = 2; j * j <= i; j ++) 
			if (i % j == 0)
				flag = 1;
		if (!flag)
			printf("%d ", i);
	}
	printf("\n");
	return 0;
}

int main(int argc, char *argv[])
{
	DWORD	tid;
	HANDLE	thd;
	int	param;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <number>\n", argv[1]);
		return -1;
	}

	param = atoi(argv[1]);

	/* Create the thread */
	thd = CreateThread(
			NULL,
			0,
			find_prime,
			&param,
			0,
			&tid);

	if (thd != NULL) {
		WaitForSingleObject(thd, INFINITE);

		CloseHandle(thd);
	}
	return 0;
}
