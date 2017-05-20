#include "opencv2\opencv.hpp"

#include "MCNet_FA.h"

#include<iostream>
#include<fstream>

int main(int argc, char **argv)
{
	
	const int str_length = 200;

	if (argc != 4)
	{
		std::cerr << "MCNet img_listfile facebbox_file res_file.\n";
		return 1;
	}

	std::ifstream listfile, facebbox_file;
	std::ofstream resfile;

	listfile.open(argv[1]);
	if (!listfile.is_open())
	{
		std::cerr << "Fail to open the image list file.\n";
		return 1;
	}

	facebbox_file.open(argv[2]);
	if (!facebbox_file.is_open())
	{
		std::cerr << "Fail to open the face boundingbox file.\n";
		return 1;
	}

	resfile.open(argv[3]);
	if (!resfile.is_open())
	{
		std::cerr << "Fail to open the result file.\n";
		return 1;
	}

	char path[str_length];
	double left, right, top, bottom;
	cv::Mat img, ptsMat;

	int count = 0;

	int64_t start, total;

	total = 0;

	while (!listfile.eof())
	{
		listfile.getline(path, str_length);

		img = cv::imread(path, CV_LOAD_IMAGE_GRAYSCALE);		

		facebbox_file >> left >> right >> top >> bottom;

		if (img.empty())
		{
			std::cerr << "Fail to open " << path << "\n";
			resfile << "\n";
			continue;
		}

		start = cv::getTickCount();

		face_alignment(img, ptsMat, left, right, top, bottom);

		total += (cv::getTickCount() - start);

		for (int i = 0; i < ptsMat.rows; i++)
		{
			for (int j = 0; j < ptsMat.cols; j++)
			{
				resfile << ptsMat.at<float>(i, j) << '\t';
			}
		}
		resfile << "\n";

		count++;

	}

	if (count > 0)
	{
		std::cout << "Processing " << count << " images, using " << total / count / cv::getTickFrequency() * 1000 << " ms averagely for each image.\n";
	}
	else
	{
		std::cout << "Processing " << count << " images.\n";
	}
	
	listfile.close();
	facebbox_file.close();
	resfile.close();

	return 0;

}