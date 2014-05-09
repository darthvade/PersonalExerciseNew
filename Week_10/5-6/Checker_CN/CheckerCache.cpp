#include "CheckerCache.h"
#include "CacheManager.h"

CheckerCache::CheckerCache(CacheManager *pDiskCache) :
_cache_map(),
_pDiscCache(pDiskCache) {

}

CheckerCache::~CheckerCache() {

}

std::string CheckerCache::find(std::string &target) {
	Iter iter = _cache_map.find(target);
	if(iter == _cache_map.end()) {
		return std::string();	
	} else {
		return iter->second;
	}
}

void CheckerCache::addresult(std::string target, std::string result) {
	_cache_map.insert({target, result});
}

void CheckerCache::syncFromDiskCache() {
	_cache_map.clear();
	_pDiscCache
}
