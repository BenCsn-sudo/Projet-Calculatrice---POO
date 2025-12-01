# Nom de l'exécutable
EXEC = calculator

# Compilateur et options
CXX = clang++
CXXFLAGS = -g -Wall -std=c++11 -Wno-everything

# Dossiers d'inclusion (pour que #include "Token.h" marche sans mettre "components/Token.h")
INCLUDES = -I./src/components -I./src/services -I./src/ui

# Recherche automatique de TOUS les fichiers .cpp dans src/ et ses sous-dossiers
# + le main.cpp à la racine
SRCS = main.cpp \
       $(wildcard src/components/*.cpp) \
       $(wildcard src/services/*.cpp) \
       $(wildcard src/ui/*.cpp)

# Génération des noms de fichiers objets (.o)
OBJS = $(SRCS:.cpp=.o)

# Règle principale
all: $(EXEC)

# Édition de liens
$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $(EXEC)

# Compilation des .cpp en .o
# $< est le fichier source, $@ est le fichier cible
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Nettoyage
clean:
	rm -f $(OBJS) $(EXEC)

.PHONY: all clean
