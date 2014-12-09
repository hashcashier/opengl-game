/*
 * Keyboard.h
 *
 *  Created on: Dec 9, 2014
 *      Author: rami
 */

#ifndef KEYBOARD_H_
#define KEYBOARD_H_

class Keyboard {
public:
	static void keyboardFunction(unsigned char c, int x, int y);
	static void keystrokeFunction(int key, int x, int y);
};

#endif /* KEYBOARD_H_ */
