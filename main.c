#include <stdio.h>
#include "ft_printf.h"
int main()
{
//    int a = 65; 
//       char b = 'b'; 

// printf("%c\n",b, a);
// ft_printf("%%% \n",b, a);
printf("=====>%d",ft_printf("%+d",100));
printf("\n=====================\n");
printf("=====>%d",printf("%+d",100));
}