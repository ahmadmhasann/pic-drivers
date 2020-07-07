#include <stdio.h>


struct myStruct {
	char s1;
	char s2;
	int s3;
	float s4;
};

int main() {
	struct myStruct data = {1,2,3,4};
	char x;
	#define SIZE sizeof(data)

	/*printf("Address of x %d", &x);
	printf("\nAddress of s1 %d", &data.s1);
	printf("\nAddress of s2 %d", &data.s2);
	printf("\nAddress of s3 %d", &data.s3);
	printf("\nAddress of s4 %d", &data.s4);
	printf("\nsize of float %d", sizeof(float));
	printf("\nsize of int %d", sizeof(int));*/
	
	int arr[sizeof(data)];
	
}