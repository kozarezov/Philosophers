# Philosophers - проект школы 21
## Описание:

Проект направленный на изучение многопоточности в языке Си.
Решение задачи обедающих философов Дейкстры.

Реализованы 3 подхода:
* philo-one
    - разрешено использовать mutex
    - вилки слева и справа от философов
* philo-two
    - разрешено использовать semaphore
    - вилки по центру стола
* philo-three
    - разрешено использовать semaphore
    - вилки по центру стола
    - разрешено использовать fork
    - у каждого философа должен быть свой процесс 

