import cv2

if __name__ == '__main__':
    # Read Image
    img = cv2.imread('image.jpg')
    # Display Image
    cv2.imshow('image', img)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
    # Applying Grayscale filter to image
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    # Saving filtered image to new file
    cv2.imwrite('graytest.jpg', gray)
