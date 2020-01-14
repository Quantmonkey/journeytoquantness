#include <iostream>
#include <cmath>
#include <cstdlib>

#include "uiuc/PNG.h"
#include "uiuc/HSLAPixel.h"
#include "ImageTransform.h"

/* ******************
(Begin multi-line comment...)

Write your name and email address in the comment space here:

Name: Oscar Lee Feng Qi
Email: Oscar9551@gmail.com

(...end multi-line comment.)
******************** */

using uiuc::PNG;
using uiuc::HSLAPixel;

PNG grayscale(PNG image) {
  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      HSLAPixel & pixel = image.getPixel(x, y);

      // `pixel` is a reference to the memory stored inside of the PNG `image`,
      // which means you're changing the image directly. No need to `set`
      // the pixel since you're directly changing the memory of the image.
      pixel.s = 0;
    }
  }

  return image;
}


PNG createSpotlight(PNG image, int centerX, int centerY) {
   for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      HSLAPixel & pixel = image.getPixel(x, y);

      //measures Euclidean distance
      unsigned eucl_dist = sqrt(pow((x - centerX),2) + pow((y - centerY),2));
      if ((0.005*eucl_dist) > 0.8) {
        pixel.l = (pixel.l * 0.2);
      }
      else {
        pixel.l = (pixel.l * (1 - 0.005*eucl_dist));
      }
    }
  } 
  return image;
  
}
 
PNG illinify(PNG image) {
  for (unsigned x = 0; x < image.width(); x++) {
      for (unsigned y = 0; y < image.height(); y++) {
        HSLAPixel & pixel = image.getPixel(x, y);

        int orig_hue = pixel.h;
        int orange_hue = 11;
        int blue_hue = 216;
        int outer_midpoint = (((360 - 216 + 11)/2) + 216);
        int inner_midpoint = ((((216 - 180) + (180 - 11))/2) + 11);

        if ((orig_hue < outer_midpoint) and (orig_hue >= inner_midpoint)) {
          pixel.h = blue_hue;
        }
        else {
          pixel.h = orange_hue;
        }
      }
    }
  return image;
}
 
PNG watermark(PNG firstImage, PNG secondImage) {
  unsigned int width {0};
  unsigned int height {0};
  if (firstImage.width() >= secondImage.width()) {
    width = secondImage.width();
  }
  else {
    width = firstImage.width();
  }

  if (firstImage.height() >= secondImage.height()) {
    height = secondImage.height();
  }
  else {
    height = firstImage.height();
  }

  for (unsigned x = 0; x < width; x++) {
      for (unsigned y = 0; y < height; y++) {
        HSLAPixel & firstpixel = firstImage.getPixel(x, y);
        HSLAPixel & secondpixel = secondImage.getPixel(x, y);

        if (secondpixel.l == 1.0) {
          if (firstpixel.l + 0.2 > 1.0) {
            firstpixel.l = (firstpixel.l + (1.0 - firstpixel.l));
          }
          else {
            firstpixel.l = (firstpixel.l + 0.2);
          }
        }
      }
  }
  return firstImage;
}
