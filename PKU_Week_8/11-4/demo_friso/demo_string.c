#include "../friso_API.h"

int main() {
	fstring str = "aaaaa";
	fstring str2 = "bbbbb";
	fstring str3 = "ccccc";
	fstring str4 = "ddddd";
	string_buffer_t strbuf = new_string_buffer();
	println(strbuf->buffer);
	printf("len=%d\n", strbuf->length);
	printf("loc=%d\n", strbuf->allocs);
	println("");
	
	string_buffer_append(strbuf, str);
	println(strbuf->buffer);
	printf("len=%d\n", strbuf->length);
	printf("loc=%d\n", strbuf->allocs);
	println("");
	
	string_buffer_append(strbuf, str2);
	println(strbuf->buffer);
	printf("len=%d\n", strbuf->length);
	printf("loc=%d\n", strbuf->allocs);
	println("");
	
	string_buffer_append(strbuf, str3);
	println(strbuf->buffer);
	printf("len=%d\n", strbuf->length);
	printf("loc=%d\n", strbuf->allocs);
	println("");
	
	string_buffer_append(strbuf, str4);
	println(strbuf->buffer);
	printf("len=%d\n", strbuf->length);
	printf("loc=%d\n", strbuf->allocs);
	println("");

	string_buffer_append_char(strbuf, 'G');
	println(strbuf->buffer);
	printf("len=%d\n", strbuf->length);
	printf("loc=%d\n", strbuf->allocs);
	println("");

	string_buffer_append_char(strbuf, 'H');
	println(strbuf->buffer);
	printf("len=%d\n", strbuf->length);
	printf("loc=%d\n", strbuf->allocs);
	println("");

	string_buffer_trim(strbuf);
	println(strbuf->buffer);
	printf("len=%d\n", strbuf->length);
	printf("loc=%d\n", strbuf->allocs);
	println("");

	string_buffer_clear(strbuf);
	println(strbuf->buffer);
	printf("len=%d\n", strbuf->length);
	printf("loc=%d\n", strbuf->allocs);
	println("");

	free_string_buffer(strbuf);
	println(strbuf->buffer);
	printf("len=%d\n", strbuf->length);
	printf("loc=%d\n", strbuf->allocs);
	println("");
	
	return 0;
}
