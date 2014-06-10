#ifndef _OPTION_PARSER_H_
#define _OPTION_PARSER_H_

typedef struct opt_item {
	void *native_args;

	int num_user_args;
	
	char *opt_key;

	int (* process_args) (void *native_args, int num_user_args, char **user_args);
} opt_item;

typedef struct opt_parser {
	int num_opts;
	opt_item *items;
} opt_parser;

int opt_parse(int argc, char *argv[], opt_parser *parser);

#endif