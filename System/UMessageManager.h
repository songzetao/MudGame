#pragma once
#include "../Engine/UMessage.h"

class UMessageManager {

public:
	UMessage Title;
	UMessage Tip;
	UMessage Info;
	UMessage Error;

public:
	UMessageManager();

	void showMessage(UMessage* message);
	void showTitle();
	void showTip();
	void showInfo();
	void showError();

	void show();
};