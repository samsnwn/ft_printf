#include "ft_printf.h"

void edge_cases_tests()
{

	printf("------------------------------------------\n\n");
	printf("***** Edge Cases tests *****");
	printf("\n\n");

	ft_printf("My result: NO ARGS\n");
	printf("Expected Result: NO ARGS\n");
	ft_printf("My result: [%c]\n", ' ');
	printf("Expected result: [%c]\n", ' ');
	ft_printf("My result: [%%]\n");
	printf("Expected result: [%%]\n");
	ft_printf("My result: [%s]\n", NULL);
	// printf("My result: [%s]\n", NULL);
	// printf("Expected result: [%h]\n");

	printf("\n");
	printf("------------------------------------------\n");
}

void char_tests()
{
	char a = 'A';
	char b = 'B';
	printf("------------------------------------------\n\n");
	printf("***** Char tests *****");
	printf("\n\n");

	ft_printf("My result:         [%c]\n", a);
	printf("Expected Result:   [%c]\n", a);
	ft_printf("My result:         [%c, %c]\n", a, b);
	printf("Expected Result:   [%c, %c]\n", a, b);

	printf("\n");
	printf("------------------------------------------\n");
}

void string_tests()
{
	char *s1 = "First String";
	char *s2 = "Second string";

	printf("------------------------------------------\n\n");
	printf("***** String tests *****");
	printf("\n\n");

	ft_printf("My result:         [%s]\n", s1);
	printf("Expected Result:   [%s]\n", s1);
	ft_printf("My result:         [%s, %s]\n", s1, s2);
	printf("Expected Result:   [%s, %s]\n", s1, s2);
	ft_printf("My result:         [NULL %s NULL]\n", NULL);
	// printf("Expected Result:    [NULL %s NULL]\n", NULL);

	printf("\n");
	printf("------------------------------------------\n");
}

void digit_tests()
{
	int x = 42;
	int y = 1000;

	printf("------------------------------------------\n\n");
	printf("***** Digit tests *****");
	printf("\n\n");

	ft_printf("My result:         [%d]\n", x);
	printf("Expected Result:   [%d]\n", x);
	ft_printf("My result:         [%d, %d]\n", x, y);
	printf("Expected Result:   [%d, %d]\n", x, y);
	ft_printf("My Result:         [%u]\n", -2);
	printf("Expected Result:   [%u]\n", -2);

	printf("\n");
	printf("------------------------------------------\n");
}

void hexa_tests()
{
	int x = 42;
	int y = 1000;

	printf("------------------------------------------\n\n");
	printf("***** Hexa tests *****");
	printf("\n\n");

	if (ft_printf("My result:         [%x]\n", x) == printf("Expected Result:   [%x]\n", x))
		printf("PASSED!!\n\n");
	else 
		printf("NOT PASSED!!\n");
	if (ft_printf("My result:         [%x, %x]\n", x, y) == printf("Expected Result:   [%x, %x]\n", x, y))
		printf("PASSED!!\n\n");
	else 
		printf("NOT PASSED!!\n\n");
	if (ft_printf("My result:         [%X]\n", x) == printf("Expected Result:   [%X]\n", x))
		printf("PASSED!!\n\n");
	else 
		printf("NOT PASSED!!\n");
	if (ft_printf("My result:         [%X, %X]\n", x, y) == printf("Expected Result:   [%X, %X]\n", x, y))
		printf("PASSED!!\n\n");
	else 
		printf("NOT PASSED!!\n\n");

	printf("\n");
	printf("------------------------------------------\n");
}

void pointer_tests()
{
	char *p1 = "First String";


	printf("------------------------------------------\n\n");
	printf("***** Pointer tests *****");
	printf("\n\n");

	ft_printf("My result:         [%p]\n", p1);
	printf("Expected Result:   [%p]\n", p1);
	// ft_printf("My result:         [%p, %p]\n", p1, p2);
	// printf("Expected Result:   [%p, %p]\n", p1, p2);

	printf("\n");
	printf("------------------------------------------\n");
}

int main()
{
	edge_cases_tests();
  char_tests();
	string_tests();
	digit_tests();
	hexa_tests();
	pointer_tests();
  return 0;
}