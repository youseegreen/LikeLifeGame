#pragma once
// �����J�[�̓��͂�ݒ�
// �f�o�b�O�ƃ����[�X�œ��͂���t�@�C�����قȂ�̂ł��̂悤�ɂ��Ă��܂��B
#ifdef _DEBUG
#define CV_EXT "d.lib"
#else
#define CV_EXT ".lib"
#endif
//#pragma comment(lib, "opencv_core341" CV_EXT) // OpenCV3.3.0�̏ꍇ�́A"opencv_core330"��
#pragma comment(lib, "opencv_world341" CV_EXT) // OpenCV3.3.0�̏ꍇ�́A"opencv_highgui330"�ɕύX

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
