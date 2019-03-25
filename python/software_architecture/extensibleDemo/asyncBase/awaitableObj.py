"""
We say that an object is an awaitable object if it can be used in an await expression.
Many asyncio APIs are designed to accept awaitables.
There are three main types of awaitable objects: coroutines, Tasks, and Futures.
"""

import asyncio


# ----------Coroutines
# Python coroutines are awaitables and therefore can be awaited from other coroutines
async def nested():
    return 42


async def run_coroutine():
    # Nothing happens if we just call "nested()".
    # A coroutine object is created but not awaited,
    # so it *won't run at all*.
    # nested()

    # Let's do it differently now and await it:
    print(await nested())  # will print "42".


# -----------tasks
# Tasks are used to schedule coroutines concurrently.
async def run_task():
    # Schedule nested() to run soon concurrently
    # with "main()".
    task = asyncio.create_task(nested())
    # "task" can now be used to cancel "nested()", or
    # can simply be awaited to wait until it is complete:
    await task


# ----------futures
# A Future is a special low-level awaitable object that
# represents an eventual result of an asynchronous
# operation
# When a Future object is awaited it means that the
# coroutine will wait until the Future is resolved in some
# other place


async def factorial(name, number):
    f = 1
    for i in range(2, number + 1):
        print(f"Task {name}: Compute factorial({i})...")
        await asyncio.sleep(1)
        f *= i
        print(f"Task {name}: factorial({i}) = {f}")


async def run_concurrent():
    # Schedule three calls *concurrently*:
    await asyncio.gather(
        factorial("A", 2),
        factorial("B", 3),
        factorial("C", 4),
    )


# wait() schedules coroutines as Tasks automatically and later returns those implicitly created
# Task objects in (done, pending) sets. Therefore the following code won’t work as expected:


if __name__ == '__main__':
    asyncio.run(run_concurrent())
