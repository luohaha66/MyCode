"""

Main mandelbrot program using Celery as the distributed, concurrent task queue

"""

import datetime
from celery import group
from PIL import Image
from software_architecture.extensibleDemo.aMQP.mandelbrot_tasks import mandelbrot_calc_row


def mandelbrot_main(w, h, max_iterations=1000, output='mandelbrot_celery.png'):
    """ Main function for mandelbrot program with celery """

    # group is a collection of task which can be exec
    job = group([mandelbrot_calc_row.s(y, w, h, max_iterations) for y in range(h)])
    # use apply_async to exec all tasks async
    result = job.apply_async()

    image = Image.new('RGB', (w, h))

    # use join to wait obj result
    for image_rows in result.join():
        for k, v in image_rows.items():
            k = int(k)
            # celery return the data as str, so they need convert to int
            v = tuple(map(int, v))
            x, y = k % w, k // w
            image.putpixel((x, y), v)

    image.save(output, 'PNG')
    print('Saved to', output)


if __name__ == "__main__":
    a = datetime.datetime.now()
    mandelbrot_main(640, 480, 10000)
    print('cost time', datetime.datetime.now() - a)
