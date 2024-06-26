/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:40:50 by nsakanou          #+#    #+#             */
/*   Updated: 2024/06/17 20:57:56 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	update_last_meal_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->last_meal_time_mtx);
	philo->last_meal_time = get_current_time();
	pthread_mutex_unlock(&philo->last_meal_time_mtx);
}

static void	count_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->count_eaten_mtx);
	philo->count_eaten++;
	pthread_mutex_unlock(&philo->count_eaten_mtx);
}

void	philo_eating(t_philo *philo)
{
	take_forks(philo);
	print_message("is eating", philo);
	update_last_meal_time(philo);
	wait_for_action(philo, philo->data->args.time_to_eat);
	count_eat(philo);
	release_forks(philo);
}
