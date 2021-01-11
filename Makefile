#Compiler and Linker
CC				:= clang-9

#The Target Binary Program
TARGET			:= minishell

#The Directories, Source, Includes, Objects, Binary and Resources
SRCDIR			:= srcs
INCDIR			:= inc
BUILDDIR		:= obj
TARGETDIR		:= bin
SRCEXT			:= c
DEPEXT			:= d
OBJEXT			:= o

SOURCES			:= srcs/main.c srcs/utils/ft_malloc.c
OBJECTS			:= $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.$(OBJEXT)))

#Flags, Libraries and Includes
CFLAGS			:= -Wall -Werror -Wextra
LIB				:= -Llibftprintf -lftprintf
INC				:= -I$(INCDIR) -I/usr/local/include
INCDEP			:= -I$(INCDIR)

# Colors
C_RESET			:= \033[0m
C_PENDING		:= \033[0;36m
C_SUCCESS		:= \033[0;32m

# Multi platforms
ECHO			:= echo

# Escape sequences (ANSI/VT100)
ES_ERASE		:= "\033[1A\033[2K\033[1A"
ERASE			:= $(ECHO) $(ES_ERASE)

# hide STD/ERR and prevent Make from returning non-zero code
HIDE_STD		:= > /dev/null
HIDE_ERR		:= 2> /dev/null || true

GREP			:= grep --color=auto --exclude-dir={.bzr,CVS,.git,.hg,.svn}
NORMINETTE		:= norminette `ls | grep -v "_main*" | grep -v "test*"`

#Defauilt Make
all: directories libft $(TARGET)
	@$(ERASE)
	@$(ECHO) "$(TARGET)\t\t[$(C_SUCCESS)✅$(C_RESET)]"
	@$(ECHO) "$(C_SUCCESS)All done, compilation successful! 👌 $(C_RESET)"

#Remake
re: fclean all

#Make the Directories
directories:
	@mkdir -p $(TARGETDIR)
	@mkdir -p $(BUILDDIR)

#Clean only Objecst
clean:
	@$(RM) -rf $(BUILDDIR)

#Full Clean, Objects and Binaries
fclean: clean
	@$(RM) -rf $(TARGETDIR)

#Pull in dependency info for *existing* .o files
-include $(OBJECTS:.$(OBJEXT)=.$(DEPEXT))

#Link
$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGETDIR)/$(TARGET) $^ $(LIB)

#Compile
$(BUILDDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $@)
	@$(ECHO) "$(TARGET)\t\t[$(C_PENDING)⏳$(C_RESET)]"
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<
	@$(CC) $(CFLAGS) $(INCDEP) -MM $(SRCDIR)/$*.$(SRCEXT) > $(BUILDDIR)/$*.$(DEPEXT)
	@$(ERASE)
	@$(ERASE)
	@cp -f $(BUILDDIR)/$*.$(DEPEXT) $(BUILDDIR)/$*.$(DEPEXT).tmp
	@sed -e 's|.*:|$(BUILDDIR)/$*.$(OBJEXT):|' < $(BUILDDIR)/$*.$(DEPEXT).tmp > $(BUILDDIR)/$*.$(DEPEXT)
	@sed -e 's/.*://' -e 's/\\$$//' < $(BUILDDIR)/$*.$(DEPEXT).tmp | fmt -1 | sed -e 's/^ *//' -e 's/$$/:/' >> $(BUILDDIR)/$*.$(DEPEXT)
	@rm -f $(BUILDDIR)/$*.$(DEPEXT).tmp

libft:
	@make -s -C libftprintf/

norm:
	@$(NORMINETTE) | $(GREP) -v "Not a valid file" | $(GREP) "Error\|Warning" -B 1 || true

#Non-File Targets
.PHONY: all re clean fclean norm
