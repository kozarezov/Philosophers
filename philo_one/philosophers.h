/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 14:23:49 by ceccentr          #+#    #+#             */
/*   Updated: 2020/10/27 11:40:23 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

# define STDERR 2
# define MAX_PHILO 200
# define PROG_NAME "Philo_one"

typedef struct		s_arg
{
	int				nbr_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_must_eat;
	int				have_six_arg;
	struct timeval	start_time;
	char			*error;
}					t_arg;

typedef struct		s_philo
{
	int				id;
	struct timeval	last_eat;
	int				left_fork;
	int				right_fork;
}					t_philo;

typedef struct		s_table
{
	pthread_mutex_t	forks[MAX_PHILO];
	pthread_mutex_t	work;
	int				is_dead;
}					t_table;

typedef struct		s_func
{
	struct s_philo	*philo;
	struct s_table	*table;
	struct s_arg	*arg;
	pthread_t		*threads;
}					t_func;

int					ft_strlen(const char *str);
void				ft_putstr_fd(char *s, int fd);
int					ft_atoi(char *str);
char				*ft_itoa(int n);
char				*ft_strjoin(char const *s1, char const *s2);

int					error_arguments(char *str);

int					main(int argc, char **argv);
int					parse_arguments(int argc, char **argv, t_arg *arguments);
void				*action(void *args);
void				init_all(t_arg *arguments, t_func *function);
int					ft_dead(t_philo *philo, t_func *function);
void				my_usleep(unsigned int millisec);
void				print_act(int time, int num, char *str, t_table *table);
void				destroy_mutex(t_arg *arguments, t_table *table);

#endif
