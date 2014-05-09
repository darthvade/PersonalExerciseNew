#ifndef __CACHEMANAGER_H__
#define __CACHEMANAGER_H__

#include <string>
#include <unordered_map>
#include <vector>
#include <ctime>

class CheckerCache;

class CacheManager {
	friend class CheckerCache;
public:
	CacheManager(const std::string &cachefile, std::string &synccyle); //第二个参数为刷新磁盘周期
	~CacheManager();
private:
	void initFromDisk(std::string &cachefile); //从磁盘文件初始化
	void syncFromRamCache(); //从RAM缓存同步
	std::vector<CheckerCache*> _vecpRamCache; //保存指向RAM缓存的指针数组
	clock_t _presynctime; //上一次刷新磁盘时间
	std::unordered_map<std::string, std::string> _disk_cache_map; //查询结果缓存（DiskCache）
};

#endif
