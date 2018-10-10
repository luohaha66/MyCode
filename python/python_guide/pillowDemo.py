from PIL import Image, ImageFilter

if __name__ == '__main__':
    # Read image
    im = Image.open('image.jpg')
    print(im.format, im.size, im.mode)
    # Display image
    im.show()
    # Applying a filter to the image
    im_sharp = im.filter(ImageFilter.SHARPEN)
    # Saving the filtered image to a new file
    im_sharp.save('image_sharpened.jpg', 'JPEG')
    # Splitting the image into its respective bands, i.e. Red, Green,
    # and Blue for RGB
    r, g, b = im_sharp.split()
