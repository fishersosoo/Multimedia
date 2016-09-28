#pragma once
#define NOISE 0.2
#include <assert.h>
#include <math.h>
struct ThreadParam
{
	UINT**LUT;
	HANDLE* Event;
	UINT degree;
	UINT scale;
	UINT** polt;
	CImage * src;
	int startIndex;
	int endIndex;
	int maxSpan;//为模板中心到边缘的距离
};

static bool GetValue(int p[],int size,int &value);

class ImageProcess
{
public:
	static UINT Linear(LPVOID param);
	static UINT8* BuildGammaLUT(float fPrecompensation );
	static void GammaCorrectiom(UINT* input,UINT8* gammaLUT);
	static UINT medianFilter(LPVOID  param);
	static UINT addNoise(LPVOID param);
	static UINT autoTone(LPVOID param);
	static UINT histogram(LPVOID param);
};