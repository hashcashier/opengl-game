/*
 * WAV.h
 *
 *  Created on: Dec 12, 2014
 *      Author: rami
 */

#ifndef WAV_H_
#define WAV_H_

#define NUM_BUFFERS 3
#define BUFFER_SIZE 4096

#include "../platformIndependentHeader.h"
#include "sys/stat.h"
#include "unistd.h"
using namespace std;

class WAV {
public:
	static int play(string fileName);
	static int play2(string fileName);
};

#endif /* WAV_H_ */
