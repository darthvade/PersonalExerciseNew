#include "Sys_head_account.h"

int main() {
	LinkAccount Maccount;
	init_account_list(&Maccount);
	read_account_from_file("test.txt", Maccount);
	debug_account_list(Maccount);

	AccountNode user;
	strcpy(user.u_name, "XXXOOO");
	user.permission = 1;
	strcpy(user.u_password, "7788");

//	insert_new_account(Maccount, &user);

//	delete_account(Maccount, "Kevin");
	
	update_account(Maccount, "XXXOOO", &user);

	debug_account_list(Maccount);

	write_account_into_file("test.txt", Maccount);

	return 0;
}
