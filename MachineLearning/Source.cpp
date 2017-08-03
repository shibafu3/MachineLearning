#ifdef _DEBUG
//Debugモードの場合
#pragma comment(lib,"C:\\opencv\\build\\x86\\vc12\\lib\\opencv_world300d.lib")            // opencv_core
#else
//Releaseモードの場合
#pragma comment(lib,"C:\\opencv\\build\\x86\\vc12\\lib\\opencv_world300.lib") 
#endif

#include <iostream>
#include <fstream>
#include <iomanip>
/*数値計算ライブラリ*/
#define _USE_MATH_DEFINES
#include <math.h>
/*可変長リストライブラリ*/
#include <vector>
/*OpenCVライブラリ*/
#include "opencv2/opencv.hpp"
#include <opencv2/core/core.hpp>
#include "opencv2/highgui/highgui_c.h"
#include "opencv2/opencv.hpp"
#include <vector>
#include <opencv2/objdetect/objdetect.hpp>


using namespace std;
using namespace cv;

int main(){
	// 画像の取得
	//Mat image = imread("C:\\chessboard.jpg");
	//if (image.empty()){
	//	return -1;
	//}
	
	// カスケード分類器の取得
	CascadeClassifier cascade;
	if (!cascade.load("C:\\ALLLBP03.xml")){
		return -1;
	}

	// カスケード分類器で顔の探索
	const double SCALE_FACTOR = 1.05;
	const int MIN_NEIGHBORS = 3;
	const Size MIN_OBJECT_SIZE = Size(50, 50);
	vector<Rect> faces;
	///////////////////
	Mat image;
	char image_name[100];
	for (int i = 0; i < 10001; i++){
		sprintf_s(image_name, "C:\\learning\\pos\\%04d.jpg", i);
		image = imread(image_name);

		if (image.empty()) {
			cout << "no image : " << image_name << endl;
			continue;
		}
	/////////////////////////

	cascade.detectMultiScale(image, faces, SCALE_FACTOR, MIN_NEIGHBORS, CV_HAAR_SCALE_IMAGE, MIN_OBJECT_SIZE);

	// 顔探索した結果を描画
	for (vector<Rect>::const_iterator itr = faces.begin(); itr != faces.end(); ++itr) {
		rectangle(image, Point(itr->x, itr->y), Point(itr->x + itr->width, itr->y + itr->height), Scalar(0, 0, 200), 3, CV_AA);
	}
	resize(image, image, Size(), 0.5, 0.5);
	// 結果表示
	imshow("Detected", image);
	waitKey(0);	
	///////
	}
	/////////
	// 入力待機
	return 0;
}