/*
 * main.cpp is a driver for an ImageInverter program
 *  using OpenMP to parallelize the image processing
 *  and TSGL to view the processing in near real time.
 *
 * Author: Joel Adams, for CS 112 at Calvin College.
 * Date: March 2015.
 * Student name: Shurjo Maitra
 * Date: 5.9.16
 */

#include "ImageInverter.h"

int main() {
	omp_set_num_threads(16);
   ImageInverter inverter("pics/beads.jpg", 1024, 1024);
//   inverter.invertImage();
   inverter.colorReplaceImage();
   inverter.lightenImage();
   inverter.wait();

}
