#pragma once
#include <string>
#include<functional>
#include <list>
#include <map> 
#include "Delegate.h"
using namespace std;


class UEventDispatcher {

private:
	map<string, CMultiDelegate *> delegateMap;

public:
	template<class T>
	void bindEvent(string key, T* _object, void (T::* _method)(string, string)) {
		IDelegate* handle = newDelegate(_object, _method);
		auto it = delegateMap.find(key);
		if (it == delegateMap.end()) {
			CMultiDelegate *delegate = new CMultiDelegate();
			*delegate += handle;
			delegateMap.insert(pair<string, CMultiDelegate*>(key, delegate));
		}
		else {
			(*(*it).second) += handle;
		}
	};
	template<class T>
	void unBindEvent(string key, T* _object, void (T::* _method)(string, string)) {
		IDelegate* handle = newDelegate(_object, _method);
		auto it = delegateMap.find(key);
		if (it != delegateMap.end()) {
			(*(*it).second) -= handle;
		}
	};
	void dispatcherEvent(string key , string cmd);

	void executeInput(string uiName , string cmd);
};

