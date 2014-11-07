#include "../friso_API.h"
#include "stdio.h"

int main() {
	friso_hash_t myhash = new_hash_table();	
	hash_put_mapping(myhash, "a", "hash_a");
	hash_put_mapping(myhash, "b", "hash_b");
	hash_put_mapping(myhash, "c", "hash_c");
	hash_put_mapping(myhash, "d", "hash_d");
	hash_put_mapping(myhash, "e", "hash_e");
	fstring hget = hash_get_value(myhash, "d");
	printf("%s\n", hget);
	fstring hget2 = hash_get_value(myhash, "xx");
	if(hget2) {
		printf("%s\n", hget2);
	}

	return 0;
}
