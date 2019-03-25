import datetime
from PIL import Image


def mandelbrot_calc_row(y, w, h, image, max_iteration=1000):
    """
    calculate one row of the mandelbrot ser with size y w h
    """
    # rescale to -1 to 1
    y0 = y * (2 / float(h)) - 1

    for x in range(w):
        # rescale to -2.5 to -1
        x0 = x * (3.5 / float(w)) - 2.5
        i, z = 0, 0 + 0j
        c = complex(x0, y0)
        while abs(z) < 2 and i < max_iteration:
            z = z ** 2 + c
            i += 1

        # color schema is that for julia sets
        color = (i % 8 * 32, i % 16 * 16, i % 32 * 8)

        image.putpixel((x, y), color)


# cost time 0:05:01.399970
def mandelbrot_calc_set(w, h, max_iteration=1000, out_put='mandelbrot.png'):
    """
    calculate a mandelbrot set given the width, height and maximum number f iterations
    """
    image = Image.new('RGB', (w, h))
    for y in range(h):
        mandelbrot_calc_row(y, w, h, image, max_iteration)
    image.save(out_put, 'PNG')


if __name__ == '__main__':
    a = datetime.datetime.now()
    mandelbrot_calc_set(640, 480, 10000)
    print('cost time', datetime.datetime.now() - a)
