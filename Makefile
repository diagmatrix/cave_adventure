# Directives
vpath %.hpp include/
vpath %.cpp src/
vpath %.o $(OBJ)

# Compiler
CXX = g++
CXXFLAGS = -g

# File variables
PROJECT := adventure
EXEC = $(BIN)$(PROJECT)
MAINSRC := main.cpp
SOURCES := event.cpp stats.cpp player.cpp aux.cpp
OBJECTS := $(SOURCES:.cpp=.o)
HEADERS := $(SOURCES:.cpp=.hpp)
MAINOBJ := $(MAINSRC:.cpp=.o)

# Directory variables
OBJ := obj/
ZIP := zip/
BIN := bin/

# Other variables
DOCUMENTATION = doxygen
BROWSER = firefox
COMPRESS = zip
BOLD = `tput bold`
GREEN = `tput setaf 2`
RESET = `tput sgr0`

# Define variables
define compile =
@echo "Compilando $@ ..."
$(CXX) $(CXXFLAGS) -o $@ $<
@echo "${GREEN}HECHO${RESET}"
endef
define makedir =
@echo "Creando carpeta $@ ..."
mkdir -p $@
@echo "${GREEN}HECHO${RESET}"
endef
define makeexec =
@echo "Generando el ejecutable $(PROJECT) ..."
$(CXX) $(CXXFLAGS) -o $@ $^
@-mv $? $(OBJ)
@echo "${GREEN}HECHO${RESET}"
endef

# Pattern-specific variables
%.o: CXXFLAGS += -Wall -I./include -c

# Recipeless rules
all: author $(BIN) $(EXEC);
.PHONY: clean-hard $(DOCUMENTATION)
clean-hard: clean-exec clean-obj clean-doxygen;
$(PROJECT): | $(BIN)
$(COMPRESS): | $(ZIP)
$(MAINOBJ): | $(OBJ)
$(OBJECTS): | $(OBJ)

# File rules
$(EXEC): $(OBJECTS) $(MAINOBJ)
	$(makeexec)
	@echo "${GREEN}Ejecutando juego...${RESET}"
	$(EXEC)

$(OBJ)$(OBJECTS): %.o: %.cpp %.hpp
	$(compile)

$(MAINOBJ): $(MAINSRC)
	$(compile)

# Directory rules
$(OBJ):
	$(makedir)

$(BIN):
	$(makedir)

$(ZIP):
	$(makedir)

# Other rules
clean-exec:
	@rm -rf $(BIN)
	@echo "El archivo $(EXEC) ha sido borrado"

clean-obj:
	@rm -rf $(OBJ)
	@echo "La carpeta $(OBJ) ha sido borrada con todos sus archivos"

clean-doxygen:
	@rm -rf doc/html doc/latex
	@echo "La documentación ha sido borrada"

$(DOCUMENTATION):
	@echo "Creando documentación..."
	@$(DOCUMENTATION) doc/$(PROJECT).doxy
	@echo "${GREEN}HECHO${RESET}"
	@$(BROWSER) doc/html/index.html
	
$(COMPRESS): clean-hard
	@echo "Creando el archivo comprimido $(PROJECT).zip ..."
	@rm -rf $(ZIP)*
	@$(COMPRESS) -r $(ZIP)/$(PROJECT).zip *
	@echo "${GREEN}HECHO${RESET}"
	
help:
	@echo "Posibles opciones:"
	@echo "		${BOLD}clean-hard${RESET}	\
	Borra todos los archivos creados por el makefile"
	@echo "		${BOLD}clean-exec${RESET}	\
	Borra el ejecutable"
	@echo "		${BOLD}clean-obj${RESET}	\
	Borra los archivos objeto"
	@echo "		${BOLD}clean-doxyen${RESET}	\
	Borra los archivos de documentación"
	@echo "		${BOLD}doxygen${RESET}		\
	Genera la documentación del proyecto"
	@echo "		${BOLD}zip${RESET}		\
	Genera un zip con el proyecto"

author:
	@echo "Este proyecto ha sido creado por Manuel Gachs Ballegeer"
	@echo "https://github.com/diagmatrix"