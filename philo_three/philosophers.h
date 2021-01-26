/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ceccentr <ceccentr@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 14:23:49 by ceccentr          #+#    #+#             */
/*   Updated: 2020/12/01 10:16:19 by ceccentr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>
# include <unistd.h>
# include <stdlib.h>
# include <semaphore.h>
# include <sys/stat.h>
# include <stdint.h>
# include <signal.h>
# include <sys/time.h>
# include <fcntl.h>

# define STDERR 2
# define MAX_PHILO 200
# define PROG_NAME "Philo_three"

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
	int				is_dead;
}					t_arg;

sem_t				*g_eating;
sem_t				*g_dead;
sem_t				*g_forks;
sem_t				*g_count;
sem_t				*g_print;
int					g_count_eating;
struct timeval		g_last_eat;
t_arg				g_arg;

int					ft_strlen(const char *str);
void				ft_putstr_fd(char *s, int fd);
int					ft_atoi(char *str);
char				*ft_itoa(int n);
char				*ft_strjoin(char const *s1, char const *s2);

int					error_arguments(char *str);

int					main(int argc, char **argv);
int					parse_arguments(int argc, char **argv, t_arg *arguments);
void				init_all(t_arg *arguments);
int					ft_dead(struct timeval now, struct timeval last);
void				my_usleep(unsigned int millisec);
void				print_act(int time, int num, char *str);
void				exit_sim(void);
void				*action(void *arg);
char				*name_thread(int n);

#endif
