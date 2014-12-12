///*
// * WAV.cpp
// *
// *  Created on: Dec 12, 2014
// *      Author: rami
// */
//
//#include "WAV.h"
//
//WAV::WAV(string fileName) {
//	ALCdevice *dev;
//	ALCcontext *ctx;
//	struct stat statbuf;
//
//	dev = alcOpenDevice(NULL);
//	if (!dev)
//		cerr << "Couldn't open audio device." << endl;
//	ctx = alcCreateContext(dev, NULL);
//	alcMakeContextCurrent(ctx);
//	if (!ctx)
//		cerr << "Couldn't create audio context." << endl;
//
//	ALuint source, buffers[NUM_BUFFERS];
//	ALuint frequency;
//	ALenum format;
//	unsigned char *buf;
//
//	int pid, files[2];
//	FILE *f;
//
//	alGenBuffers(NUM_BUFFERS, buffers);
//	alGenSources(1, &source);
//	if (alGetError() != AL_NO_ERROR) {
//		cerr << "Error generating audio sources/buffers." << endl;
//	}
//
//	if (stat(fileName.c_str(), &statbuf) != 0 || !S_ISREG(statbuf.st_mode)) {
//		fprintf(stderr, "%s doesn't seem to be a regular file :(\n",
//				fileName.c_str());
//	}
//
//	if (pipe(files) != 0) {
//		fprintf(stderr, "Pipe failed :(\n");
//	}
//
//	pid = fork();
//	switch (pid) {
//	case -1:
//		fprintf(stderr, "Fork failed :(\n");
//		break;
//	case 0:
//		close(files[0]);
//		close(STDOUT_FILENO);
//		dup2(files[1], STDOUT_FILENO);
//		execlp("mplayer", "-nogui", "-really-quiet", "-novideo",
//				"-noconsolecontrols", "-ao", "pcm:file=/dev/stdout",
//				fileName.c_str(), (char*) NULL);
//		_exit(1);
//	default:
//		close(files[1]);
//		break;
//	}
//	f = fdopen(files[0], "rb");
////	buf = malloc(BUFFER_SIZE);
//	fread(buf, 1, 12, f);
//	fread(buf, 1, 8, f);
//	if (buf[0] != 'f' || buf[1] != 'm' || buf[2] != 't' || buf[3] != ' ') {
//		fprintf(stderr, "Not 'fmt ' :(\n");
//		fclose(f);
//	} else {
//		int channels, bits;
//		fread(buf, 1, 2, f);
//		if (buf[1] != 0 || buf[0] != 1) {
//			fprintf(stderr, "Not PCM :(\n");
//			fclose(f);
//		}
//		fread(buf, 1, 2, f);
//		channels = buf[1] << 8;
//		channels |= buf[0];
//		fread(buf, 1, 4, f);
//		frequency = buf[3] << 24;
//		frequency |= buf[2] < 16;
//		frequency |= buf[1] < 8;
//		frequency |= buf[0];
//		fread(buf, 1, 6, f);
//		fread(buf, 1, 2, f);
//		bits = buf[1] << 8;
//		bits |= buf[0];
//		format = 0;
//		if (bits == 8) {
//			if (channels == 1)
//				format = AL_FORMAT_MONO8;
//			else if (channels == 2)
//				format = AL_FORMAT_STEREO8;
//		} else if (bits == 16) {
//			if (channels == 1)
//				format = AL_FORMAT_MONO16;
//			else if (channels == 2)
//				format = AL_FORMAT_STEREO16;
//		}
//		if (!format) {
//			fprintf(stderr, "Incompatible format (%d, %d) :(\n", channels,
//					bits);
//			fclose(f);
//		}
//	} fread(buf, 1, 8, f);
//    if(buf[0] != 'd' || buf[1] != 'a' || buf[2] != 't' || buf[3] != 'a')
//    {
//        fclose(f);
//        fprintf(stderr, "Not 'data' :(\n");
//    }
//}
//
