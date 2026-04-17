#include <stdio.h>

int check(int n, int i) {
	if ( n < 2 ) {
		return 0;
	}
	if ( n == 2) {
		return 1;
	}

	if ( n % i == 0 ) {
		return 0;
	}
	if ( i * i > n ) {
		return 1;
	}
	return check(n, i + 1);
}

int main() {
	int n;
	printf("Nhap n: ");
	scanf("%d",&n);
	if ( check(n, 2) ) printf("la so nguyen to");
	else printf("khong phai so nguyen to");
	return 0;
}

