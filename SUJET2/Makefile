#Makefile
#Author : Maxime ALZOUBAIDY (alzoubaidy@cy-tech.fr)
#Date : 11/07/22
#Os : Linux


#Directorie path
Dir_SRC = Src
Dir_OBJ = Obj
Dir_PROG = Bin
Dir_SAVE = Save

#Compiler
CC = gcc

#Compiler flags
CFLAGS = -g -Wall -fsanitize=address

#Library flags
LDLIBS = -lm

#Shell commands
MKDIR_P = mkdir -p
RM = rm -f
RM_R = rm -rf

#all set up
SRC = $(wildcard $(Dir_SRC)/*.c) 
HEAD = $(wildcard Include/*.h)
OBJ = $(SRC:$(Dir_SRC)/%.c=$(Dir_OBJ)/%.o)
PROG = $(Dir_PROG)/main

#Target
all : $(PROG)

#Compiling target
$(PROG) : $(OBJ)
	@echo "Generating executable file ..."
	@$(MKDIR_P) $(Dir_PROG)
	@$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)
	@echo "Done !"

$(Dir_OBJ)/%.o : $(Dir_SRC)/%.c
	@echo "Compiling $^ ..."
	@$(MKDIR_P) $(Dir_OBJ)
	@$(CC) -c $< -o $@

.PHONY : clean


#Clean files from Obj and Bin
clean :
	@echo "Cleaning files from Obj and Bin ..."
	@$(RM) $(OBJ) $(PROG)
	@echo "Done !"


#Clean repertorie Obj and Bin
hardClean : 
	@echo "Clearing repertorie Obj and Bin..."
	@$(RM_R) $(Dir_OBJ) $(Dir_PROG)
	@echo "Done !"


#Save sources
save :
	@echo "Building save for sources..."
	@$(MKDIR_P) $(Dir_SAVE)
	@cp $(Dir_SRC)/* $(Dir_SAVE)
	@echo "Done !"


#Run your target
run : 
	@if [ -x $(PROG) ]; then\
		./$(PROG);\
	fi


#Help menu
help :
	@echo "Welcome to my Makefile."
	@echo "Here are the option you can use :"
	@echo "\t make : compil your project,"
	@echo "\t make clean : clean repertoy Bin and Obj. Move their files to trash,"
	@echo "\t make hardClean : remove Bin and Obj repertories,"
	@echo "\t make save : Create Save directory and save Src files,"
	@echo "\t make run : run the target."