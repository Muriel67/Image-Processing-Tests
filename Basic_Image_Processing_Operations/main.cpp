#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;


int main()
{
	Mat img = imread("Capture.jpg"); 
	if (img.empty())
	{
		cout << "Error opening the file";
		return -1;
	}

	// resolution

	Mat lowRes, highRes;
	resize(img, lowRes, Size(img.cols / 2, img.rows / 2));
	resize(img, highRes, Size(img.cols * 2, img.rows * 2));

	// brightness adjustment

	Mat brightUp, brightDown;
	img.convertTo(brightUp, -1, 1, 50);
	img.convertTo(brightDown, -1, 1, -50);

	// contrast adjustment

	Mat contrastHigh, constrastLow;
	img.convertTo(contrastHigh, -1, 1.5, 0);
	img.convertTo(constrastLow, -1, 0.5, 0);

	// show results

	imshow("Origianl Image", img);

	//Resolution

	imshow("Low Resolution", lowRes);
	imshow("High Resolution", highRes);

	// brightness

	imshow("High Brightness", brightUp);
	imshow("Low Brightness", brightDown);

	// contrast

	imshow("Low Contrast", constrastLow);
	imshow("High Contrast", constrastLow);
	
	waitKey(0);
	destroyAllWindows();

	return 0;


}

