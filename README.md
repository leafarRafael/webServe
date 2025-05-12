# webServe

Implementação de um servidor HTTP em C++, desenvolvido como parte do currículo da 42SP.

## 📚 Sobre o Projeto

Este projeto tem como objetivo criar um servidor HTTP capaz de lidar com múltiplas conexões simultâneas, utilizando programação de sockets em C/C++.
O servidor deve ser compatível com o protocolo HTTP/1.1 e suportar funcionalidades como:

- Tratamento de requisições GET, POST e DELETE
- Suporte a CGI para execução de scripts dinâmicos
- Gerenciamento de múltiplas conexões simultâneas
- Configuração flexível através de arquivos de configuração

## 🛠️ Estrutura do Projeto

- **includes/**: Contém os arquivos de cabeçalho (`.hpp`) com as definições de classes e funções utilizadas no projeto.
- **src/**: Contém os arquivos fonte (`.cpp`) com a implementação das funcionalidades principais.
- **Makefile**: Arquivo para automação da compilação do projeto.

## 🚀 Compilação e Execução

Para compilar o projeto, utilize o comando:

```bash
make
```

Após a compilação, execute o servidor com o arquivo de configuração desejado:

```bash
./webserv [arquivo_de_configuração]
```

**Exemplo:**

```bash
./webserv config/default.conf
```

## 🧪 Testes e Visualização

Você pode testar o servidor utilizando ferramentas como:

- [curl](https://curl.se/)
- [Postman](https://www.postman.com/)
- Navegadores web (Chrome, Firefox, etc.)

Certifique-se de que o arquivo de configuração esteja corretamente definido para atender às suas necessidades de teste.

## 📄 Licença

Este projeto está sob a licença MIT. Consulte o arquivo [LICENSE](LICENSE) para mais informações.

## 👤 Autor

- [Rafael](https://github.com/leafarRafael)

---

# webServe

Implementation of an HTTP server in C++, developed as part of the 42SP curriculum.

## 📚 About the Project

This project aims to create an HTTP server capable of handling multiple simultaneous connections, using socket programming in C++.
The server should be compatible with the HTTP/1.1 protocol and support features such as:

- Handling of GET, POST, and DELETE requests
- Support for CGI to execute dynamic scripts
- Management of multiple simultaneous connections
- Flexible configuration through configuration files

## 🛠️ Project Structure

- **includes/**: Contains header files (`.hpp`) with class and function definitions used in the project.
- **src/**: Contains source files (`.cpp`) with the implementation of core functionalities.
- **Makefile**: File used to automate the build process.

## 🚀 Compilation and Execution

To compile the project, run:

```bash
make
```

After compilation, run the server with the desired configuration file:

```bash
./webserv [configuration_file]
```

**Example:**

```bash
./webserv config/default.conf
```

## 🧪 Testing and Visualization

You can test the server using tools like:

- [curl](https://curl.se/)
- [Postman](https://www.postman.com/)
- Web browsers (Chrome, Firefox, etc.)

Ensure that the configuration file is properly set up to meet your testing requirements.

## 📄 License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## 👤 Author

- [Rafael](https://github.com/leafarRafael)
