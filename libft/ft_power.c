unsigned long	ft_power(unsigned long nbr, unsigned long pow)
{
	unsigned long i;
	unsigned long tmp;

	i = 1;
	tmp = nbr;
	if (pow == 0)
		return (1);
	while (i < pow)
	{
		nbr = nbr * tmp;
		i++;
	}
	return (nbr);
}
