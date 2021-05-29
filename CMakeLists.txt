cmake_minimum_required(VERSION 3.17)
project(philosophers C)

set(CMAKE_C_STANDARD 99)

add_executable(philosophers philo_three/main.c philo_three/philo_three.h philo_three/print.c philo_three/ft_atoi.c philo_three/validate_init.c
        philo_three/exit_func.c philo_three/philo_process.c philo_three/ft_itoa.c philo_three/exit_func.c philo_three/monitor.c philo_three/utils.c philo_three/monitor.c)

target_link_libraries(philosophers PUBLIC pthread)