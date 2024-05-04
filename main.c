#include <stdio.h>
#include "ft_printf.h"
#include "libft/libft.h"

int	main(void)
{
	printf("***** Integer tests *****\n");
	printf("\n");
	printf("width: 8 -> [%8d]\n", 42);                       // [      42]
	printf("Zero-padding, width: 8 ->[%08d]\n", 42);         // [00000042]
	printf("space -> [% d]\n", 42);                          // [ 42]
	printf("sign, zero-padding -> [%+08d]\n", 42);           // [+0000042]
	printf("left-padding(minus) -> [%-8d]\n", 42);           // [42      ]
	printf("width: 8, .2 padding -> [%8.2d]\n", 42);         // [      42]
	printf("sign, zero-padding, width: 8 ->[%+08d]\n", -42); // [-0000042]
	printf("\n\n");
	printf("------------------------------------------\n");

	printf("***** Hexadecimals tests *****\n");
	printf("\n");
	printf("width: 8 -> [%8x]\n", 42);            
	printf("Zero-padding, width: 8 ->[%08x]\n", 42);       
	printf("[%x]\n", 42);                         
	printf("left-padding(minus) -> [%-8x]\n", 42);        
	printf("sign, zero-padding, width: 8 ->[%+015X]\n", -42); 
	printf("\n\n");
	printf("------------------------------------------\n");

	printf("***** Unsigned decimals tests *****\n");
	printf("\n");
	printf("width: 8 -> [%u]\n", 42.65);            
	printf("Zero-padding, width: 8 ->[%08u]\n", 42.65);       
	printf("left-padding(minus) -> [%-8u]\n", 42.65);        
	printf("\n\n");
	printf("------------------------------------------\n");

	printf("***** Char tests *****\n");
	printf("[%c]\n", 'a');
	printf("[%8c]\n", 'a');
	printf("[%08c]\n", 'a');
	printf("[%-8c]\n", 'a');
	printf("\n");

	printf("\n\n");
	printf("------------------------------------------\n");

	printf("***** String tests *****\n");
	printf("\n");
	printf(".3 precision -> [%.3s]\n", "Hello World");                // [Hel]
	printf("width: 15, .3 precision -> [%15.3s]\n\n", "Hello World"); // [            Hel]
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