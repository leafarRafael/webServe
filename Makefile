#-----------------------------------------------------------------------------------------
# Static library
NAME		:= webserv

#-----------------------------------------------------------------------------------------
# Compiler and flags
CFLAGS		:= -Wall -Werror -Wextra -std=c++98 -g3
CPP			:= c++
O_FLAGS		:= -c

#-----------------------------------------------------------------------------------------
# Command to clean up files
CMD_CLEAN	:= rm -Rf

#-----------------------------------------------------------------------------------------
# DIRECTORY
SRC_DIR				:= src/ src/utils \
					src/Server \
					src/Server/Settings \
					src/Server/ParseConf \
					src/Server/ParseConf/ParseValidation \
					src/Server/ParseConf/ParseTokens \
					src/Server/Settings/DataServer \
					src/Server/Settings/Location2 \
					src/Server/Settings/Location2/DataLocation \
					src/Server/Settings/Directives/AllowMethods \
					src/Server/Settings/Directives/AutoIndex \
					src/Server/Settings/Directives/ErrorPage2 \
					src/Server/Settings/Directives/ErrorPage2/ErrorCodeURL \
					src/Server/Settings/Directives/Index \
					src/Server/Settings/Directives/Listen2 \
					src/Server/Settings/Directives/MaxBodySize \
					src/Server/Settings/Directives/PathLocation \
					src/Server/Settings/Directives/Return \
					src/Server/Settings/Directives/Root \
					src/Server/Settings/Directives/ServerName \
					src/Server/Socket \
					src/Server/Response \
					src/Server/Response/HTTP \
					src/Server/Response/HTTP/StatusLine \
					src/Server/Response/HTTP/Headers \
					src/Server/Response/HTTP/Body \
					src/Webserv \
					src/ParserRequest \
					src/Parser\
					src/Logger\
					src/Server/Location \
					src/Server/ErrorPage\
					src/ParseRequest/Request \
					src/ParseRequest/Request/Request \
					src/ParseRequest\
					src/ParseRequest/Request/AHeaders \
					src/ParseRequest/Request/ARequestLine \
					src/ParseRequest/Request/ABody \
					src/ParseRequest/Request/ABody/DataBody \
					src/ParseRequest/Request/ABody/MultPart \
					src/ParseRequest/Request/ABody/Chunked \
					src/ParseRequest/Request/ABody/SimpleBody \
					src/Client

#-----------------------------------------------------------------------------------------
# Header file
INCLUDE				:= -I src/Server \
					-I src/Server/Socket \
					-I src/Server/Settings \
					-I src/Server/Settings/DataServer \
					-I src/Server/ParseConf \
					-I src/Server/ParseConf/ParseValidation \
					-I src/Server/ParseConf/ParseTokens \
					-I src/Server/Settings/Location2 \
					-I src/Server/Settings/Location2/DataLocation \
					-I src/Server/Settings/Directives/AllowMethods \
					-I src/Server/Settings/Directives/AutoIndex \
					-I src/Server/Settings/Directives/ErrorPage2 \
					-I src/Server/Settings/Directives/ErrorPage2/ErrorCodeURL \
					-I src/Server/Settings/Directives/Index \
					-I src/Server/Settings/Directives/Listen2 \
					-I src/Server/Settings/Directives/MaxBodySize \
					-I src/Server/Settings/Directives/PathLocation \
					-I src/Server/Settings/Directives/Return \
					-I src/Server/Settings/Directives/Root \
					-I src/Server/Settings/Directives/ServerName \
					-I src/utils\
					-I src/Server/Response \
					-I src/Server/Response/HTTP \
					-I src/Server/Response/HTTP/StatusLine \
					-I src/Server/Response/HTTP/Headers \
					-I src/Server/Response/HTTP/Body \
					-I src/Webserv\
					-I src/ParserRequest \
					-I src/Parser\
					-I src/Logger\
					-I include \
					-I src/Server/Location\
					-I src/Server/ErrorPage \
					-I src/ParseRequest\
					-I src/ParseRequest/Request \
					-I src/ParseRequest/Request/Request \
					-I src/ParseRequest/Request/AHeaders \
					-I src/ParseRequest/Request/ARequestLine \
					-I src/ParseRequest/Request/ABody \
					-I src/ParseRequest/Request/ABody/DataBody \
					-I src/ParseRequest/Request/ABody/MultPart \
					-I src/ParseRequest/Request/ABody/Chunked \
					-I src/ParseRequest/Request/ABody/SimpleBody \
					-I src/Client

#-----------------------------------------------------------------------------------------
# Source files
SRC_FILES += $(foreach path, $(SRC_DIR), $(wildcard $(addprefix $(path)/, *.cpp)))

#-----------------------------------------------------------------------------------------
# Directory for object files
OBJS		:= ./objs
O_FILE		:= $(SRC_FILES:%.cpp=$(OBJS)/%.o)

#-----------------------------------------------------------------------------------------
# Default rule to create the static library
all: $(NAME)

#-----------------------------------------------------------------------------------------
# Rule to create the static library
$(NAME): $(O_FILE)
	@$(CPP) $(O_FILE) -o $(NAME)

#-----------------------------------------------------------------------------------------
# Rule to compile source files into object files
$(OBJS)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CPP) $(O_FLAGS) $(INCLUDE) $(CFLAGS) $< -o $@

#-----------------------------------------------------------------------------------------
# Rule to clean
clean:
	@$(CMD_CLEAN) $(OBJS)

fclean: clean
	@$(CMD_CLEAN) $(NAME)

re: fclean all

run:
	./$(NAME)

re_run: re
	./$(NAME) conf/conf.conf

debug: re
	./$(NAME) "DEBUG"

valgrind: re
	valgrind ./$(NAME) conf/conf.conf

curl:
	curl -X POST -H "Transfer-Encoding: chunked" -H "Content-Type: application/json" --data-binary @index/dados.json 127.0.0.1:8080

telnet:
	@bash -c "telnet 127.0.0.1 8080"
	@sleep 2
	@bash -c "cat index/RequisicaoChunked"

.PHONY: all clean fclean re