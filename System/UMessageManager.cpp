#include "UMessageManager.h"
#include "../Engine/Const.h"
UMessageManager::UMessageManager()
{
	Title.setColor(c_red_head, c_red_tail);
	Tip.setColor(c_yellow_head, c_yellow_tail);
	Info.setColor(c_blue_head, c_blue_tail);
	Error.setColor(c_red_head, c_red_tail);

}

void UMessageManager::showMessage(UMessage* message)
{
	message->show();
	message->clear();
}

void UMessageManager::showTitle()
{
	showMessage(&Title);
}

void UMessageManager::showTip()
{
	showMessage(&Tip);
	Tip.appendLine("Tip:");
}

void UMessageManager::showInfo()
{
	showMessage(&Info);
	Info.appendLine("Info:");
}

void UMessageManager::showError()
{
	showMessage(&Error);
	Error.appendLine("Error:");
}

void UMessageManager::show()
{
	showTitle();
	showTip();
	showInfo();
	showError();
}
