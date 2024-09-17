#include <unistd.h>

void	ft_putchar(char c) 
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb) 
{
	if (nb < 0) {
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10) {
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10) ft_putchar(nb + 48);
}

void ft_foreach(int *tab, int length, void (*f)(int)) {
	int x = 0;
	while (x < (length - 1))
	{
		f(tab[x]);
		x++;
		ft_putchar('\n');
	}
}

int main(void)
{
	int array[] = {2, 3, 23, 21, 1984, 45, 87};
	ft_foreach(array, 7, &ft_putnbr);
	return (0);
}
