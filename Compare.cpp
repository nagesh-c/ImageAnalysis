#include <opencv2\highgui\highgui.hpp>
#include <iostream>
#include <conio.h>

using namespace cv;
using namespace std;

int main(int argc,char *argv)
{
	long int i=0,j=0,k=0;
	cout<<"frame"<<"\t"<<"tp"<<"\t"<<"fp"<<"\t"<<"tn"<<"\t"<<"fn"<<"\t"<<"precision"<<"\t"<<"pwc"<<"\t"<<"prc"<<endl;
	long int tp=0;fp=0;fn=0;tn=0;
	if(argc < 3)
	{
		cout<<"Usage: ./a.out image1.jpg image2.jpg"<<endl;
		exit(-1);
	}	
	Mat img1 = imread(argv[1],CV_LOAD_IMAGE_GRAYSCALE);
	Mat img2 = imread(argv[2],CV_LOAD_IMAGE_GRAYSCALE);
	if(img1.empty()||img2.empty())
	{
		cout<<"either of the image is empty"<<endl;
		getch();
		return -1;
	}
	int width_i = img1.step[0];
	int width_j = img1.step[1];
	for(i=0;i<img1.rows;i++)
		{
			for(j=0;j<img1.cols;j++)
			{
				if(img1.data[i*width_i+j*width_j] == 255){
					if(img2.data[i*width_i+j*width_j] == 255)
						tp++;
				}
				if(img1.data[i*width_i+j*width_j] == 255){
					if(img2.data[i*width_i+j*width_j] != 255)
						fn++;
				}
				if(img1.data[i*width_i+j*width_j]==0){
					if(img2.data[i*width_i+j*width_j]!=0)
						fp++;
				}
				if(img1.data[i*width_i+j*width_j]==0){
					if(img2.data[i*width_i+j*width_j]==0)
						tn++;
				}
			}
		double precision = (tp/(double)(tp+fp));
		double pwc = ((fn+fp)/(double)(tp+fn+fp+tn))*100.0;
		double prc = 100-pwc;
		std::cout<<x<<"\t"<<tp<<"\t"<<fp<<"\t"<<tn<<"\t"<<fn<<"\t"<<precision<<"\t"<<pwc<<"\t"<<prc<<endl;
	}
	getch();
	return 0;
}
