####################################################
#                      MAKEFILE                    #
####################################################

##### DEFINES #####
APPS = ./apps/tests
DOCTEST = ./DOCTEST
HEADERS = ./headers
SRC = ./src
TESTS = ./tests
OBJ = ./obj
CWI = ./Capybara
FINAL_INCLUDES = ./CWI

LIBS = $(DOCTEST)/* -lCwI -L $(CWI)

##### ALL #####
all: headers apps atz_files

##### COMPILE HEADERS FILES #####
headers:\
	$(OBJ)/Div.o \
	$(OBJ)/Element.o \
	$(OBJ)/Style.o \
	$(OBJ)/Text.o \
	$(OBJ)/Image.o \
	$(OBJ)/TextBox.o \
	$(OBJ)/Button.o \
	$(OBJ)/Form.o \
	$(OBJ)/Render.o
	ar -rcs $(CWI)/libCwI.a $(OBJ)/*.o

##### COMPILE APPS #####
apps:\
	clean_tests \
	$(APPS)/test_div \
	$(APPS)/test_text \
	$(APPS)/test_style \
	$(APPS)/test_image \
	$(APPS)/test_textbox \
	$(APPS)/test_button \
	$(APPS)/test_form \
	$(APPS)/test_render

atz_files:
	rm -rf $(FINAL_INCLUDES)/*
	cp $(HEADERS)/* $(FINAL_INCLUDES)

##### GENERAL DIRECTIVE FOR COMPILE OBJ FILES #####
$(OBJ)/%.o: $(SRC)/%.cpp $(HEADERS)/%.hpp
	g++ -c $< -Wall -I $(HEADERS) -o $@

##### GENERAL DIRECTIVE FOR COMPILE EXE FILES #####
$(APPS)/%: $(TESTS)/%.cpp
	g++ $< -Wall $(LIBS) -I $(HEADERS) -o $@

##### CLEAN OLD VERSIONS #####
clean:
	rm -rf $(APPS)/* $(CWI)/* $(OBJ)/*

##### CLEAN ALL APPS FOR NEW COMPILE #####
clean_tests:
	rm -rf $(APPS)/*
