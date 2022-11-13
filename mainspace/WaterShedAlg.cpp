 #include "../headerspace/WatershedAlg.h"
 #include<iostream>
 using namespace std;
 using namespace cv;
 #include <time.h>
 int main(){



    cv::Mat srcImg=cv::imread("../image/pexels-sagui-andrea-618833.jpg");
    int rows=srcImg.rows;
    int cols=srcImg.cols;

     cv::Mat duplImage(srcImg.rows,srcImg.cols,CV_8UC3,Scalar::all(0));
     srcImg.copyTo(duplImage);

     if(!srcImg.data){

        cout<<"The file is not loaded or does not exist"<<endl;
        return -1;


     }
/****Buffer allocation****/
   int **threshmat=new int*[rows];
   for(int i=0;i<rows;i++){

      threshmat[i]=new int[cols];

   }

  int **markers=new int*[rows];
          for(int i=0;i<rows;i++){
              markers[i]=new int[cols];

          }


   #pragma omp parallel for
        for(int i=0;i<rows;i++){
         #pragma omp parallel for
           for(int j=0;j<cols;j++){
               markers[i][j]=0;

                }
        }




        bool** visArr=new bool*[rows];
       // #pragma omp parallel for
        for(int i=0;i<rows;i++){
             visArr[i]=new bool[cols];
        }


        int* plotx=new int[rows*cols];
        int* ploty=new int[rows*cols];



        memset(plotx,-1,sizeof(int)*rows*cols);
        memset(ploty,-1,sizeof(int)*rows*cols);




   int **plots=new int*[rows];
   for(int i=0;i<rows;i++){
     plots[i]=new int[cols];
   }



       bool** __restrict inprioq=new bool*[rows];
       int** __restrict markerMap=new int*[rows];
      // #pragma omp parallel for
      for(int i=0;i<rows;i++){
          inprioq[i]=new bool[cols];
         // markerMap[i]=new int[cols];
       }

           for(int i=0;i<rows;i++){
           markerMap[i]=new int[cols];
          // markerMap[i]=new int[cols];
       }





     #pragma omp parallel for
        for(int i=0;i<rows;i++){
         #pragma omp parallel for
         for(int j=0;j<cols;j++){
           inprioq[i][j]=false;
          markerMap[i][j]=0;

           }
          }

int **temp=new int*[rows*cols];

for(int i=0;i<rows*cols;i++){

     temp[i]=new int[3];

}


int **nextSet= new int*[rows*cols*9];
for(int i=0;i<rows*cols*9;i++){

 nextSet[i]=new int[3];

}

/****Buffer allocation****/
   clock_t start1,end1;
    double start,end;
    start1=clock();
    start=omp_get_wtime();
     WatershedAlg *walg=new WatershedAlg();
     walg->processImage(srcImg,duplImage,threshmat,markers,visArr,plotx,ploty,plots,inprioq,markerMap,temp,nextSet);
     end=omp_get_wtime();
     end1=clock();
     //cout<<"CLOCKS_PER_SEC :"<<CLOCKS_PER_SEC<<endl;
     cout<<"The total time the parallel  algorithm used is :"<<(double)(end - start)<<"s"<<endl;
     cout<<"The total time the algorithm used is :"<<(double)(end1 - start1)/CLOCKS_PER_SEC<<endl;
     delete walg;
     return 0;
   } 
