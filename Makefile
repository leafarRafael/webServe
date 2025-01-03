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
					src/Mime \
					src/Server \
					src/Log \
					src/ErrorDefault \
					src/ReasonPhrase \
					src/Server/Methods/AMethods \
					src/Server/Methods/AMethods/DataRequest \
					src/Server/Methods/AMethods/DataDirectives \
					src/Server/Methods/AMethods/DataDirectives/FindLocation \
					src/Server/Methods/AMethods/CGI \
					src/Server/Methods/AMethods/GetFile \
					src/Server/Methods/GET \
					src/Server/Methods/POST \
					src/Server/Methods/DELETE \
					src/ParseConf \
					src/ParseConf/ParseValidation \
					src/ParseConf/ParseTokens \
					src/Server/Settings \
					src/Directives \
					src/Directives/AllowMethods \
					src/Directives/AutoIndex \
					src/Directives/ErrorPage \
					src/Directives/ErrorPage/ErrorCodeURL \
					src/Directives/Index \
					src/Directives/Listen \
					src/Directives/MaxBodySize \
					src/Directives/PathLocation \
					src/Directives/Return \
					src/Directives/Root \
					src/Directives/ServerName \
					src/Server/Settings/DataServer \
					src/Server/Settings/Location \
					src/Server/Settings/Location/DataLocation \
					src/Server/Socket \
					src/Server/HTTP \
					src/Server/HTTP/StatusLine \
					src/Server/HTTP/Headers \
					src/Server/HTTP/Body \
					src/WebServ \
					src/WebServ/Epoll \
					src/ParserRequest \
					src/ParseRequest/Request \
					src/ParseRequest/Request/Request \
					src/ParseRequest\
					src/ParseRequest/Request/AHeaders \
					src/ParseRequest/Request/ARequestLine \
					src/ParseRequest/Request/ABody \
					src/ParseRequest/Request/ABody/DataBody \
					src/ParseRequest/Request/ABody/Chunked \
					src/ParseRequest/Request/ABody/SimpleBody \
					src/Client

#-----------------------------------------------------------------------------------------
# Header file
INCLUDE				:= -I src/Server \
					-I src/Mime \
					-I src/ErrorDefault \
					-I src/ReasonPhrase \
					-I src/Server/Methods/AMethods \
					-I src/Server/Methods/AMethods/DataRequest \
					-I src/Server/Methods/AMethods/DataDirectives \
					-I src/Server/Methods/AMethods/DataDirectives/FindLocation \
					-I src/Server/Methods/AMethods/CGI \
					-I src/Server/Methods/AMethods/GetFile \
					-I src/Server/Methods/GET \
					-I src/Server/Methods/POST \
					-I src/Server/Methods/DELETE \
					-I src/Server/Socket \
					-I src/Server/Settings \
					-I src/Server/Settings/DataServer \
					-I src/Log \
					-I src/ParseConf \
					-I src/Directives \
					-I src/Directives/AllowMethods \
					-I src/Directives/AutoIndex \
					-I src/Directives/ErrorPage \
					-I src/Directives/ErrorPage/ErrorCodeURL \
					-I src/Directives/Index \
					-I src/Directives/Listen \
					-I src/Directives/MaxBodySize \
					-I src/Directives/PathLocation \
					-I src/Directives/Return \
					-I src/Directives/Root \
					-I src/Directives/ServerName \
					-I src/ParseConf/ParseValidation \
					-I src/ParseConf/ParseTokens \
					-I src/Server/Settings/Location \
					-I src/Server/Settings/Location/DataLocation \
					-I src/utils\
					-I src/Server/HTTP \
					-I src/Server/HTTP/StatusLine \
					-I src/Server/HTTP/Headers \
					-I src/Server/HTTP/Body \
					-I src/WebServ\
					-I src/WebServ/Epoll \
					-I src/ParserRequest \
					-I src/ParseRequest\
					-I src/ParseRequest/Request \
					-I src/ParseRequest/Request/Request \
					-I src/ParseRequest/Request/AHeaders \
					-I src/ParseRequest/Request/ARequestLine \
					-I src/ParseRequest/Request/ABody \
					-I src/ParseRequest/Request/ABody/DataBody \
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

run: all
	./$(NAME) fileConf/conf.conf

re_run: re
	./$(NAME) fileConf/conf.conf

debug: re
	./$(NAME) "DEBUG"

valgrind: re
	valgrind  --leak-check=full ./$(NAME) fileConf/conf.conf

curl:
	curl -X POST -H "Transfer-Encoding: chunked" -H "Content-Type: application/json" --data-binary @index/dados.json 127.0.0.1:8080

telnet:
	@bash -c "telnet 127.0.0.1 8080"
	@sleep 2
	@bash -c "cat index/RequisicaoChunked"

.PHONY: all clean fclean re