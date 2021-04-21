## SOURCES.MK ##

## SRCS ##

SOURCES		+=                   		\
		srcs/main.c                 	\


## SRCS/BUILTINS ##

SOURCES		+=                   		\
		srcs/builtins/env.c         	\
		srcs/builtins/echo.c        	\
		srcs/builtins/pwd.c         	\
		srcs/builtins/unset.c       	\
		srcs/builtins/export.c      	\


## SRCS/INPUT ##

SOURCES		+=                   		\
		srcs/input/input.c          	\


## SRCS/UTILS ##

SOURCES		+=                   		\
		srcs/utils/ft_malloc.c      	\
		srcs/utils/prompt.c         	\
		srcs/utils/dir.c            	\


## SRCS/ENV ##

SOURCES		+=                   		\
		srcs/env/search_key.c       	\
		srcs/env/init.c             	\
		srcs/env/free.c             	\


## SRCS/PARSER ##

SOURCES		+=                   		\
		srcs/parser/dquoted.c       	\
		srcs/parser/parser.c        	\
		srcs/parser/errors.c        	\
		srcs/parser/utils.c         	\
		srcs/parser/var.c           	\
		srcs/parser/double.c        	\
		srcs/parser/apply.c         	\
		srcs/parser/squoted.c       	\
		srcs/parser/string.c        	\


