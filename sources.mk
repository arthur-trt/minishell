## SOURCES.MK ##

## SRCS ##

SOURCES		+=                                 		\
		srcs/main.c                               	\


## SRCS/INPUT ##

SOURCES		+=                                 		\
		srcs/input/cursor_pos.c                   	\
		srcs/input/get_win_size.c                 	\
		srcs/input/set_term_mode.c                	\
		srcs/input/char.c                         	\
		srcs/input/get_key.c                      	\
		srcs/input/outfun.c                       	\
		srcs/input/move_cursor_lines_bonus.c      	\
		srcs/input/move_cursor_words_bonus.c      	\
		srcs/input/move_cursor.c                  	\
		srcs/input/input.c                        	\


## SRCS/EXEC ##

SOURCES		+=                                 		\
		srcs/exec/search_path.c                   	\


## SRCS/HISTORY ##

SOURCES		+=                                 		\
		srcs/history/print_history.c              	\
		srcs/history/add_elem_history.c           	\
		srcs/history/nav_history.c                	\
		srcs/history/backup_history.c             	\
		srcs/history/free_history.c               	\
		srcs/history/append_history.c             	\
		srcs/history/construct_history.c          	\


## SRCS/UTILS ##

SOURCES		+=                                 		\
		srcs/utils/free_split.c                   	\
		srcs/utils/dir.c                          	\
		srcs/utils/clean_str.c                    	\
		srcs/utils/ft_malloc.c                    	\


## SRCS/PARSER/LEXER ##

SOURCES		+=                                 		\
		srcs/parser/lexer/add_cmd_to_lexer.c      	\
		srcs/parser/lexer/print_lexer.c           	\
		srcs/parser/lexer/lexer.c                 	\
		srcs/parser/lexer/free_lexer.c            	\
		srcs/parser/lexer/clean_cmd.c             	\


## SRCS/ENV ##

SOURCES		+=                                 		\
		srcs/env/free.c                           	\
		srcs/env/init.c                           	\
		srcs/env/search_key.c                     	\


## BONUS ##

SOURCES_BONUS	+= $(SOURCES)                 			\
		srcs/input/move_cursor_lines_bonus.c      	\
		srcs/input/move_cursor_words_bonus.c      	\


