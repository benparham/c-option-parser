#ifndef _OPTION_PARSER_H_
#define _OPTION_PARSER_H_

typedef struct opt_item {
	int num_args;

	char *opt_key;
	int (* process_args) (int num_args, char **user_args, void *native_args);
} opt_item;

typedef struct opt_parser {
	int num_opts;
	opt_item *items;
} opt_parser;

int opt_parse(int argc, char *argv[], opt_parser *parser, void *native_args);

#endif