/*
 * colorTransformation.h
 *
 *  Created on: Sep 3, 2015
 *      Author: adas
 */

#ifndef COLORTRANSFORMATION_H_
#define COLORTRANSFORMATION_H_


template<typename T>
__global__
void RGB2GrayScale(T *RGBimage, T *grayScaleImage, uint rows, uint cols)
{
	int idx = blockIdx.x * blockDim.x + threadIdx.x;
	int idy = blockIdx.y * blockDim.y + threadIdx.y;
	T r, g, b;

	if (idx < cols && idy < rows) {
		r = RGBimage[(idy*cols + idx)*3 + 2];
		g = RGBimage[(idy*cols + idx)*3 + 1];
		b = RGBimage[(idy*cols + idx)*3];
		grayScaleImage[idy*cols + idx] = (0.2989360213f * r) + (0.5870430745f * g) + (0.1140209043f * b);
	}
}


#endif /* COLORTRANSFORMATION_H_ */
