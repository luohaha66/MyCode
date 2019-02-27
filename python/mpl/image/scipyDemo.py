import scipy.misc
import matplotlib.pyplot as plt

if __name__ == '__main__':
    # load already prepared array from scipy
    face = scipy.misc.face()
    # convert to gray
    face = face[:, :, 0]
    # set the default colormap to gray
    plt.gray()
    # show original image
    plt.figure()
    plt.subplot(121)
    plt.imshow(face)

    # show 'zoomed' region
    z_face = face[100:350, 140:350]
    plt.subplot(122)
    plt.imshow(z_face)
    plt.show()
    
    print(face.shape)
    print(face.dtype)
    print(face.max())
