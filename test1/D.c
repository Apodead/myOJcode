#include<stdio.h>

int main(){
	char operation;
	printf("#include<stdio.h>\nint main()\n");
	printf("{\n\tint a,b;\n\tscanf(\"%%d%%d\",&a,&b);\n");
	printf("\tprintf(\"%%d\",a");
	operation = getchar();
	switch(operation){
		case 'P':
			operation='+';
			break;
		case 'S':
			operation='-';
			break;
		case 'M':
			operation='*';
			break;
		case 'D':
			operation='/';
			break;
		case 'A':
			operation='&';
			break;
		case 'O':
			operation='|';
			break;
		case 'E':
			operation='^';
			break;
	}
	putchar(operation);
	printf("b);\n\treturn 0;\n}");
	return 0;
}
