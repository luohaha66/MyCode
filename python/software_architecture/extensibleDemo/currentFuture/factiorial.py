import operator
import functools
from concurrent.futures import ThreadPoolExecutor, as_completed

# concurrent.futures use thread or process to handle concurrent
# and use future obj to return value by async


def factorial(n):
    return functools.reduce(operator.mul, [i for i in range(1, n+1)])


def main():
    with ThreadPoolExecutor(max_workers=5) as executor:
        future_map = {
            executor.submit(factorial, n): n for n in range(10, 30)
        }
        for future in as_completed(future_map):
            num = future_map[future]
            print(f'Factorial of {num} is {future.result()}')


if __name__ == '__main__':
    main()
