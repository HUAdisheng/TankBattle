#pragma once
#ifndef _PROPS__H_
#define _PROPS__H_
#include<iostream>
#include "cocos2d.h"
using namespace cocos2d;
enum PROP_TYPE {
	Speed,
	Invicible,

};
class Props :public Sprite{
public:
	static Props* create(const std::string& PropImage);
	//Type of Props
	void setType(PROP_TYPE type) {
		this->pro_type = type;
	}

	void setTime(int time) {
		this->Last_time = time;
	}

	bool TestEnding();

	//≤‚ ‘ π”√
private:
	PROP_TYPE pro_type;
	int Last_time;
	//bool Is_End;
};
#endif // !_PROPS__H_
