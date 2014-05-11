#include <iostream>
#include <pthread.h>
#include "Checker.h"
#include <string>
#include "CheckerCache.h"
#include <ctime>
#include <clocale>
#include <unistd.h>
#include "WstringConvertString.hpp"
#include "CacheManager.h"

using namespace std;

void *syn(void *cm) {
	while(true) {
		CacheManager *p = static_cast<CacheManager*> (cm);
		p->syncFromRamCache("./DiskCache");
	}
	pthread_exit(0);
}

int main() {
	setlocale(LC_CTYPE, "");
	string file("/home/kevin/MyProjects/SpellChecker/data/segresult.txt");
	/*磁盘Cache和RamCache初始化*/
	string cycle("1");
	CacheManager cacheMag("./DiskCache", cycle);
	CheckerCache cache(&cacheMag); //初始化过程中完成与DiskCache的同步

	/*开启新线程执行CacheManager的磁盘同步*/
	pthread_t sync;
	pthread_create(&sync, NULL, syn, (void *)&cacheMag);

	wcout << L"开始初始化" << endl;
	clock_t init = clock();
	Checker checker(file);
	init = clock() - init;
	wcout << L"初始化完成！" << L" " << L"共用时：" << ((float)init) / CLOCKS_PER_SEC << L"秒" << endl << endl;;
	wstring target;
	while(true) {
		wcout << L"请输入待查汉字：";
		wcin >> target;
		wcout << endl;
		clock_t t = clock();
		//search evnet begin
		string temptarget = Convert::WstringToString(target);
		string cacheresult(cache.find(temptarget));
		if(cacheresult.size() != 0) {
			wstring result = Convert::StringToWstring(cacheresult);	
			wcout << result << endl;
		} else {
			wstring result = checker.findTopKSimilarWords(target, 4);
			wcout << result << endl;
			cache.addresult(temptarget, Convert::WstringToString(result));
		}
		//search event end
		t = clock() - t;
		wcout << endl;
		wcout << L"查询完成！" << L" " << L"共用时：" << ((float)t) / CLOCKS_PER_SEC << L"秒";
		wcout << endl;
		wcout << endl;
	}
	return 0;
}
