/*
 * parameters.h
 *
 *  Created on: Jul 23, 2015
 *      Author: adas
 */

#ifndef PARAMETERS_H_
#define PARAMETERS_H_

// Includes
#include <string>
#include "constants.h"

using  namespace std;

enum NORMType {L1SQRT, L2SQRT};

////////////////////////
// LBP algorithm options
////////////////////////
struct LBPconfig {
	// Block Histogram dimensions
	const uint XCell;
	const uint YCell;
	const uint XBlock;
	const uint YBlock;
	const uint clipTh;
	LBPconfig() :
		XCell(XCELL), YCell(YCELL),
		XBlock(XBLOCK), YBlock(YBLOCK),
		clipTh(CLIPTH) { }
};

////////////////////////
// HOG algorithm options
////////////////////////
struct HOGconfig {

};

///////////////////////////////////////
// Launch configuration data structure
///////////////////////////////////////
struct parameters {
	// file paths
	string pathToSVMmodel;
	string pathToImgs;

	// Image adquisition
	bool useDiskImgs;
	bool useCamera;
	bool usePyramid;

	// Pyramid options
	bool useHostReescale;
	bool useDeviceReescale;

	uint pyramidIntervals;
	uint nMaxScales;
	uint imagePaddingX;
	uint imagePaddingY;
	uint minRoiMargin;
	float minScale;

	// Feature extraction methods
	bool useLBP;
	bool useHOG;
	bool useHOGLBP;
	bool useNorm;
	string normType;

	// Feature extraction options
	bool useHostFilter;
	bool useDeviceFilter;
	LBPconfig LBPvars;
	HOGconfig HOGvars;

	// Classification methods
	bool useSVM;
	bool useRF;
	bool useNMS;

	// Classification options
	float SVMthr;

	////////////////////////////
	// CUDA CONFIGURATION
	////////////////////////////
	// Device type preference
	string devPreference;

	// Preprocess CUDA block dimensions
	uint preBlockX;
	uint preBlockY;
	uint preBlockZ;

	// Resize CUDA block dimensions
	uint resizeBlockX;
	uint resizeBlockY;
	uint resizeBlockZ;

	uint paddingBlockX;
	uint paddingBlockY;
	uint paddingBlockZ;

	// Local Binary Patterns CUDA blocks dimensions
	uint LBPblockX;
	uint LBPblockY;
	uint LBPblockZ;

	uint cellBlockX;
	uint cellBlockY;
	uint cellBlockZ;

	uint blockBlockX;
	uint blockBlockY;
	uint blockBlockZ;

	uint normBlockX;
	uint normBlockY;
	uint normBlockZ;

	// Support Vector Machine CUDA blocks dimensions
	uint SVMblockX;
	uint SVMblockY;
	uint SVMblockZ;
};



#endif /* PARAMETERS_H_ */
