#ifndef WATERSHEDALG_H
#define WATERSHEDALG_H

//#include "../structPixel/structPixel.cpp"
#include<iostream>
#include <fstream>
#include <opencv2/opencv.hpp>
#include<queue>
#include <vector>
#include<random>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <queue>
#include<string>
#include <cstdlib>
#include<omp.h>
using namespace cv;
using namespace std;
#define ZERO 0
#define ONE 254
#define STEP 1
//#include <opencv2/imgcodecs.hpp>
class WatershedAlg{

public:
Mat makeImageGrayScale(Mat &image);
Mat inverseImage(Mat &image);
Mat erosion(Mat &image, vector< vector <int> > &kernel);
int** thresholdMeasure(Mat &image,int **thrshmat0);
int** antiInverseImage(int** threshmat,int &rows,int &cols);
int** distanceTransform(int** matArr, int** markers,int &rows,int &cols,int** plots,bool** visArr,int* plotx,int* ploty); 
Mat watershed(int** image, int **markers,Mat &duplImage,int &rows,int &cols,bool** inprioq,int** markerMap,int** temp,int** nextSet);
void removeholesopt(int** src, int &pnumlThrshold, int &handlingType, int &neighbourType,int pixelThreshhold,int &rows,int &cols);
void processImage(Mat &image,Mat &duplImage,int** threshmat,int**  markers,bool** visArr,int* plotx,int *ploty,int** plots,bool** inprioq,int** markerMap,int** temp,int**  nextSet) ;
};
#endif
