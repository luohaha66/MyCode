import os
import mimetypes
import datetime
from PIL import Image
from concurrent.futures import ThreadPoolExecutor, as_completed


def thumbnail(pic, size=(64, 64)):
    """save thumbnail for an image URL"""
    try:
        img = Image.open(pic)
        img.thumbnail(size, Image.ANTIALIAS)

        # get filename
        base_name = os.path.basename(pic)
        thumb_name = os.path.join('thumbs', '{}_thumb.png'.format(base_name.rsplit('.')[0]))
        img.save(thumb_name)
        return True
    except Image.DecompressionBombError:
        print(f'converting file {pic} failed')


def directory_walker(start_dir):
    """
    walk a directory and generate list of valid images
    """
    for root, _, files in os.walk(start_dir):
        for f in files:
            filename = os.path.join(root, f)
            file_type = mimetypes.guess_type(filename)[0]
            if file_type:
                if file_type.startswith('image/'):
                    yield filename


# cost time 0:00:11.238294
def concurrent_and_async():
    with ThreadPoolExecutor(max_workers=5) as executor:
        future_map = {
            executor.submit(thumbnail, pic): pic for pic in directory_walker('wuwu')
        }
        for future in as_completed(future_map):
            if future.result():
                print(f'Thumbnail of {future_map[future]} saved')


# cost time 0:00:25.334307
def step_by_step():
    for pic in directory_walker('wuwu'):
        if thumbnail(pic):
            print(f'Thumbnail of {pic} saved')


if __name__ == '__main__':
    a = datetime.datetime.now()
    # concurrent_and_async()
    step_by_step()
    print('cost time', datetime.datetime.now() - a)
