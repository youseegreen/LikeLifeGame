#pragma once
// リンカーの入力を設定
// デバッグとリリースで入力するファイルが異なるのでこのようにしています。
#ifdef _DEBUG
#define CV_EXT "d.lib"
#else
#define CV_EXT ".lib"
#endif
//#pragma comment(lib, "opencv_core341" CV_EXT) // OpenCV3.3.0の場合は、"opencv_core330"に
#pragma comment(lib, "opencv_world341" CV_EXT) // OpenCV3.3.0の場合は、"opencv_highgui330"に変更

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
