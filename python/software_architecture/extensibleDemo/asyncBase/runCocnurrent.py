import asyncio
import time


async def say_after(delay, what):
    await asyncio.sleep(delay)
    print(what)


async def run_concurrent():
    """
    started at 21:07:36
    hello
    world
    finished at 21:07:38
    """
    # The asyncio.create_task() function to run
    # coroutines concurrently as asyncio Tasks
    task1 = asyncio.create_task(
        say_after(1, 'hello'))
    task2 = asyncio.create_task(
        say_after(2, 'world'))
    print(f"started at {time.strftime('%X')}")
    # Wait until both tasks are completed (should take
    # around 2 seconds.), rather than 3 seconds, they run concurrent
    # awaitable objects: coroutines, Tasks, and Futures
    await task1
    await task2
    print(f"finished at {time.strftime('%X')}")

if __name__ == '__main__':
    asyncio.run(run_concurrent())
