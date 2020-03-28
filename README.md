This face alignment tool is based on Caffe [1]. It is the C++ implementation of our method MCNet. The testing code of the conference version of MCNet can be found [here](https://github.com/ZhiwenShao/MCNet). 

It is a Microsoft Visual Studio 2013 solution "MCNet.sln". 

You need to change the include path, library path, and additional dependencies of OpenCV according to your own installation path and version of OpenCV in "C/C++ -> General -> Additional Include Directories", "Linker -> General -> Additional Library Directories", and "Linker -> Input -> Additional Dependencies" of "Project -> Properties -> Configuration Properties" respectively.


Prerequisites:

1. OpenCV, any version is applicable

2. Microsoft Visual Studio 2013 or a later version 


Usuage:

MCNet img_listfile facebbox_file res_file

Input:
- "img_listfile " is a file that contains the path of images. 
- "facebbox_file " is a file that contains corresponding face bounding boxes.

Output:
- "res_file" is a file that contains the predicted facial landmark locations.


Format:

Format of the img_listfile:
Each line is the path of a face image.

Format of the facebbox_file:
Each line contains left, right, top and bottom of the face bounding box corresponding to the image in the img_listfile.

Format of the outputFile:
Each line contains x coordinate and y coordinate of predicted 68 facial landmarks (x1 y1 x2 y2 ...).


Example:

MCNet IBUG_path.txt IBUG_face_bbox.txt IBUG_land.txt

You need to put the ibug [2] images into the folder "x64/Release/image/ibug/".

In the folder "x64/Release", you can run the file "run_MCNet.bat".

You can also run the code in the Microsoft Visual Studio 2013. We have added the command arguments to "Project -> Properties -> Configuration Properties -> Debugging -> Command Arguments".

If you find our code useful in your research work, please cite our paper.
```
@article{shao2018deepmulti,
  title={Deep Multi-Center Learning for Face Alignment},
  author={Shao, Zhiwen and Zhu, Hengliang and Tan, Xin and Hao, Yangyang and Ma, Lizhuang},
  journal={Neurocomputing},
  year={2018},
  publisher={Elsevier}
}
```
Should you have any questions, just contact with us through email shaozhiwen@sjtu.edu.cn.


References:

[1] Yangqing Jia, Evan Shelhamer, Jeff Donahue, Sergey Karayev, Jonathan Long, Ross B Girshick, Sergio Guadarrama, and Trevor Darrell, "Caffe: Convolutional architecture for fast feature embedding.," in ACM International Conference on Multimedia. ACM, 2014, pp. 675–678.

[2] Christos Sagonas, Georgios Tzimiropoulos, Stefanos Zafeiriou, and Maja Pantic, "300 faces in-the-wild challenge: The first facial landmark localization challenge," in IEEE International Conference on Computer VisionWorkshops. IEEE, 2013, pp. 397–403.
