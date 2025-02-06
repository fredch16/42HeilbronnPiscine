/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:58:50 by fredchar          #+#    #+#             */
/*   Updated: 2025/02/04 17:23:12 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		add(int a, int b);
int		subtract(int a, int b);
int		multiply(int a, int b);
int		divide(int a, int b);
int		modulo(int a, int b);
int		ft_atoi(char *str);
void	ft_putnbr(int nbr);
void	ft_putstr(char *str);

int	get_operator_index(char *op)
{
	char	*operators;
	int		i;

	operators = "+-*/%";
	i = 0;
	while (i < 5 && op[0] != operators[i])
		i++;
	if (i == 5 || op[1] != '\0')
	{
		write(1, "0\n", 2);
		return (-1);
	}
	return (i);
}

int	handle_zero_division(char **av, int v2)
{
	if ((av[2][0] == '/' && v2 == 0) || (av[2][0] == '%' && v2 == 0))
	{
		if (av[2][0] == '/')
			ft_putstr("Stop : division by zero\n");
		else if (av[2][0] == '%')
			ft_putstr("Stop : modulo by zero\n");
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		v1;
	int		v2;
	int		res;
	int		(*op_func[5])(int, int);
	int		op_index;

	op_func[0] = add;
	op_func[1] = subtract;
	op_func[2] = multiply;
	op_func[3] = divide;
	op_func[4] = modulo;
	if (ac != 4)
		return (0);
	v1 = ft_atoi(av[1]);
	v2 = ft_atoi(av[3]);
	op_index = get_operator_index(av[2]);
	if (op_index == -1)
		return (0);
	if (!handle_zero_division(av, v2))
		return (0);
	res = op_func[op_index](v1, v2);
	ft_putnbr(res);
	write(1, "\n", 1);
	return (0);
}
