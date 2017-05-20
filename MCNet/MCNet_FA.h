#include <cstdint>

#ifdef DLL_IMPLEMENT  
#define DLL_API __declspec(dllexport)  
#else  
#define DLL_API __declspec(dllimport)  
#endif 

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	DLL_API int __cdecl face_alignment(const cv::Mat &img, cv::Mat &ptsMat, double left,
		double right, double top, double bottom);
#ifdef __cplusplus
}
#endif // __cplusplus