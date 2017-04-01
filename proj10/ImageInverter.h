/* ImageInverter.h declares the ImageInverter class,
 *  which uses TSGL to invert a photographic image.
 *
 * Joel Adams, Fall 2015, for CS 112 at Calvin College.
 *
 * Note: We use int instead of unsigned throughout
 *       because of a bug in GCC/OpenMP.
 * Student name: Shurjo Maitra
 * Date: 5.9.16
 */

#ifndef IMAGEINVERTER_H_
#define IMAGEINVERTER_H_

#include <tsgl.h>      // Canvas, ColorInt, etc.
#include <omp.h>       // OpenMP functions
#include <unistd.h>    // sleep()

using namespace tsgl;
using namespace std;

class ImageInverter {
public:
  ImageInverter(const string& fileName, int width, int height);
  void invertImage();
  void wait()          { myCanvas0.wait(); }
  void colorReplaceImage();
  void lightenImage();

private:
  Canvas   myCanvas0;
  int      myWidth;
  int      myHeight;
  string   myFileName;
};

#endif /* IMAGEINVERTER_H_ */
