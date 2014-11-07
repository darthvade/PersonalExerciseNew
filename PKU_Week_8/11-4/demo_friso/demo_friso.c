#include "../friso_API.h"
#include "../friso.h"

int main() {
	fstring _path_ = "./friso.ini";

	friso_t friso;
	friso_config_t config;
	friso_task_t task;

	friso = friso_new();
	config = friso_new_config();
	friso_init_from_ifile(friso, config, _path_);

	task = friso_new_task();
	
	while(1) {
		char buffer[1024];
		printf(">>");		
		scanf("%s", buffer);
		friso_set_text(task, buffer);
		while((config->next_token(friso, config, task)) != NULL) {
			printf("%s ", task->token->word);	
		}
		printf("\n");
	}

	friso_free_task(task);
	friso_free_config(config);
	friso_free(friso);
	return 0;
}
