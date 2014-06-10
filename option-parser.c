#include <stdio.h>
#include <string.h>

#include <option-parser.h>

int opt_parse(int argc, char *argv[], opt_parser *parser) {
	for (int i = 1; i < argc; i++) {
		char *key = argv[i];

		int found = 0;

		int j = 0;
		while (j < parser->num_opts) {
			opt_item item = parser->items[j];
			
			if (strcmp(key, item.opt_key) == 0) {

				if (i + item.num_user_args >= argc) {
					printf("Not enough arguments supplied for option: '%s'\n", key);
					return 1;
				}

				char *user_args[item.num_user_args];
				for (int k = 0; k < item.num_user_args; k++) {
					i++;
					user_args[k] = argv[i];
				}

				if (item.process_args(item.native_args, item.num_user_args, user_args)) {
					return 1;
				}

				found = 1;
				break;
			}

			j++;
		}

		if (!found) {
			printf("Invalid option: '%s'\n", key);
			return 1;
		}
	}

	return 0;
}