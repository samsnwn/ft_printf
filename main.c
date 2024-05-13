#include <stdio.h>
#include "ft_printf.h"
#include "libft/libft.h"

int	main(void)
{
	// Zero padding, sign, hash and space are only allowed for nmumbers 
	//  width and left padding are allowed for all types
	// Width does not allow any kind of truncation 
	printf("\n");
	// Integer base 10 tests
	printf("***** Integer base 10 tests *****\n");
	printf("\n");
	printf("No flags -> [%i]\n", 42);                         // [42]
	printf("width: 8 -> [%8i]\n", 42);                       // [      42]
	printf("sign, width: 8 -> [%+8i]\n", 42);                // [     +42]
	printf("Zero-padding, width: 8 ->[%08i]\n", 42);         // [00000042]
	printf("Sign, Zero-padding, width: 8 ->[%+08i]\n", 42);  // [+0000042]
	printf("space -> [% i]\n", 42);                          // [ 42]
	printf("space, yero-padding, width: 10 -> [% 010i]\n", 42); // [ 000000042]
	printf("left-padding(minus) -> [%-8i]\n", 42);           // [42      ]
	printf("left-padding(minus), sign -> [%-+8i]\n", 42);      // [+42     ]
	printf("width: 8, .2 padding -> [%8.2i]\n", 42);         // [      42]
	printf("sign, zero-padding, width: 8 ->[%+08i]\n", -42); // [-0000042]
	printf("\n\n");
	printf("------------------------------------------\n");

	// Decimal base 10 tests
	printf("***** Decimal base 10 tests *****\n");
	printf("\n");
	printf("width: 8 -> [%8d]\n", 42);            
	printf("Zero-padding, width: 8 ->[%08d]\n", 42);       
	printf("[%d]\n", 42);                         
	printf("left-padding(minus) -> [%-8d]\n", 42);        
	printf("sign, zero-padding, width: 15 ->[%015d]\n", -42); 
	printf("\n\n");
	printf("------------------------------------------\n");

	// Unsigned decimals base 10 tests
	printf("***** Unsigned decimals base 10 tests *****\n");
	printf("\n");
	printf("width: 8 -> [%u]\n", 54);            
	printf("Zero-padding, width: 8 ->[%08u]\n", 54);       
	printf("left-padding(minus) -> [%-8u]\n", 54);        
	printf("\n\n");
	printf("------------------------------------------\n");

	// Hexadecimals base 16 tests
	printf("***** Hexadecimals base 16 tests *****\n");
	printf("\n");
	printf("No flags -> [%x]\n", 1990);            
	printf("Hash - >[%#x]\n", 1990);            
	printf("width: 8 -> [%8x]\n", 1990);            
	printf("Hash, Zero-padding, width: 8 ->[%#08x]\n", 1990);       
	printf("left-padding(minus) -> [%-8x]\n", 1900);        
	printf("zero-padding, width: 15 ->[%015x]\n", -1990); 
	printf("\n\n");
	printf("------------------------------------------\n");

// Hexa UPPERCASE base 16 tests
	printf("***** Hexadecimals UPPERCASE base 16 tests *****\n");
	printf("\n");
	printf("No flags -> [%X]\n", 1990);            
	printf("Hash - >[%#X]\n", 1990);            
	printf("width: 8 -> [%8X]\n", 1990);            
	printf("Hash, Zero-padding, width: 8 ->[%#08X]\n", 1990);       
	printf("left-padding(minus) -> [%-8X]\n", 1900);        
	printf("zero-padding, width: 15 ->[%015X]\n", -1990); 
	printf("\n\n");
	printf("------------------------------------------\n");

	// For chars and strings only width and left padding are allowed
	// Char tests
	// ft_printf("***** Char tests *****\n");
	// ft_printf("\n");
	ft_printf("[%c]\n", 'a');
	ft_printf("[%8c]\n", 'a');
	ft_printf("[%-8c]\n", 'a');
	// ft_printf("\n\n");
	// ft_printf("------------------------------------------\n");
 
	// String tests
	printf("***** String tests *****\n");
	printf("\n");
	printf(".3 precision -> [%.3s]\n", "Hello World");                // [Hel]
	printf("width: 15, .3 precision -> [%15.3s]\n\n", "Hello World"); // [            Hel]
	printf("\n\n");
	printf("------------------------------------------\n");

	// VOID pointer tests
	void *ptr;
	ptr = "Hello World";

	printf("***** Void pointer tests *****\n");
	printf("\n");
	printf("[%p]\n", ptr);
	printf("[%20p]\n", ptr);
	printf("\n\n");
	printf("------------------------------------------\n");

	// printf("[%+8.4s]\n", "Hello World");
	// warning: flag '+' results in undefined behavior with 's' conversion specifier : [    Hell]
	// printf("[%015.3s]\n", "Hello World");
	// warning: flag '0' results in undefined behavior with 's' conversion specifier[000000000000Hel]
	// printf("[%-08d]\n", 42);
	// warning: flag '0' is ignored when flag '-' is present : [42      ]
	return (0);
}

// void compare_testing_results()
// {
// 	if (printf("width: 8 -> [%8d]\n", 42) == ft_printf("width: 8 -> [%8d]\n", 42))
// 		printf("OK\n");
// 	else
// 		printf("KO\n");
// }