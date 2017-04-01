/* ImageInverter.cpp defines the ImageInverter methods
 *  that are declared in ImageInverter.h.
 *
 * Joel Adams, Fall 2015, for CS 112 at Calvin College.
 * Student name: Shurjo Maitra
 * Date: 5.9.16
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

	Canvas canvas1(-1, -1, myWidth, myHeight,
			myFileName + " Inverted, Chunk-Size 1");
	canvas1.start();

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
				canvas1.drawPixel(row, col,
						ColorInt(invertedR, invertedG, invertedB));
			}
		}
	}
	canvas1.wait();
}

/* method to replace colors in an image
 * Precondition: myCanvas0 contains a valid image.
 * Postcondition: canvas1 is displaying the colors replaced of the original image in myCanvas0.
 */
void ImageInverter::colorReplaceImage() {
	// record starting time
	double startTime = omp_get_wtime();

	Canvas canvas2(-1, -1, myWidth, myHeight,
			myFileName + " colorReplaced, Chunk-Size 1");
	canvas2.start();

	ColorInt pixelColor;

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
				// replace the color
				int replacedR = pixelColor.B;
				int replacedG = pixelColor.R;
				int replacedB = pixelColor.G;
				// replace color at the same spot in canvas2
				canvas2.drawPixel(row, col,
						ColorInt(replacedR, replacedG, replacedB));
			}
		}
	}

// compute and display the time difference
double time = omp_get_wtime() - startTime;
cout << "\n\nImage color replacement took " << time << " seconds.\n" << endl;

//save converted image
canvas2.takeScreenShot();
canvas2.wait();
}

/* method to lighten an image
 * Precondition: myCanvas0 contains a valid image.
 * Postcondition: canvas1 is displaying the lightened version of the image in myCanvas0.
 */
void ImageInverter::lightenImage() {
	// record starting time
	double startTime = omp_get_wtime();

	Canvas canvas3(-1, -1, myWidth, myHeight,
			myFileName + " colorReplaced, Chunk-Size 1");
	canvas3.start();

	ColorInt pixelColor;

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
				// lighten the color
				float correctionFactor = 0.5f;
				int lightenedR = (255 - pixelColor.R) * correctionFactor + pixelColor.R;
				int lightenedG = (255 - pixelColor.G)* correctionFactor + pixelColor.G;
				int lightenedB = (255 - pixelColor.B)* correctionFactor + pixelColor.B;
				// lighten color at the same spot in canvas2
				canvas3.drawPixel(row, col,
						ColorInt(lightenedR, lightenedG, lightenedB));
			}
		}
	}

// compute and display the time difference
double time = omp_get_wtime() - startTime;
cout << "\n\nImage lightening took " << time << " seconds.\n" << endl;

//save converted image
canvas3.takeScreenShot();
canvas3.wait();
}
