#include <stdio.h>
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}
int	ft_strcmp(char *s1, char *s2)
{
	int x = 0;
	while((s1[x] != '\0') && (s2[x] != '\0')&& (s1[x] == s2[x]))
		x++;
	return (s1[x] - s2[x]);

}
void ft_swap(char **s1, char **s2)
{
	char *box = *s1;
	*s1 = *s2;
	*s2 = box;
}
int main(int argc, char **argv)
{
	//STAMPO NUMERO DI ARGOMENTI PASSATI AL MAIN
	
	printf("Numero argomenti passati al main: %d\n", (argc - 1));
	int x = 1;
	int y;
	
	//PROVA DELLA FUNZIONE PUTCHAR
	/*char c = 'A';
	ft_putchar(c);
	ft_putchar('\n');*/
	
	//STAMPO TUTTI I NOMI DEI VARI ARGOMENTI PASSATI
	printf("Argomenti ancora da Ordinare\n");
	while(x < argc)
	{
		y = 0;
		while(argv[x][y] != '\0')
		{
			ft_putchar(argv[x][y]);
			y++;
		}
		ft_putchar('\n');
		x++;
	}

	//COMPARARE I VARI ARGOMENTI E ORDINARLI
        int ok = 0;
        while(!ok)
        {
           	ok = 1;
		int p = 1;
		while(p < (argc - 1))
		{     
                	int diff = ft_strcmp(argv[p], argv[p + 1]);
                	if(diff > 0)
               	 	{
                        	ft_swap(&argv[p],&argv[p + 1]);
                		ok = 0;
			}
                p++;
		}
	}
	
  	//STAMPO TUTTI I NOMI DEI VARI ARGOMENTI ORDINATI
	printf("Argomenti Ordinati\n");
	int z = 1;
	int w;
        while(z < argc)
        {
                w = 0;
                while(argv[z][w] != '\0')
                {
                        ft_putchar(argv[z][w]);
                        w++;
                }
                ft_putchar('\n');
                z++;
        }
	return(0);
}
