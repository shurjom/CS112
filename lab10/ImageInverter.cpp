/* ImageInverter.cpp defines the ImageInverter methods
 *  that are declared in ImageInverter.h.
 *
 * Joel Adams, Fall 2015, for CS 112 at Calvin College.
 */

#include "ImageInverter.h"

/* explicit constructor
 * @param fileName, a string.
 * @param width, an int.
 * @param height, an int.
 * Precondition: fileName contains the name of a valid image file
 *               && width contains the number of columns in that image
 *               && height contains the number of rows in the image.
 * Postcondition: myCanvas0 contains the image from fileName
 *               && myWidth == width
 *               && myHeight == height
 *               && myFileName == fileName
 */

ImageInverter::ImageInverter(const string& fileName, int width, int height) :
		myCanvas0(0, 0, width, height, fileName), myWidth(width), myHeight(
				height), myFileName(fileName) {
	myCanvas0.start();
	myCanvas0.drawImage(fileName, 0, 0, width, height);
	sleep(1);
}

/* method to invert an image
 * Precondition: myCanvas0 contains a valid image.
 * Postcondition: canvas1 is displaying the inverse of the image in myCanvas0.
 */

void ImageInverter::invertImage() {
	// record starting time
	double startTime = omp_get_wtime();

	Canvas canvas1(-1, -1, myWidth, myHeight, myFileName + " Inverted");
	canvas1.start();

	ColorInt pixelColor;

	// loop through the image rows
#pragma omp parallel for
	for (int row = 0; row < myHeight; row++) {
		// slow the processing to simulate a very large image
		myCanvas0.sleep();
		// loop through the image columns
		for (int col = 0; col < myWidth; col++) {
			// read the pixel at canvas1[row][col]
			pixelColor = myCanvas0.getPixel(row, col);
			// compute its inverse
			int invertedR = 255 - pixelColor.R;
			int invertedG = 255 - pixelColor.G;
			int invertedB = 255 - pixelColor.B;
			// draw the inverse at the same spot in canvas2
			canvas1.drawPixel(row, col,
					ColorInt(invertedR, invertedG, invertedB));
		}
	}
	// compute and display the time difference
	double time = omp_get_wtime() - startTime;
	cout << "\n\nImage inversion took " << time << " seconds.\n" << endl;

    //save converted image
    canvas1.takeScreenShot();
	canvas1.wait();
}

void ImageInverter::invertImage2() {

   Canvas canvas2(-1, -1, myWidth, myHeight, myFileName + " Inverted, Chunk-Size 1");
   canvas2.start();

   // launch additional threads
   #pragma omp parallel
   {
      ColorInt pixelColor;
      // how many workers do we have?
      unsigned numThreads = omp_get_num_threads();
      // which one am I?
      unsigned id = omp_get_thread_num();

      // loop through the image rows
      for (int row = id; row < myHeight; row += numThreads) {
         // slow the processing to simulate a very large image
         myCanvas0.sleep();
         // loop through the image columns
         for (int col = 0; col < myWidth; col++) {
            // read the pixel at canvas1[row][col]
            pixelColor = myCanvas0.getPixel(row, col);
            // compute its inverse
            int invertedR = 255 - pixelColor.R;
            int invertedG = 255 - pixelColor.G;
            int invertedB = 255 - pixelColor.B;
            // draw the inverse at the same spot in canvas2
            canvas2.drawPixel(row, col, ColorInt(invertedR,invertedG,invertedB) );
         }
      }
   }
   canvas2.wait();
}


void ImageInverter::invertImage3() {

   Canvas canvas3(-1, -1, myWidth, myHeight, myFileName + " Inverted, Equal-Sized Chunks ");
   canvas3.start();

   // launch additional threads
   #pragma omp parallel
   {
      ColorInt pixelColor;
      // how many workers do we have?
      unsigned numThreads = omp_get_num_threads();
      // which one am I?
      unsigned id = omp_get_thread_num();

      // compute size of chunks (iterations % numThreads may != 0)
      double iterations = myHeight;
      unsigned chunkSize = (unsigned)ceil(iterations / numThreads);
      // compute starting index
      int start = id * chunkSize;
      // compute stopping index
      int stop = 0;
      if (id < numThreads-1) {
          stop = start + chunkSize;
      } else {
          stop = myHeight;
      }
      // loop through image rows in equal-sized chunks
      for (int row = start; row < stop; row++) {
         // slow the processing to simulate a very large image
         myCanvas0.sleep();
         // loop through the image columns
         for (int col = 0; col < myWidth; col++) {
            // read the pixel at canvas1[row][col]
            pixelColor = myCanvas0.getPixel(row, col);
            // compute its inverse
            int invertedR = 255 - pixelColor.R;
            int invertedG = 255 - pixelColor.G;
            int invertedB = 255 - pixelColor.B;
            // draw the inverse at the same spot in canvas2
            canvas3.drawPixel(row, col, ColorInt(invertedR,invertedG,invertedB) );
         }
      }
   }
   canvas3.wait();
}
