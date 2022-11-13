#include "../headerspace/WatershedAlg.h"
using namespace cv;
void WatershedAlg::processImage(Mat &image,Mat &duplImage,int** threshmat0,int**  markers,bool** visArr,int* plotx,int *ploty,int** plots,bool** inprioq,int** markerMap,int** temp,int**  nextSet) {

       image = makeImageGrayScale(image);


       vector< vector<int> > erosionTargetThree{{1, 1, 1}, {1, 1, 1}, {1, 1, 1}, };
       image = erosion(image, erosionTargetThree);

        int** __restrict threshmat;
        threshmat= thresholdMeasure(image,threshmat0);

       int** __restrict antimat;
       antimat=antiInverseImage(threshmat,image.rows,image.cols);

	int** __restrict matimage;
        matimage=distanceTransform(antimat,markers,image.rows,image.cols,plots,visArr,plotx,ploty);
       image = watershed(matimage, markers,duplImage,image.rows,image.cols,inprioq,markerMap,temp,nextSet);
   cv::imshow("watershed result",image);
 cv::waitKey(0);

    }
