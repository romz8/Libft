#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void red()
{
	printf("\033[1;33m");
}
void green()
{
	printf("\033[0;32m");
}
void blue()
{
	printf("\033[0;34m");
}
void reset () 
{
	printf("\033[0m");
}

void (delete_example)(void * sentence)
{
	if (!sentence)
		return ;
	free(sentence);
}

int main(void)
{
	unsigned long x =  0;
	int	i;
	char	c;
	int arr[] = {5, 32, 42, 50, 55, 65, 72, 78, 80, 90, 94,95, 97, 108, 115, 122, 126, 127, 128, 255}  ;
	printf("------ testing the char functions -------\n");
	printf("asc| letter | alpha | digit | alnum | ascii | print | toupper | tolower\n");
	while (x < sizeof(arr) / sizeof(arr[0]))
	{
		c = (char) arr[x];
		i = arr[x];
		printf("%i	%c	%i	%i	%i	%i	%i	%c	%c\n", i, c, ft_isalpha(i), ft_isdigit(i), ft_isalnum (i), ft_isascii(i), ft_isprint(i),ft_toupper(i), ft_tolower(c));	
		x++;
		}

	printf("------ testing the strchr and strrchr functions -------\n");
	printf(" -- test 1 ---\n");

	char *str = "this is the first test sentence of length 44";
	printf("%s\n \n", str);	
	
	printf("ft_strlen yields : %lu\n", ft_strlen(str));
	printf("ft_strchr for e yields :\n %s \n",ft_strchr(str,'e'));
	char *teste = "teste";
	printf("if 0x40 is address of teste, ft_strchr('teste', 'e') should yield 'este' and pointer 0x41 result is:\n %s \n origina pointer :%p \n returned pointer : %p \n",ft_strchr(teste,'e'), teste, ft_strchr(teste,'e'));
	printf("if 0x1 is address of 'teste' then ft_strchr('teste', '\\0') should yield 0x6 (5 char after), result is:\n%s\n returned pointer %p\n",ft_strchr("teste",'\0'), ft_strchr("teste",'\0'));
	printf("if 0x1 is address of 'teste' then strchr('teste', '\\0') should yield 0x6 (5 char after), result is:\n%s\n returned pointer %p\n",strchr("teste",'\0'), strchr("teste",'\0'));

	printf("\n\n\n --- now on strrchr -------\n");

    printf("if 0x40 is address of teste, ft_strrchr('teste', 'e') should yield 'e' and pointer 0x44 result is:\n %s \n origina pointer :%p \n returned pointer : %p \n",ft_strrchr(teste,'e'), teste, ft_strrchr(teste,'e'));
    printf("if 0x1 is address of 'teste' then ft_strrchr('teste', '\\0') should yield 0x6 (5 char after), result is:\n%s\n returned pointer %p\n",ft_strrchr("teste",'\0'), ft_strrchr("teste",'\0'));
    printf("if 0x1 is address of 'teste' then strrchr('teste', '\\0') should yield 0x6 (5 char after), result is:\n%s\n returned pointer %p\n",strrchr("teste",'\0'), strrchr("teste",'\0'));

	printf("\n---- test 2 : comparing sentence functions ---\n");
	char *s2 = "Love yourself, everybody else is already taken - Oscar Wilde";
	printf("this is comparing the first sentence to itslef : diff is : %i\n",ft_strncmp(str, str,ft_strlen(str)));
	printf("this is comparing the second  sentence to itslef : diff is : %i\n",ft_strncmp(s2, s2,ft_strlen(s2)));
	printf("this is comparing the firt & ft_strrchr(s1, t)  sentence to 8 term : diff is : %i\n",ft_strncmp(str, ft_strrchr(str,'t'),8));
	printf("this is comparing the second & first sentence to n = 88 : diff is : %i\n",ft_strncmp(s2, str, 88));
	char dst[8];
	printf("copying the first 8 characters of sentence 1 in  cpy with ft_strlcpy:\n size %lu\n text : %s\n",ft_strlcpy(dst, str, sizeof(dst)),dst);
	printf("\n --- test on strlcat ---\n\n");
	char dest[20] ="final";
	char src[12] ="destination";
	printf("this destination : %s  - size is 20 and length is : %lu\n", dest, ft_strlen(dest));
    printf("the source is: %s  - size is 11 and length is : %lu\n", src, ft_strlen(src));
	printf("applying ft_strlcat for size 3  we have return value : %lu and sentence is :\n %s \n", ft_strlcat(dest, src, 3), dest);
	printf("applying ft_strlcat for size 21 we have return value : %lu and sentence is :\n %s \n", ft_strlcat(dest, src, 21), dest);

	printf("\n\n ---- testing atoi ----\n");
	char *a = "42";
	char *y = "-42";
	char *z = "1258495634";
	char *u = "--42";
	char *t = "+42";
	char *w = "    		58497-abfc";
	printf("we have the value : %s %s %s %s %s %s\n", a, y, z, u, t, w);
	printf("ft_atoi yields : %i %i %i %i %i %i\n", ft_atoi(a), ft_atoi(y), ft_atoi(z), ft_atoi(u), ft_atoi(t), ft_atoi(w));
	printf("atoi yields : %i %i %i %i %i %i\n", atoi(a), atoi(y), atoi(z), atoi(u), atoi(t), atoi(w));
	printf("ft_atoi for \\001 2 is :%i \n",ft_atoi("\001 2"));
	printf("atoi for \\001 2 is :%i \n",atoi("\001 2"));

	printf("\n\n---- testing ft_strnstr NOT GOOOOOOD ------\n");
	printf("lookin for Oscar in s2 yields for 100 haracters with ft_strnstr: %s\n", ft_strnstr(s2, "Oscar",100)); 
	printf("lookin for Oscar in s2 yields for 10 haracters with ft_strnstr: %s\n", ft_strnstr(s2, "Oscar",10));
	printf("lookin for oscar in s2 yields for 100 haracters with ft_strnstr: %s\n", ft_strnstr(s2, "oscar",100));
	//printf("lookin for oscar in s2 yields for 100 haracters with ft_strnstr: %s\n", ft_strnstr(s2, NULL,100));
	//printf("lookin for Oscar in s2 yields for 100 haracters with strnstr: %s\n", strnstr(s2, "Oscar",100));
    //printf("lookin for Oscar in s2 yields for 10 haracters with strnstr: %s\n", strnstr(s2, "Oscar",10));
    //printf("lookin for oscar in s2 yields for 100 haracters with strnstr: %s\n", strnstr(s2, "oscar",100));

	char spm[25] = "Super Mario Bros";
	printf("lookin for Mario in 'Super Mario Bros' but  for 7 haracters (stops at 'M') with ft_strnstr: %s\n", ft_strnstr(spm, "Mario", 7));
	printf("lookin for Mario in 'Super Mario Bros' but  for 7 haracters (stops at 'M') with strnstr: %s\n", strnstr(spm, "Mario", 7));

	printf("--- test memset --\n\n");
	char ft_arr[10];
	char c_arr[10];
	printf("result for ft_memset and 'A' : %s \n", ft_memset(ft_arr, 'A', 2 * sizeof(char)));
	printf("result for memset and 'A' : %s \n", memset(c_arr, 'A', 2 * sizeof(char)));

	int ft_intarr[10];
    int  int_arr[10];
	ft_memset(ft_intarr, 1, 8 * sizeof(int));
	memset(int_arr, 1, 8 * sizeof(int));
	int x1 = 0;
	while (x1 < 10)
	{
		printf("result for ft_memset and 10 : %d \n", ft_intarr[x1]);
    	printf("result for memset and 10 : %d \n", int_arr[x1]);	
		x1++;
	}

	printf("---- testing bzero----\n\n");
	ft_bzero(ft_arr, 5);
	bzero(c_arr, 5);
	printf("result for ft_bzero : %s \n", ft_arr);
    printf("result for bzero : %s \n", c_arr);

	ft_bzero(ft_intarr, 8);
    bzero(int_arr, 8);
	x1 = 0;
    while (x1 < 10)
    {
        printf("result for ft_bzero and 8 : %d \n", ft_intarr[x1]);
        printf("result for bzerot and 8 : %d \n", int_arr[x1]);
        x1++;
    }

	printf("----- testing memcpy -----\n\n");
	char sr_arr[100] = "one test sentence to test";
	char f_dest[40];
	char *bad = NULL;
	printf("this is the result to see :\n %s\n", ft_memcpy(f_dest, sr_arr, 21));
	printf("this is the result to see :\n %s\n", memcpy(bad, bad, 21));

	printf("\n\n ---- testing memchr ----\n\n");
	char *res_ft_memchr = ft_memchr(sr_arr, 'c', 21);
	char *res_memchr = memchr(sr_arr, 'c', 21);
	printf("this is the ft_memchr res: \n %s\n", res_ft_memchr);
	printf("this is the ft_memchr res: \n %s\n", res_memchr);

	printf("\n\n ---- testing memcmp ----\n\n");
	printf("comparing the sentence 1 with itelf  with ft_memcmp yields : %i\n\n",ft_memcmp(str, str, 50));
	printf("comparing the sentence 1 with itelf  with memcmp yields : %i\n\n",memcmp(str, str, 50));
	printf("comparing the 2 sentences with ft_memcmp yields : %i\n\n",ft_memcmp(str, s2, 50));
	printf("comparing the 2 sentences with memcmp yields : %i\n\n",memcmp(str, s2, 50));

	printf("----- testing memmove -----\n\n");
    char *bad_move = NULL;
	char ft_mmve_dest[40];
	char mmve_dest[40];

    ft_memmove(ft_mmve_dest, sr_arr, 21);
    ft_memmove(bad_move, bad_move , 21);

    printf("this is the result to see :\n %s\n", ft_mmve_dest);
    printf("this is the result to see :\n %s\n",mmve_dest);

	char overlap1[100] = "Let's try to overlap this sentence";
	char overlap2[100] = "Let's try to overlap this sentence";
	printf("this is the sentence befre overlap : %s \n", overlap1);
	ft_memmove(overlap1 + 7, overlap1, 15);
	printf("this is the sentence with ft_memmove overlap : %s \n", overlap1);
	memmove(overlap2 + 7, overlap2, 15);
	printf("this is the sentence with memmove overlap : %s \n", overlap2);
	if (ft_strncmp(overlap1, overlap2, ft_strlen(overlap1)) == 0 && ft_memcmp(overlap1, overlap2, ft_strlen(overlap1)) == 0)
		printf("TRUE they are similar\n\n");

	printf("\n\n ------ Testing ft_calloc -------\n\n");
	int *ptr_int = ft_calloc(80, sizeof(int));
	int *ptr_ca_int = calloc(80, sizeof(int));

	i = 0;
	int j = 0;
	while (i < 80)
	{
		if (ptr_int[i] != ptr_ca_int[i])
			j++;
		i++;
	}
	printf("the nber of diff forr int is :%i\n",j);
	free(ptr_int);
	free(ptr_ca_int);

	char *ptr_char = ft_calloc(50, sizeof(char));
    char *ptr_cal_char = calloc(50, sizeof(char));
	i = 0;
	j = 0;
	while (i < 50)
    {
        if (ptr_char[i] != ptr_cal_char[i])
            j++;
        i++;
    }
    free(ptr_char);
    free(ptr_cal_char);
	printf("the nber of diff for string is :%i\n",j);

	printf("------ testing ft_strdup -----\n\n");
	char *stnce_strdup ="this is the test sentence for ft_strdup";
	char *dst_ft_strdup = ft_strdup(stnce_strdup);
	char *dst_strdup = strdup(stnce_strdup);
	printf("the sentence we compare is :\n %s \n the difference between strdup and ft are : %i\n",stnce_strdup,ft_strncmp(dst_ft_strdup, dst_strdup, ft_strlen(stnce_strdup)));
	printf("this is the sentence for \"\" input in ft_strdup:%s\n",ft_strdup(""));
	printf("this is the size received for \"\" input in ft_strdup:%lu\n",ft_strlen(ft_strdup("")));
	if (ft_strncmp(ft_strdup(""),strdup("") , 3) == 0)
		printf("ft_strdup and strdup are equal for \"\"\n");
	else
		printf("ft_strdup and strdup are NOT equal for \"\" \n");
	if (ft_strdup("") == NULL)
		printf("the result is NULL ptr\n");
	free(dst_ft_strdup);
	free(dst_strdup);
	
	printf("---- testing ft_substr-----\n\n");
	char *test_sub = "the substring starts here and goes on until here but then stop";
	char *str_sub = ft_substr(test_sub, ft_strlen(test_sub),27);
	printf("the original sentence is : %s \n", test_sub);
	printf("the sub sentence is : %s \n", str_sub);

	printf("---- testing ft_strjoin-----\n\n");
    char *test_cat1 = "this is the s1";
	char *test_cat2 = "this is the s2";
    char *str_concat = ft_strjoin(test_cat1, test_cat2);
    printf("the original sentences are : %s \n: %s\n", test_cat1, test_cat2);
    printf("the sub sentence is : %s \n", str_concat);
	free(str_sub);
	free(str_concat);


	printf("---- testing ft_strtrim-----\n\n");
    char *test_totrim = "nishbc this is the sentence to trimhbnsc";
    char *test_totrim2 = "niscabhscahnniscabhsah";
	char *test_totrim3 = "";
	char *test_totrim4 = "  \t \t \n   \n\n\n\t";
	char *test_set = "niscabh";
    char *str_trim = ft_strtrim(test_totrim, test_set);
	char *str_trim2 = ft_strtrim(test_totrim2, test_set);
	char *str_trim3 = ft_strtrim(test_totrim3, test_set);
	char *str_trim4= ft_strtrim(test_totrim4, test_set);
    printf("the original sentences 1 is : %s \n: and set is %s\n", test_totrim, test_set);
    printf("the sub sentence is : %s \n", str_trim);
	printf("the original sentences 2 : %s \n and set is: %s\n", test_totrim2, test_set);
    printf("the sub sentence is : %s \n", str_trim2);
	printf("the original sentences 3 is : %s \nand set is: %s\n", test_totrim3, test_set);
    printf("the sub sentence is : %s \n", str_trim3);
	printf("the original sentences 4 is : %s \nand set is: %s\n", test_totrim4, " \n\t");
    printf("the sub sentence is : %s \n", str_trim4);
	free(str_trim);
	free(str_trim2);
	free(str_trim3);
	free(str_trim4);

	printf("---- testing ft_split-----\n\n");
     char *test_tosplit = "this is, the sentence, we want to trim - at least we hope - as per ft_split";
     char c1 = ',';
     char c2 = ' ';
     char c3 = '-';
     //char c4 = ' ';
     char **matrix1 = ft_split(test_tosplit, c1);
	 char **matrix2 = ft_split(test_tosplit, c2);
	 char **matrix3 = ft_split(test_tosplit, c3);
	 //char **matrix4 = ft_split(test_tosplit, c4);

	 //printf("test sentence: %s\n", ft_substr(test_tosplit, 22, 530));
	 i = 0;
	 while (i < 4)
	 {
		printf("%s\n",matrix1[i]);
		if (!matrix1[i])
			free(matrix1[i]);
		i++;
	 }
	 i = 0;
     while (i < 18)
     {
        printf("%s\n",matrix2[i]);
        if (!matrix2[i])
            free(matrix2[i]);
        i++;
     }
	 i = 0;
     while (i < 4)
     {
        printf("%s\n",matrix3[i]);
        if (!matrix3[i])
            free(matrix3[i]);
        i++;
     }
	 blue();
	 printf("---- testing ft_itoa -----\n\n");
	 reset();
	 printf("%s\n", ft_itoa(33));
	 printf("%s\n", ft_itoa(-33));
	 printf("%s\n", ft_itoa(12345));
	 printf("%s\n", ft_itoa(-12345));
	 printf("%s\n", ft_itoa(156));
	 printf("%s\n", ft_itoa(-623));
	 printf("%s\n", ft_itoa(45));
	 printf("%s\n", ft_itoa(-0));
	 printf("%s\n", ft_itoa(-2147483648));
	 printf("%s\n", ft_itoa(2147483647));
	 printf("%s\n", ft_itoa(0));

	 blue();
	 printf("\n\n ---- testing ft_put ----\n\n");
	 reset();
	 char *test_put ="this is the sentence to test put functions";
	 printf("testing ft_puthcar on the first char we have :\n"); 
	 ft_putchar_fd(test_put[0], 1); 
	 printf("\ntesting ft_putstr on the we have :\n");
	 ft_putstr_fd(test_put, 1);
	 printf("\n\n\ntesting ft_putendl  we have ");
	 ft_putendl_fd(test_put, 1);

	 blue();
	 printf("\n\n ---- testing ft_putnbr ----\n\n");
	 reset();
	 ft_putnbr_fd(33, 1);
	 printf("\n");
	 ft_putnbr_fd(-33, 1);
	 printf("\n");
     ft_putnbr_fd(12345, 1);
	 printf("\n");
     ft_putnbr_fd(-12345, 1);
	 printf("\n");
     ft_putnbr_fd(9876542, 1);
	 printf("\n");
     ft_putnbr_fd(-2147483648, 1);
	 printf("\n");
     ft_putnbr_fd(2147483647, 1);
	 printf("\n");
     ft_putnbr_fd(0, 1);
     printf("\n");
	 
	 red();
	 printf("\n\n\n\n ------- BONUS : LIST PART ----------\n\n\n");
	 reset();
	 
	 t_list* node_0 = ft_lstnew(0);
	 t_list* node_min = ft_lstnew(-2147483648);
	 t_list* node_weird = ft_lstnew("cvxnuudgdhdaubiibcr123456");
	 
	 printf("result for 0 is %i: p %p\n", (int) node_0->content, node_0);
	 printf("result for min integer is %i :p %p\n",(int) node_min->content, node_min);
	 printf("result for weird text  is %i:p %p\n", (int) node_weird->content, node_weird);
	 
	 t_list *head;
	 t_list **dble_head;
	 head = node_0;
	 dble_head = &head;
	 ft_lstadd_front(dble_head, node_min);
	 ft_lstadd_front(dble_head, node_weird);
	 
	 int list_size = ft_lstsize(head);
	 printf("\n\n the size of the list is:%i\n", list_size);
	 t_list *last_node = ft_lstlast(head);
	 printf("\nthe last node of the list is:%i p: %p\n", (int) last_node->content, last_node);
	 
	 //adding another node witht he lst_add_back at the end
	 t_list *node_8 = ft_lstnew(8);
	 printf("\nwe created the isolated node of value : %i :p: %p\n", (int) node_8->content, node_8);
	 ft_lstadd_back(dble_head, node_8);
	 last_node = ft_lstlast(head);
	 list_size = ft_lstsize(head);
	 printf("now that we added node_weird at the end the last node is: %i :p %p \n and the size is :%i\n",(int) last_node->content, last_node, list_size);
	 t_list *solo = last_node;
	 int solo_size = ft_lstsize(solo);
	 printf("\nthe size for just one node is :%i\n", solo_size);
	 printf(" Applying ft_lstdelone to node_weird yield:\n");
	 
	 void (*del_function)(void *);
	 del_function = &delete_example;

	 ft_lstdelone(node_min, del_function);
	 printf("result for 0 is %i: p %p\n", (int) node_0->content, node_0);
     printf("result for min integer is %i :p %p\n",(int) node_min->content, node_min);
     printf("result for weird text  is %i:p %p\n", (int) node_weird->content, node_weird);
	 printf("result for weird text  is %i:p %p\n", (int) node_8->content, node_8);
	 free(node_0);
	 free(node_min);

	 return 0;
}
