# star_count
Counting the number of stars in a picture of the sky at night by grayscaling an image, </br>
then when a bright pixel is encountered, look around that pixel to see if it's darker, </br>
then it's assumed that that is a star.  It could be unreliable if there are a bunch of </br>
stars with different shapes.

Notice in the original image that there was some light pollution that would affect the filter.</br>
Using a gaussian filter (big help) and some "denoise" setting made the image much easier to process</br>
and my results would be more accurate.

Original image: </br>
![orig_image](https://s9.postimg.org/uyfi7bngr/orig.jpg)

Image with gaussian filter and "denoised": </br>
![gauss&denoised](https://s9.postimg.org/ssl7ctk0b/IMG_denoise_3030.jpg)
