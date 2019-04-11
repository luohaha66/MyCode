
import zlib
from PIL import Image

im = Image.open('2.png')
imb = im.tobytes()
cb = zlib.compress(imb)
im1 = Image.frombytes('RGBA', im.size, zlib.decompress(cb))
with open('3.png', 'wb') as f:
    im1.save(f)
